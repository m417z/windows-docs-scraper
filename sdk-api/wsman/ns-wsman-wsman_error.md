# WSMAN_ERROR structure

## Description

Contains error information that is returned by a Windows Remote Management (WinRM) client. The [WSMAN_ERROR](https://learn.microsoft.com/windows/desktop/WinRM/wsman-error) structure is used by all callbacks to return error information and is valid only for the callback.

## Members

### `code`

Specifies an error code. This error can be a general error code that is defined in winerror.h or a WinRM-specific error code.

### `errorDetail`

Specifies extended error information that relates to a failed call. This field contains the fault detail text if it is present in the fault. If there is no fault detail, this field contains the fault reason text. This field can be set to **NULL**.

### `language`

Specifies the language for the error description. This field can be set to **NULL**. For more information about the language format, see the RFC 3066 specification from the Internet Engineering Task Force at [http://www.ietf.org/rfc/rfc3066.txt](https://www.ietf.org/rfc/rfc3066.txt).

### `machineName`

Specifies the name of the computer. This field can be set to **NULL**.

### `pluginName`

Specifies the name of the plug-in that generated the error. This field can be set to **NULL**.