# IWindowsParentalControlsCore::GetVisibility

## Description

Indicates the visibility of the Parental Controls user interface.

## Parameters

### `peVisibility` [out]

Indicates whether the user interface is hidden. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WPCFLAG_WPC_VISIBLE**<br><br>0 | The user interface is visible. |
| **WPCFLAG_WPC_HIDDEN**<br><br>0x1 | The user interface is hidden. |

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