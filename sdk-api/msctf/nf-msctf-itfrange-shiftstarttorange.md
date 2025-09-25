# ITfRange::ShiftStartToRange

## Description

Moves the start anchor of this range to an anchor within another range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the anchor that the start anchor is moved to.

### `aPos` [in]

Contains one of the [TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor) values that specifies which anchor of *pRange* the start anchor is moved to.

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

If the shift operation causes the range start anchor to move past the end anchor, the end anchor is moved to the same location as the start anchor.

This method is more efficient than [ITfRange::ShiftStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstart) and should be used when possible.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::ShiftEndToRange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftendtorange)

ITfRange::ShiftStart

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)