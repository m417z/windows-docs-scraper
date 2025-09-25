# IMFAsyncCallback::GetParameters

## Description

Provides configuration information to the dispatching thread for a callback.

## Parameters

### `pdwFlags` [out]

Receives a flag indicating the behavior of the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The following values are defined. The default value is zero.

| Value | Meaning |
| --- | --- |
| **Zero** | The callback does not take a long time to complete, but has no specific restrictions on what system calls it makes. The callback generally takes less than 30 milliseconds to complete. |
| ****MFASYNC_FAST_IO_PROCESSING_CALLBACK**** | The callback does very minimal processing. It takes less than 1 millisecond to complete.<br><br>The callback must be invoked from one of the following work queues:<br><br>* **MFASYNC_CALLBACK_QUEUE_IO**<br>* **MFASYNC_CALLBACK_QUEUE_TIMER** |
| ****MFASYNC_SIGNAL_CALLBACK**** | Implies **MFASYNC_FAST_IO_PROCESSING_CALLBACK**, with the additional restriction that the callback does no processing (less than 50 microseconds), and the only system call it makes is **SetEvent**.<br><br>The callback must be invoked from one of the following work queues:<br><br>* **MFASYNC_CALLBACK_QUEUE_IO**<br>* **MFASYNC_CALLBACK_QUEUE_TIMER** |
| ****MFASYNC_BLOCKING_CALLBACK**** | Blocking callback. |
| ****MFASYNC_REPLY_CALLBACK**** | Reply callback. |

### `pdwQueue` [out]

Receives the identifier of the work queue on which the callback is dispatched.

This value can specify one of the standard Media Foundation work queues, or a work queue created by the application. For list of standard Media Foundation work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers). To create a new work queue, call [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue). The default value is **MFASYNC_CALLBACK_QUEUE_STANDARD**.

If the work queue is not compatible with the value returned in *pdwFlags*, the Media Foundation platform returns **MF_E_INVALID_WORKQUEUE** when it tries to dispatch the callback. (See [MFPutWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem).)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****E_NOTIMPL**** | Not implemented. Assume the default behavior. |

## Remarks

The **GetParameters** method returns information about the callback so that the dispatching thread can optimize the process that it uses to invoke the callback.

If the method returns a value other than zero in the *pdwFlags* parameter, your [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method must meet the requirements described here. Otherwise, the callback might delay the pipeline.

If you want default values for both parameters, return **E_NOTIMPL**. The default values are given in the parameter descriptions on this page.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)