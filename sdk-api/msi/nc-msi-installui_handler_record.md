# INSTALLUI_HANDLER_RECORD callback function

## Description

The **INSTALLUI_HANDLER_RECORD** function
prototype defines a callback function that the installer calls for progress notification and error messages. Call
the **MsiSetExternalUIRecord** function to enable a record-base external
user-interface (UI) handler.

**Windows Installer 3.0 and Windows Installer 2.0:** Not supported. Available beginning with Windows Installer version 3.1 and later.

## Parameters

### `pvContext`

Pointer to an application context passed to the
[MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluirecord) function. This parameter
can be used for error checking.

### `iMessageType`

Specifies a combination of one message box style, one message box icon type, one default button, and one
installation message type. This parameter must be one of the following.

| Message box StylesFlag | Meaning |
| --- | --- |
| **MB_ABORTRETRYIGNORE** | The message box contains the **Abort**, **Retry**, and **Ignore** buttons. |
| **MB_OK** | The message box contains the **OK** button. This is the default. |
| **MB_OKCANCEL** | The message box contains the **OK** and **Cancel** buttons. |
| **MB_RETRYCANCEL** | The message box contains the **Retry** and **Cancel** buttons. |
| **MB_YESNO** | The message box contains the **Yes** and **No** buttons. |
| **MB_YESNOCANCEL** | The message box contains the **Yes**, **No**, and **Cancel** buttons. |

| Message box IconTypesFlag | Meaning |
| --- | --- |
| **MB_ICONEXCLAMATION, MB_ICONWARNING** | An exclamation point appears in the message box. |
| **MB_ICONINFORMATION, MB_ICONASTERISK** | The information sign appears in the message box. |
| **MB_ICONQUESTION** | A question mark appears in the message box. |
| **MB_ICONSTOP, MB_ICONERROR, MB_ICONHAND** | A stop sign appears in the message box. |

| Default ButtonsFlag | Meaning |
| --- | --- |
| **MB_DEFBUTTON1** | The first button is the default button. |
| **MB_DEFBUTTON2** | The second button is the default button. |
| **MB_DEFBUTTON3** | The third button is the default button. |

| Install message TypesFlag | Meaning |
| --- | --- |
| **INSTALLMESSAGE_FATALEXIT** | Premature termination |
| **INSTALLMESSAGE_ERROR** | Formatted error message |
| **INSTALLMESSAGE_WARNING** | Formatted warning message |
| **INSTALLMESSAGE_USER** | User request message. |
| **INSTALLMESSAGE_INFO** | Informative message for log |
| **INSTALLMESSAGE_FILESINUSE** | List of files currently in use that must be closed before being replaced |
| **INSTALLMESSAGE_RESOLVESOURCE** | Request to determine a valid source location |
| **INSTALLMESSAGE_RMFILESINUSE** | List of files currently in use that must be closed before being replaced. Available beginning with Windows Installer version 4.0. For more information about this message see [Using Restart Manager with an External UI](https://learn.microsoft.com/windows/desktop/Msi/using-restart-manager-with-an-external-ui-). |
| **INSTALLMESSAGE_OUTOFDISKSPACE** | Insufficient disk space message |
| **INSTALLMESSAGE_ACTIONSTART** | Start of action message. This message includes the action name and description. |
| **INSTALLMESSAGE_ACTIONDATA** | Formatted data associated with the individual action item. |
| **INSTALLMESSAGE_PROGRESS** | Progress gauge information. This message includes information on units so far and total number of units. |
| **INSTALLMESSAGE_COMMONDATA** | Formatted dialog information for user interface. |
| **INSTALLMESSAGE_INITIALIZE** | Sent prior to UI initialization, no string data |
| **INSTALLMESSAGE_TERMINATE** | Sent after UI termination, no string data |
| **INSTALLMESSAGE_SHOWDIALOG** | Sent prior to display of authored dialog or wizard |
| **INSTALLMESSAGE_INSTALLSTART** | Sent prior to installation of product. |
| **INSTALLMESSAGE_INSTALLEND** | Sent after installation of product. |

The following defaults should be used if any of the preceding messages are missing: MB_OK, no icon, and
MB_DEFBUTTON1. There is no default installation message type; a message type is always specified.

### `hRecord`

Specifies a handle to the record object. For information about record objects, see the [Record Processing Functions](https://learn.microsoft.com/windows/win32/msi/database-functions#record-processing-functions).

## Return value

The following return values map to the buttons specified by the message box style:

IDOKIDCANCELIDABORTIDRETRYIDIGNOREIDYESIDNO

## Remarks

This type of external UI handler should be used when it is known what type of errors or messages the caller is
interested in, and wants to avoid the overhead of parsing the string message that is sent to an external UI
handler of INSTALLUI_HANDLER type, but retrieve the data of interest from fields of hRecord.

For more information on returning values from an external user interface handler, see the
[Returning Values from an
External User Interface Handler](https://learn.microsoft.com/windows/desktop/Msi/returning-values-from-an-external-user-interface-handler) topic. The hRecord object sent to the record-based external UI handler is
owned by Windows Installer and is valid only for the callback's lifetime. The callback should extract from the
record any data it needs and it should not close that handle.

Any attempt by a record-based external UI handler to alter the data in the hRecord object will be ignored by
Windows Installer.

For more information about using a record-based external handler, see [Monitoring an Installation Using MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/Msi/monitoring-an-installation-using-msisetexternaluirecord).

## See also

[MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia)

[Not Supported in Windows Installer 3.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-3-0)