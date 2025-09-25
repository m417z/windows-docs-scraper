# IWPCSettings::GetRestrictions

## Description

Determines whether web restrictions, time limits, or game restrictions are on.

## Parameters

### `pdwRestrictions` [out]

Indicates the current restrictions. This parameter can be one of more of the following values.

| Value | Meaning |
| --- | --- |
| **WPCFLAG_NO_RESTRICTION**<br><br>0 | There are no restrictions. |
| **WPCFLAG_LOGGING_REQUIRED**<br><br>0x1 | Activity logged is on. |
| **WPCFLAG_WEB_FILTERED**<br><br>0x2 | A Web Content Filter is active. |
| **WPCFLAG_HOURS_RESTRICTED**<br><br>0x4 | Hours are restricted. |
| **WPCFLAG_GAMES_BLOCKED**<br><br>0x8 | Games are blocked. |
| **WPCFLAG_APPS_RESTRICTED**<br><br>0x10 | Applications are restricted. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_ACCESS_DENIED** | The calling process has insufficient privileges. |
| **E_FILE_NOT_FOUND** | The user settings were not found. |
| **E_FAIL** | The method failed. |

## See also

[IWPCSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcsettings)