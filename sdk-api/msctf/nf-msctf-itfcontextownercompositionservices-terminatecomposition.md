# ITfContextOwnerCompositionServices::TerminateComposition

## Description

Terminates a composition.

## Parameters

### `pComposition` [in]

Pointer to a [ITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompositionview) interface that represents the composition to terminate. If this value is **NULL**, all compositions in the context are terminated.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **TF_E_NOLOCK** | A text service currently holds a lock on the document. |
| **E_UNEXPECTED** | This method was called during another composition operation. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

A text service uses [ITfComposition::EndComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcomposition-endcomposition) to terminate a composition that it created.

If the context owner implements the text store, the context owner must be able to grant a synchronous write lock before calling this method.

This method also does the following:

* For each composition terminated, [ITfCompositionSink::OnCompositionTerminated](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompositionsink-oncompositionterminated) is called for all installed composition advise sinks.
* If the context owner installed a context owner composition advise sink, [ITfContextOwnerCompositionSink::OnEndComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextownercompositionsink-onendcomposition) is called for each terminated composition.
* The GUID_PROP_COMPOSING property will be cleared for the text covered by each terminated composition.

## See also

[ITfComposition::EndComposition](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcomposition-endcomposition), [nf-msctf-itfcompositionsink-oncompositionterminated](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompositionsink-oncompositionterminated), [ITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionview), [ITfContextOwnerCompositionServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextownercompositionservices), [ITfContextOwnerCompositionSink::OnEndComposition](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontextownercompositionsink-onendcomposition)