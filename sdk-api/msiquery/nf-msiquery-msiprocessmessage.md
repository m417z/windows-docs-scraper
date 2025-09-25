# MsiProcessMessage function

## Description

The
**MsiProcessMessage** function sends an error record to the installer for processing.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `eMessageType` [in]

The *eMessage* parameter must be a value specifying one of the following message types. To display a message box with push buttons or icons, use OR-operators to add INSTALLMESSAGE_ERROR, INSTALLMESSAGE_WARNING, or INSTALLMESSAGE_USER to the standard message box styles used by
the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) and
[MessageBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxexa) functions. For more information, see the Remarks below.

| Value | Meaning |
| --- | --- |
| **INSTALLMESSAGE_FATALEXIT** | Premature termination, possibly fatal out of memory. |
| **INSTALLMESSAGE_ERROR** | Formatted error message,[1] is message number in [Error table](https://learn.microsoft.com/windows/desktop/Msi/error-table). |
| **INSTALLMESSAGE_WARNING** | Formatted warning message,[1] is message number in Error table. |
| **INSTALLMESSAGE_USER** | User request message,[1] is message number in Error table. |
| **INSTALLMESSAGE_INFO** | Informative message for log,not to be displayed. |
| **INSTALLMESSAGE_FILESINUSE** | List of files currently in use that must be closed before being replaced. |
| **INSTALLMESSAGE_RESOLVESOURCE** | Request to determine a valid source location. |
| **INSTALLMESSAGE_RMFILESINUSE** | List of files currently in use that must be closed before being replaced. Available beginning with Windows Installer version 4.0. For more information about this message see [Using Restart Manager with an External UI](https://learn.microsoft.com/windows/desktop/Msi/using-restart-manager-with-an-external-ui-). |
| **INSTALLMESSAGE_OUTOFDISKSPACE** | Insufficient disk space message. |
| **INSTALLMESSAGE_ACTIONSTART** | Progress: start of action,[1] action name,[2] description,[3] template for ACTIONDATA messages. |
| **INSTALLMESSAGE_ACTIONDATA** | Action data. Record fields correspond to the template of ACTIONSTART message. |
| **INSTALLMESSAGE_PROGRESS** | Progress bar information. See the description of record fields below. |
| **INSTALLMESSAGE_COMMONDATA** | To enable the Cancel button set [1] to 2 and [2] to 1. <br><br>To disable the Cancel button set [1] to 2 and [2] to 0 |

### `hRecord` [in]

Handle to a record containing message format and data.

## Return value

This function returns int.

## Remarks

The
**MsiProcessMessage** function performs any enabled logging operations and defers execution. You can selectively enable logging for various message types.

For INSTALLMESSAGE_FATALEXIT, INSTALLMESSAGE_ERROR, INSTALLMESSAGE_WARNING, and INSTALLMESSAGE_USER messages, if field 0 is not set field 1 must be set to the error code corresponding to the error message in the
[Error table](https://learn.microsoft.com/windows/desktop/Msi/error-table). Then, the message is formatted using the template from the Error table before passing it to the user-interface handler for display.

### Record Fields for Progress Bar Messages

The following describes the record fields when eMessageType is set to INSTALLMESSAGE_PROGRESS. Field 1 specifies the type of the progress message. The meaning of the other fields depend upon the value in this field. The possible values that can be set into Field 1 are as follows.

| Field 1 value | Field 1 description |
| --- | --- |
| 0 | Resets progress bar and sets the expected total number of ticks in the bar. |
| 1 | Provides information related to progress messages to be sent by the current action. |
| 2 | Increments the progress bar. |
| 3 | Enables an action (such as CustomAction) to add ticks to the expected total number of progress of the progress bar. |

The meaning of Field 2 depends upon the value in Field 1 as follows.

| Field 1 value | Field 2 description |
| --- | --- |
| 0 | Expected total number of ticks in the progress bar. |
| 1 | Number of ticks the progress bar moves for each ActionData message that is sent by the current action. This field is ignored if Field 3 is 0. |
| 2 | Number of ticks the progress bar has moved. |
| 3 | Number of ticks to add to total expected progress. |

The meaning of Field 3 depends upon the value in Field 1 as follows.

| Field 1 value | Field 3 value | Field 3 description |
| --- | --- | --- |
| 0 | 0 | Forward progress bar (left to right) |
|  | 1 | Backward progress bar (right to left) |
| 1 | 0 | The current action will send explicit ProgressReport messages. |
|  | 1 | Increment the progress bar by the number of ticks specified in Field 2 each time an ActionData message is sent by the current action. |
| 2 | Unused |  |
| 3 | Unused |  |

The meaning of Field 4 depends upon the value in Field 1 as follows.

| Field 1 value | Field 4 value | Field 4 description |
| --- | --- | --- |
| 0 | 0 | Execution is in progress. In this case, the UI could calculate and display the time remaining. |
|  | 1 | Creating the execution script. In this case, the UI could display a message to please wait while the installer finishes preparing the installation. |
| 1 | Unused |  |
| 2 | Unused |  |
| 3 | Unused |  |

For more information and a code sample, see
[Adding Custom Actions to the ProgressBar](https://learn.microsoft.com/windows/desktop/Msi/adding-custom-actions-to-the-progressbar).

### Display of Message Boxes

To display a message box with push buttons or icons, use OR-operators to add INSTALLMESSAGE_ERROR, INSTALLMESSAGE_WARNING, or INSTALLMESSAGE_USER with the message box options used by [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) and [MessageBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxexa). The available push button options are MB_OK, MB_OKCANCEL, MB_ABORTRETRYIGNORE, MB_YESNOCANCEL, MB_YESNO, and MB_RETRYCANCEL. The available default button options are MB_DEFBUTTON1, MB_DEFBUTTON2, and MB_DEFBUTTON3. The available icon options are MB_ICONERROR, MB_ICONQUESTION, MB_ICONWARNING, and MB_ICONINFORMATION. If no icon options is specified, Windows Installer chooses a default icon style based upon the message type.

For example, the following call to
**MsiProcessMessage** sends an INSTALLMESSAGE_ERROR message with the MB_ICONWARNING icon and the MB_ABORTRETRYCANCEL buttons.

```cpp
PMSIHANDLE hInstall;
PMSIHANDLE hRec;
MsiProcessMessage(hInstall,
                  INSTALLMESSAGE(INSTALLMESSAGE_ERROR|MB_ABORTRETRYIGNORE|MB_ICONWARNING),
                  hRec);

```

If a custom action calls **MsiProcessMessage**, the custom action should be capable of handling a cancellation by the user and should return ERROR_INSTALL_USEREXIT.

For more information on sending messages with
**MsiProcessMessage**, see the
[Sending Messages to Windows Installer Using MsiProcessMessage](https://learn.microsoft.com/windows/desktop/Msi/sending-messages-to-windows-installer-using-msiprocessmessage).

## See also

[Installer Action Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Sending Messages to Windows Installer Using MsiProcessMessage](https://learn.microsoft.com/windows/desktop/Msi/sending-messages-to-windows-installer-using-msiprocessmessage)