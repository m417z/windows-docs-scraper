# RtwqEndUnregisterWorkQueueWithMMCSS function

Completes an asynchronous request to unregister a work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

*pResult*

Pointer to the [**IMFAsyncResult**](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [**IRtwqAsyncCallback::Invoke**](https://learn.microsoft.com/windows/win32/api/rtworkq/nf-rtworkq-irtwqasynccallback-invoke) method.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | None |
| Library<br> | Rtworkq.lib |
| DLL<br> | RTWorkQ.dll |

