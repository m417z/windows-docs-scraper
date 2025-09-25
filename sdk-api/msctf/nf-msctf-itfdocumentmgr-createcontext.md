# ITfDocumentMgr::CreateContext

## Description

Creates a context object.

## Parameters

### `tidOwner` [in]

The client identifier. For an application, this value is provided by a previous call to [ITfThreadMgr::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-activate). For a text service, this value is provided in the text service [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate) method.

### `dwFlags` [in]

Reserved, must be zero.

### `punk` [in]

Pointer to an object that supports the [ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp) or [ITfContextOwnerCompositionSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextownercompositionsink) interfaces. This value can be **NULL**.

### `ppic` [out]

Address of an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) pointer that receives the context.

### `pecTextStore` [out]

Pointer to a [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie) value that receives an edit cookie for the new context. This value identifies the context in various methods.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

All references to the *punk* parameter are released when the context is destroyed or when the context is removed from the stack with the [ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop) method.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContextOwnerCompositionSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextownercompositionsink)

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfDocumentMgr::Pop](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-pop)

[ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate)

[ITfThreadMgr::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-activate)

[TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie)