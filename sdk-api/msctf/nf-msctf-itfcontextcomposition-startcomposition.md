# ITfContextComposition::StartComposition

## Description

Creates a new composition.

## Parameters

### `ecWrite` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pCompositionRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that specifies the text that the composition initially covers.

### `pSink` [in]

Pointer to an [ITfCompositionSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompositionsink) object that receives composition event notifications. This parameter is optional and can be **NULL**. If supplied, the object is released when the composition is terminated.

### `ppComposition` [out]

Pointer to an [ITfComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcomposition) interface pointer that receives the new composition object. This parameter receives **NULL** if the context owner rejects the composition.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. If the context owner composition advise sink rejects the composition, *ppComposition* is set to **NULL**. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | The composition object cannot be created. |
| **E_UNEXPECTED** | The method was called within another composition operation. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |
| **TF_E_NOLOCK** | The edit context identified by *ecWrite* does not have a read/write lock. |

## Remarks

If the context owner has installed a context owner composition advise sink, the [ITfContextOwnerCompositionSink::OnStartComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextownercompositionsink-onstartcomposition) method is called. If the advise sink rejects the new composition, this method returns S_OK but *ppComposition* is set to **NULL**.

Any text covered by *pCompositionRange* receives the GUID_PROP_COMPOSING property.

## See also

[IEnumITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumitfcompositionview), [ITfContextComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextcomposition), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange), [ITfCompositionSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionsink), [ITfContextOwnerCompositionSink::OnStartComposition](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontextownercompositionsink-onstartcomposition), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession)