# ITfFnLMProcessor::Reconvert

## Description

Invokes the reconversion process in the language model text service for a range.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to reconvert.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pRange* is invalid. |

## Remarks

This method is identical to [ITfFnReconversion::Reconvert](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-reconvert). When **ITfFnReconversion::Reconvert** is called in the text service, the text service should forward the call to this method if a language model processor is installed. If no language model processor is installed, the text service should perform its default processing.

## See also

[ITfFnLMProcessor](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnlmprocessor)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)