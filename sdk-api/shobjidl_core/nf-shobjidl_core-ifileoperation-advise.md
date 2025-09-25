# IFileOperation::Advise

## Description

Enables a handler to provide status and error information for all operations.

## Parameters

### `pfops` [in]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

Pointer to an [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) object to be used for progress status and error notifications.

### `pdwCookie` [out]

Type: **DWORD***

When this method returns, this parameter points to a returned token that uniquely identifies this connection. The calling application uses this token later to delete the connection by passing it to [IFileOperation::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-unadvise). If the call to **Advise** fails, this value is meaningless.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Several individual methods have the ability to declare their own progress sinks, which are redundant to the one set here. They are used when you only want to be given progress and error information for a specific operation.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-unadvise)