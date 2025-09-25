# ITfRange::ShiftEndToRange

## Description

Moves the end anchor of this range to an anchor within another range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the anchor that the end anchor is moved to.

### `aPos` [in]

Contains one of the [TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor) values that specify which anchor of *pRange* the end anchor will get moved to.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pRange* is invalid. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only lock. |

## Remarks

The start and end positions of a range are called anchors.

If the shift operation causes the range end anchor to move past the start anchor, the start anchor is moved to the same location as the end anchor.

This method is more efficient than [ITfRange::ShiftEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftend) and should be used.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::ShiftEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftend)

[ITfRange::ShiftStartToRange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstarttorange)