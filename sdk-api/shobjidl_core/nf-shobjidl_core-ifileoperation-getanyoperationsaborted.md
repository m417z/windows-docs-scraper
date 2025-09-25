# IFileOperation::GetAnyOperationsAborted

## Description

Gets a value that states whether any file operations initiated by a call to [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) were stopped before they were complete. The operations could be stopped either by user action or silently by the system.

## Parameters

### `pfAnyOperationsAborted` [out]

Type: **BOOL***

When this method returns, points to **TRUE** if any file operations were aborted before they were complete; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) returns.

You should call **IFileOperation::GetAnyOperationsAborted** regardless of whether [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) returned a success or failure code. A success code can be returned even if the operation was stopped by the user or the system.

This method provides the same functionality as the **fAnyOperationsAborted** member of the [SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa) structure used by the legacy function [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa).