# IWPCWebSettings::GetSettings

## Description

Retrieves the web restrictions settings.

## Parameters

### `pdwSettings` [out]

The settings. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WPCFLAG_WEB_SETTING_NOTBLOCKED**<br><br>0 | There are no restrictions. |
| **WPCFLAG_WEB_SETTING_DOWNLOADSBLOCKED**<br><br>0x1 | Downloads are blocked. |

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## See also

[IWPCWebSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcwebsettings)