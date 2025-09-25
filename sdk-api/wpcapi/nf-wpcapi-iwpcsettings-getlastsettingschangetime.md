# IWPCSettings::GetLastSettingsChangeTime

## Description

Retrieves the time at which the configuration settings were last updated.

## Parameters

### `pTime` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the time at which the settings were last updated.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FILE_NOT_FOUND** | The user settings were not found. |
| **E_FAIL** | The method failed. |

## See also

[IWPCSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcsettings)