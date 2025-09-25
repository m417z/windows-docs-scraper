# IFileOperation::PerformOperations

## Description

Executes all selected operations.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Note that if the operation was canceled by the user, this method can still return a success code. Use the [GetAnyOperationsAborted](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-getanyoperationsaborted) method to determine if this was the case.

## Remarks

This method is called last to execute those actions that have been specified earlier by calling their individual methods. For instance, [RenameItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-renameitem) does not rename the item, it simply sets the parameters. The actual renaming is done when you call **PerformOperations**.

## See also

[FinishOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-finishoperations)

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[StartOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-startoperations)