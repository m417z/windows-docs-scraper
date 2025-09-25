# IActionProgress::ResetCancel

## Description

Resets progress dialog after a cancellation has been completed.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

This method is called when a cancellation has been completed. User input should typically be limited for cancellations of actions that involve large calculations or file operations. This method may be used by calling applications to notify a progress UI that the cancellation has been completed and the UI should return control to the user.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[IActionProgress::QueryCancel](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-querycancel)