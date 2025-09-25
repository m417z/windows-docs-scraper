# ITfTextLayoutSink::OnLayoutChange

## Description

Receives a notification when the layout of a context view changes.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface for the context that changed.

### `lcode` [in]

Specifies the [TfLayoutCode](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tflayoutcode) element that describes the layout change.

### `pView` [in]

Pointer to the [ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview) interface for the context view in that the layout change occurred.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each context has a default view for which a reference can be obtained using the [ITfContext::GetActiveView](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getactiveview) method. The method returns only the value TF_LC_CHANGE for the *lcode* parameter for this view, because the values are possible only for multiple views. Because TSF does not support multiple views, this method never receives other values of the **TfLayoutCode** enumeration.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContext::GetActiveView](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getactiveview)

[ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview)

[ITfTextLayoutSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftextlayoutsink)

[TfLayoutCode](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tflayoutcode)