# MsiSetExternalUIW function

## Description

The
**MsiSetExternalUI** function enables an external user-interface handler. This external UI handler is called before the normal internal user-interface handler. The external UI handler has the option to suppress the internal UI by returning a non-zero value to indicate that it has handled the messages. For more information, see
[About the User Interface](https://learn.microsoft.com/windows/desktop/Msi/about-the-user-interface).

## Parameters

### `puiHandler` [in]

Specifies a callback function that conforms to the
[INSTALLUI_HANDLER](https://learn.microsoft.com/windows/desktop/api/msi/nc-msi-installui_handlera) specification.

### `dwMessageFilter` [in]

Specifies which messages to handle using the external message handler. If the external handler returns a non-zero result, then that message will not be sent to the UI, instead the message will be logged if logging has been enabled. For more information, see
the [MsiEnableLog](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienableloga) function.

| Value | Meaning |
| --- | --- |
| **INSTALLLOGMODE_FILESINUSE** | Files in use information. When this message is received, a [FilesInUse Dialog](https://learn.microsoft.com/windows/desktop/Msi/filesinuse-dialog) should be displayed. |
| **INSTALLLOGMODE_FATALEXIT** | Premature termination of installation. |
| **INSTALLLOGMODE_ERROR** | The error messages are logged. |
| **INSTALLLOGMODE_WARNING** | The warning messages are logged. |
| **INSTALLLOGMODE_USER** | The user requests are logged. |
| **INSTALLLOGMODE_INFO** | The status messages that are not displayed are logged. |
| **INSTALLLOGMODE_RESOLVESOURCE** | Request to determine a valid source location. |
| **INSTALLLOGMODE_RMFILESINUSE** | Files in use information. When this message is received, a [MsiRMFilesInUse Dialog](https://learn.microsoft.com/windows/desktop/Msi/msirmfilesinuse-dialog) should be displayed. |
| **INSTALLLOGMODE_OUTOFDISKSPACE** | There was insufficient disk space. |
| **INSTALLLOGMODE_ACTIONSTART** | The start of new installation actions are logged. |
| **INSTALLLOGMODE_ACTIONDATA** | The data record with the installation action is logged. |
| **INSTALLLOGMODE_COMMONDATA** | The parameters for user-interface initialization are logged. |
| **INSTALLLOGMODE_PROGRESS** | [Progress bar](https://learn.microsoft.com/windows/desktop/Msi/p-gly) information. This message includes information on units so far and total number of units. For an explanation of the message format, see the [MsiProcessMessage](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiprocessmessage) function. This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_INITIALIZE** | If this is not a quiet installation, then the [basic UI](https://learn.microsoft.com/windows/desktop/Msi/b-gly) has been initialized. If this is a [full UI](https://learn.microsoft.com/windows/desktop/Msi/f-gly) installation, the *full UI* is not yet initialized. This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_TERMINATE** | If a [full UI](https://learn.microsoft.com/windows/desktop/Msi/f-gly) is being used, the *full UI* has ended. If this is not a quiet installation, the [basic UI](https://learn.microsoft.com/windows/desktop/Msi/b-gly) has not yet ended. This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_SHOWDIALOG** | Sent prior to display of the [full UI](https://learn.microsoft.com/windows/desktop/Msi/f-gly) dialog. This message is only sent to an external user interface and is not logged. |
| ****INSTALLLOGMODE_INSTALLSTART**** | Installation of product begins. <br><br>The message contains the product's ProductName and ProductCode. |
| ****INSTALLLOGMODE_INSTALLEND**** | Installation of product ends. <br><br>The message contains the product's ProductName, ProductCode, and return value. |

### `pvContext` [in]

Pointer to an application context that is passed to the callback function. This parameter can be used for error checking.

## Return value

The return value is the previously set external handler, or zero (0) if there was no previously set handler.

## Remarks

To restore the previous UI handler, second call is made to
**MsiSetExternalUI** using the
[INSTALLUI_HANDLER](https://learn.microsoft.com/windows/desktop/api/msi/nc-msi-installui_handlera) returned by the first call to
**MsiSetExternalUI** and specifying zero (0) for dwMessageFilter.

The external user interface handler pointed to by the *puiHandler* parameter does not have full control over the external user interface unless
[MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui) is called with the *dwUILevel* parameter set to INSTALLUILEVEL_NONE. If
**MsiSetInternalUI** is not called, the internal user interface level defaults to INSTALLUILEVEL_BASIC. As a result, any message not handled by the external user interface handler is handled by Windows Installer. The initial "Preparing to install. . ." dialog always appears even if the external user interface handler handles all messages.

**MsiSetExternalUI** should only be called from a
[Bootstrapping](https://learn.microsoft.com/windows/desktop/Msi/bootstrapping) application. You cannot call
**MsiSetExternalUI** from a custom action.

> [!NOTE]
> The msi.h header defines MsiSetExternalUI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Interface and Logging Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)