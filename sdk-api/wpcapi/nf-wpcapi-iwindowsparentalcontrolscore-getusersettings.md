# IWindowsParentalControlsCore::GetUserSettings

## Description

Retrieves a pointer to an interface for general settings for the specified user.

## Parameters

### `pcszSID` [in]

The SID string of the user. If this parameter is **NULL**, retrieve settings for the current user.

### `ppSettings` [out]

A pointer to an [IWPCSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcsettings) interface pointer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | A pointer argument is **NULL**. |
| **E_FILE_NOT_FOUND** | The user settings were not found. |
| **E_OUT_OF_MEMORY** | There is insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWindowsParentalControls](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwindowsparentalcontrols)

[IWindowsParentalControlsCore](https://learn.microsoft.com/windows/win32/api/wpcapi/nn-wpcapi-iwindowsparentalcontrolscore)