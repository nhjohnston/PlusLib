/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusCapistranoCommand_h
#define __vtkPlusCapistranoCommand_h

#include "vtkPlusServerExport.h"

#include "vtkPlusCommand.h"
#include "vtkIGSIOTransformRepository.h"

class vtkMatrix4x4;

/*!
  \class vtkPlusCapistranoCommand
  \brief This command is for communicating with vtkPlusCapistranoDevice.
  \ingroup PlusLibPlusServer
  This command is used for communicating with a Capistrano device.
 */
class vtkPlusServerExport vtkPlusCapistranoCommand : public vtkPlusCommand
{
public:

  static vtkPlusCapistranoCommand* New();
  vtkTypeMacro(vtkPlusCapistranoCommand, vtkPlusCommand);
  virtual void PrintSelf(ostream& os, vtkIndent indent);
  virtual vtkPlusCommand* Clone() { return New(); }

  /*! Executes the command  */
  virtual PlusStatus Execute();

  /*! Read command parameters from XML */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* aConfig);

  /*! Write command parameters to XML */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* aConfig);

  /*! Get all the command names that this class can execute */
  virtual void GetCommandNames(std::list<std::string>& cmdNames);

  /*! Gets the description for the specified command name. */
  virtual std::string GetDescription(const std::string& commandName);

  /*! Id of the device that the text will be sent to */
  virtual std::string GetDeviceId() const;
  virtual void SetDeviceId(const std::string& deviceId);

  /*!
    If true then the command waits for a response and returns with the received text in the command response.
  */
  vtkSetMacro(ResponseExpected, bool);
  vtkGetMacro(ResponseExpected, bool);
  vtkBooleanMacro(ResponseExpected, bool);

protected:
  vtkPlusCapistranoCommand();
  virtual ~vtkPlusCapistranoCommand();

  std::string GetCommandName() const;
  void SetCommandName(const std::string& text);
  std::string GetCommandValue() const;
  void SetCommandValue(const std::string& text);

  std::list<std::pair<std::string, std::string>> RequestedParameterChanges;

private:
  std::string DeviceId;
  std::string CommandName;
  std::string CommandValue;
  bool ResponseExpected;

  vtkPlusCapistranoCommand(const vtkPlusCapistranoCommand&);
  void operator=(const vtkPlusCapistranoCommand&);
};


#endif
