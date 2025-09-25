# IFileOperationProgressSink::StartOperations

## Description

Performs caller-implemented actions before any specific file operations are performed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**StartOperations** is the first of the [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) methods to be called after [PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations). It can be used to perform any setup or initialization that you require before the file operations begin.