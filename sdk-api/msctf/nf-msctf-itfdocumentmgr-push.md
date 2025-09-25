# ITfDocumentMgr::Push

## Description

Adds a context to the top of the context stack.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) object to be added to the stack. This object is obtained from a previous call to [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pic* is invalid. |
| **TF_E_STACKFULL** | No space exists on the stack for the context. The context stack has a limit of two contexts. |
| **E_UNEXPECTED** | This method was called during an [ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop) call. |

## Remarks

The first context added to the stack becomes the main document context.

The TSF manager and text services only interact with the context at the top of the stack. Normally, only the main document context is on the stack. Occasionally, it is necessary to add a second context to the stack. For example, when a text service must display a modal UI, such as a candidate list. During this time, the text service will add its context to the stack. When the text service UI is no longer required, the text service removes the context from the stack. The main context then returns to the top of the stack. To simplify this process and prevent multiple modal UIs from being displayed, there is a maximum of two contexts allowed on the stack.

This method causes the [ITfThreadMgrEventSink::OnPushContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onpushcontext) method of all installed thread manager event sinks to be called. If this is the first context to be added to the stack, this method causes the [ITfThreadMgrEventSink::OnInitDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-oninitdocumentmgr) method of all installed thread manager event sinks to be called.

[ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop) must be called to remove this context from the context stack.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop)

[ITfThreadMgrEventSink::OnInitDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-oninitdocumentmgr)

[ITfThreadMgrEventSink::OnPushContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgreventsink-onpushcontext)