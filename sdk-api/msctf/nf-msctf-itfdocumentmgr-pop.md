# ITfDocumentMgr::Pop

## Description

Removes the context from the top of the context stack.

## Parameters

### `dwFlags` [in]

If this value is 0, only the context at the top of the stack is removed. If this value is TF_POPF_ALL, all of the contexts are removed from the stack.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The stack is empty or this method is called without the TF_POPF_ALL flag and only a single context is on the stack. |
| **E_UNEXPECTED** | This method was called during another **ITfDocumentMgr::Pop** call. |
| **E_INVALIDARG** | *dwFlags* is invalid. |

## Remarks

This method must be called from the same thread as the corresponding [ITfDocumentMgr::Push](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-push) call.

The first context added to the stack becomes the primary context. The primary context cannot be removed from the stack without using the TF_POPF_ALL flag. When the document is uninitialized, this method should be called with the TF_POPF_ALL flag. This causes the document manager to remove all contexts from the context stack and terminate any text service UI. Do not use the TF_POPF_ALL flag at any other time.

This method causes the [ITfThreadMgrEventSink::OnPopContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onpopcontext) method of all installed thread manager event sinks to be called. If the last context is removed from the stack, this method causes the [ITfThreadMgrEventSink::OnUninitDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onuninitdocumentmgr) method of all installed thread manager event sinks to be called.

## See also

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfDocumentMgr::Push](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-push)

[ITfThreadMgrEventSink::OnPopContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onpopcontext)

[ITfThreadMgrEventSink::OnUninitDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onuninitdocumentmgr)