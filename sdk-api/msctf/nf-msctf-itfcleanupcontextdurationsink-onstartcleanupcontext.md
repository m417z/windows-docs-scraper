# ITfCleanupContextDurationSink::OnStartCleanupContext

## Description

Called when a context cleanup operation is about to begin.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A context cleanup occurs when:

- The text service is deactivated while a context is still on the context stack. This can occur when the active text service is changed or when the active language changes while the text service is active.
- [ITfThreadMgr::Deactivate](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfthreadmgr-deactivate) is called while a context is still on the context stack.

[ITfCleanupContextDurationSink::OnStartCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextdurationsink-onstartcleanupcontext) is called just before the TSF manager begins making [ITfCleanupContextSink::OnCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextsink-oncleanupcontext) notifications. When all of the OnCleanupContext notifications complete, the TSF manager calls **OnEndCleanupContext**.

## See also

[ITfCleanupContextDurationSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcleanupcontextdurationsink), [ITfCleanupContextDurationSink::OnEndCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextdurationsink-onendcleanupcontext), [ITfCleanupContextSink::OnCleanupContext](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcleanupcontextsink-oncleanupcontext)