# ITfCleanupContextSink::OnCleanupContext

## Description

Called during a context cleanup operation.

## Parameters

### `ecWrite` [in]

Contains a [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie) value that identifies the edit context cleaned up. The edit context is guaranteed to have a read/write lock.

### `pic` [in]

Pointer to an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface that represents the context cleaned up.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A context cleanup occurs when:

- The text service is deactivated while a context is still on the context stack. This can occur when the active text service is changed or when the active language changes while the text service is active.
- [ITfThreadMgr::Deactivate](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfthreadmgr-deactivate) is called while a context is still on the context stack.

[ITfCleanupContextDurationSink::OnStartCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextdurationsink-onstartcleanupcontext) is called just before the TSF manager begins making [ITfCleanupContextSink::OnCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextsink-oncleanupcontext) notifications. When all of the OnCleanupContext notifications complete, the TSF manager calls **OnEndCleanupContext**.

## See also

[ITfCleanupContextSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcleanupcontextsink), [ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [TfEditCookie](https://learn.microsoft.com/windows/win32/tsf/tfeditcookie)