# ITfThreadMgr::Activate

## Description

Activates TSF for the calling thread.

## Parameters

### `ptid` [out]

Pointer to a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that receives a client identifier.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ptid* is invalid. |
| **E_UNEXPECTED** | This method was called while the thread was deactivating. |

## Remarks

This method can be called more than once from a thread, but each call must be matched with a corresponding call to [ITfThreadMgr::Deactivate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-deactivate) from the same thread.

## See also

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[ITfThreadMgr::Deactivate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-deactivate)

[TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid)