# ITfContextComposition::FindComposition

## Description

Creates an enumerator object that contains all compositions that intersect a specified range of text.

## Parameters

### `ecRead` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pTestRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that specifies the range to search. This parameter can be **NULL**. If this parameter is **NULL**, the enumerator will contain all compositions in the edit context.

### `ppEnum` [out]

Pointer to an [IEnumITfCompositionView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumitfcompositionview) interface pointer that receives the enumerator object.

## Return value

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The enumerator object cannot be initialized. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | The enumerator object cannot be created. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |

The edit context identified by *ecRead* does not have a read-only lock.

## See also

[IEnumITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumitfcompositionview), [ITfContextComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextcomposition), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession),