# MsiSetExternalUIRecord function

## Description

The **MsiSetExternalUIRecord** function enables an external user-interface (UI) handler.

## Parameters

### `puiHandler` [in]

Specifies a callback function that conforms to the [INSTALLUI_HANDLER_RECORD](https://learn.microsoft.com/windows/desktop/api/msi/nc-msi-installui_handler_record) specification.

To disable the current external UI handler, call the function with this parameter set to a **NULL** value.

### `dwMessageFilter` [in]

Specifies which messages to handle using the external message handler. If the external handler returns a non-zero result, then that message is not sent to the UI, instead the message is logged if logging is enabled. For more information, see
[MsiEnableLog](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienableloga).

| Value | Meaning |
| --- | --- |
| **INSTALLLOGMODE_FILESINUSE** | Files in use information.<br><br>When this message is received, a [FilesInUse Dialog](https://learn.microsoft.com/windows/desktop/Msi/filesinuse-dialog) should be displayed. |
| **INSTALLLOGMODE_FATALEXIT** | Premature termination of installation. |
| **INSTALLLOGMODE_ERROR** | The error messages are logged. |
| **INSTALLLOGMODE_WARNING** | The warning messages are logged. |
| **INSTALLLOGMODE_USER** | The user requests are logged. |
| **INSTALLLOGMODE_INFO** | The status messages that are not displayed are logged. |
| **INSTALLLOGMODE_RESOLVESOURCE** | Request to determine a valid source location. |
| **INSTALLLOGMODE_RMFILESINUSE** | Files in use information. When this message is received, a [MsiRMFilesInUse Dialog](https://learn.microsoft.com/windows/desktop/Msi/msirmfilesinuse-dialog) should be displayed. |
| **INSTALLLOGMODE_OUTOFDISKSPACE** | The is insufficient disk space. |
| **INSTALLLOGMODE_ACTIONSTART** | The start of new installation actions are logged. |
| **INSTALLLOGMODE_ACTIONDATA** | The data record with the installation action is logged. |
| **INSTALLLOGMODE_COMMONDATA** | The parameters for user-interface initialization are logged. |
| **INSTALLLOGMODE_PROGRESS** | The [Progress bar](https://learn.microsoft.com/windows/desktop/Msi/p-gly) information.<br><br>This message includes information about units so far and total number of units. This message is only sent to an external user interface and is not logged. For more information, see [MsiProcessMessage](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiprocessmessage). |
| **INSTALLLOGMODE_INITIALIZE** | If this is not a quiet installation, then the [basic UI](https://learn.microsoft.com/windows/desktop/Msi/b-gly) is initialized.<br><br>If this is a full UI installation, the [Full UI](https://learn.microsoft.com/windows/desktop/Msi/f-gly) is not yet initialized.<br><br>This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_TERMINATE** | If a full UI is being used, the full UI has ended.<br><br>If this is not a quiet installation, the basic UI has not ended.<br><br>This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_SHOWDIALOG** | Sent prior to display of the Full UI dialog.<br><br>This message is only sent to an external user interface and is not logged. |
| **INSTALLLOGMODE_INSTALLSTART** | Installation of product begins.<br><br>The message contains the product's ProductName and ProductCode. |
| **INSTALLLOGMODE_INSTALLEND** | Installation of product ends.<br><br>The message contains the product's ProductName, ProductCode, and return value. |

### `pvContext` [in]

A pointer to an application context that is passed to the callback function.

This parameter can be used for error checking.

### `ppuiPrevHandler` [out, optional]

Returns the pointer to the previously set callback function that conforms to the [INSTALLUI_HANDLER_RECORD](https://learn.microsoft.com/windows/desktop/api/msi/nc-msi-installui_handler_record) specification, or **NULL** if no callback is previously set.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function completes successfully. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This value indicates that an attempt is made to call this function from a custom action.<br><br>This function cannot be called from a custom action. |

## Remarks

This function cannot be called from [Custom Actions](https://learn.microsoft.com/windows/desktop/Msi/custom-actions).

The external UI handler enabled by calling **MsiSetExternalUIRecord** receives messages in the format of a [Record Object](https://learn.microsoft.com/windows/desktop/Msi/record-object). The external UI handler enabled by calling [MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia) receives messages in the format of a string. An external UI is always called before the Windows Installer internal UI. An enabled record-based external UI is called before any string-based external UI. If the record-based external UI handler returns 0 (zero), the message is sent to any enabled string-based external UI handler. If the external UI handler returns a non-zero value, the internal Windows Installer UI handler is suppressed and the messages are considered handled.

This function stores the external user interfaces it has set. To replace the current external UI handler with a previous handler, call the function and specify the [INSTALLUI_HANDLER_RECORD](https://learn.microsoft.com/windows/desktop/api/msi/nc-msi-installui_handler_record) as the *puiHandler* parameter and 0 (zero) as the *dwMessageFilter* parameter.

The external user interface handler pointed to by the *puiHandler* parameter does not have full control over the external user interface unless
[MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui) is called with the *dwUILevel* parameter set to INSTALLUILEVEL_NONE. If
**MsiSetInternalUI** is not called, the internal user interface level defaults to INSTALLUILEVEL_BASIC. As a result, any message not handled by the external user interface handler is handled by Windows Installer. The initial "Preparing to install. . ." dialog always appears even if the external user interface handler handles all messages.
[MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia) should only be called from an
[Bootstrapping](https://learn.microsoft.com/windows/desktop/Msi/bootstrapping) application. You cannot call
**MsiSetExternalUI** from a custom action.

To disable this external UI handler, call **MsiSetExternalUIRecord** with a **NULL** value for the *puiHandler* parameter.

**Windows Installer 2.0 and Windows Installer 3.0:** Not supported. The **MsiSetExternalUIRecord** function is available beginning with Windows Installer 3.1.

For more information about using a record-based external handler, see [Monitoring an Installation Using MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/Msi/monitoring-an-installation-using-msisetexternaluirecord).

## See also

[Interface and Logging Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Not Supported in Windows Installer 3.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-3-0)