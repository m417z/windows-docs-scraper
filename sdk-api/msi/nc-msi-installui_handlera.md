# INSTALLUI_HANDLERA callback function

## Description

The
**INSTALLUI_HANDLER** function prototype defines a callback function that the installer calls for progress notification and error messages. For more information on the usage of this function prototype, a sample code snippet is available in
[Handling Progress Messages Using MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/Msi/handling-progress-messages-using-msisetexternalui).

## Parameters

### `pvContext`

Pointer to an application context passed to the
[MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia) function. This parameter can be used for error checking.

### `iMessageType`

Specifies a combination of one message box style, one message box icon type, one default button, and one installation message type. This parameter must be one of the following.

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
| **INSTALLMESSAGE_FILESINUSE** | List of files currently in use that must be closed before being replaced. |
| **INSTALLMESSAGE_RESOLVESOURCE** | Request to determine a valid source location |
| **INSTALLMESSAGE_RMFILESINUSE** | List of files currently in use that must be closed before being replaced. Available beginning with Windows Installer 4.0. For more information about this message see [Using Restart Manager with an External UI](https://learn.microsoft.com/windows/desktop/Msi/using-restart-manager-with-an-external-ui-). |
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

The following defaults should be used if any of the preceding messages are missing: MB_OK, no icon, and MB_DEFBUTTON1. There is no default installation message type; a message type is always specified.

### `szMessage`

Specifies the message text.

## Return value

The following return values map to the buttons specified by the message box style:

IDOKIDCANCELIDABORTIDRETRYIDIGNOREIDYESIDNO

## Remarks

For more information on returning values from an external user interface handler, see the
[Returning Values from an External User Interface Handler](https://learn.microsoft.com/windows/desktop/Msi/returning-values-from-an-external-user-interface-handler) topic.

> [!NOTE]
> The msi.h header defines INSTALLUI_HANDLER as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia)