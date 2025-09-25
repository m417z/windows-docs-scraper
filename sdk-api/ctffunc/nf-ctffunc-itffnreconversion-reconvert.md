# ITfFnReconversion::Reconvert

## Description

Invokes the reconversion process for a range of text.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to be reconverted. To obtain this range object call [ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

If this method causes some type of user interface to be displayed, such as a dialog box, this method must not wait for the UI to be dismissed before returning.

## See also

[ITfFnReconversion](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnreconversion)

[ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)