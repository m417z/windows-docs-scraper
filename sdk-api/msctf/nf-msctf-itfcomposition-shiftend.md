# ITfComposition::ShiftEnd

## Description

Moves the end anchor of a composition.

## Parameters

### `ecWrite` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pNewEnd` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that contains the new end anchor position. The end anchor of the context will be moved to the end anchor of this range. This method fails if the end anchor of this range is positioned prior to the start anchor of the composition.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The end anchor of *pNewEnd* is positioned prior to the start anchor of the composition or *pNewStart* is invalid. |
| **E_UNEXPECTED** | The composition has already terminated. |
| **TF_E_NOLOCK** | The edit context identified by *ecWrite* does not have a read/write lock. |

## Remarks

This method causes the GUID_PROP_COMPOSING property to be removed from any text removed from the composition. Likewise, the GUID_PROP_COMPOSING property is also added to any text added to the composition.

## See also

[ITfComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcomposition), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange), [ITfComposition::ShiftStart](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcomposition-shiftstart)