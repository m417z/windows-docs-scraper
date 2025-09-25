# IFileOperationProgressSink::FinishOperations

## Description

Performs caller-implemented actions after the last operation performed by the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) is complete.

## Parameters

### `hrResult` [in]

Type: **HRESULT**

The return value of the final operation. Note that this is not the HRESULT returned by one of the [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) methods, which simply queue the operations. Instead, this is the result of the actual operation, such as copy, delete, or move.

## Return value

Type: **HRESULT**

Not used.