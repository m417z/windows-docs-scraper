# ITfContextOwnerCompositionSink::OnUpdateComposition

## Description

Called when an existing composition is changed.

## Parameters

### `pComposition` [in]

Pointer to an [ITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompositionview) object that represents the composition updated.

### `pRangeNew` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that contains the range of text the composition will cover after the composition is updated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To determine what has changed within the composition, compare *pRangeNew* with the range returned from [ITfCompositionView::GetRange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompositionview-getrange). The range returned by **ITfCompositionView::GetRange** is not updated until after **ITfContextOwnerCompositionSink::OnUpdateComposition** returns.

## See also

[ITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionview), [ITfContextOwnerCompositionSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextownercompositionsink), [ITfCompositionView::GetRange](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompositionview-getrange), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange)