# IWindowsParentalControlsCore::GetWebFilterInfo

## Description

Retrieves the name and identifier of the currently active Web Content Filter.

## Parameters

### `pguidID` [out]

The GUID of the currently active Web Content Filter.

### `ppszName` [in, out]

The name of the currently active Web Content Filter.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | A pointer argument is **NULL**. |
| **E_OUT_OF_MEMORY** | There is insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWindowsParentalControls](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwindowsparentalcontrols)

[IWindowsParentalControlsCore](https://learn.microsoft.com/windows/win32/api/wpcapi/nn-wpcapi-iwindowsparentalcontrolscore)