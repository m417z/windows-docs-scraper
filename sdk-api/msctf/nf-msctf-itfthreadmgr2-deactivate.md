# ITfThreadMgr2::Deactivate

## Description

Deactivates TSF for the calling thread.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | This method was called while the thread was activated or this call had no corresponding [Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr2-activate) call. |

## Remarks

Each call to this method must be matched with a previous call to **Activate**. This method must be called from the same thread that the corresponding **Activate** call was made from.

## See also

[ITfThreadMgr2](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr2)