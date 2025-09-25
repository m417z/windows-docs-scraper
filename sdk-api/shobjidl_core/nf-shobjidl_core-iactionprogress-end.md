# IActionProgress::End

## Description

Indicates that the action associated with this progress implementation has ended.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

This method indicates that the action has finished, and the implementing class should perform cleanup and display results to the user, if applicable.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[IActionProgress::Begin](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-begin)