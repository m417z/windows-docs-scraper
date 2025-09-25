# ITfRange::ShiftEnd

## Description

Moves the end anchor of the range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `cchReq` [in]

Contains the number of characters that the end anchor is shifted. A negative value causes the anchor to move backward and a positive value causes the anchor to move forward.

### `pcch` [out]

Pointer to a **LONG** value that receives the number of characters the anchor shifted.

### `pHalt` [in]

Pointer to a [TF_HALTCOND](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_haltcond) structure that contains conditions on the shift. This parameter is optional and can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only lock. |

## Remarks

The start and end positions of a range are called anchors.

This method cannot move an anchor beyond a region boundary. If the shift reaches a region boundary, the number of characters actually shifted will be less than requested. [ITfRange::ShiftEndRegion](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftendregion) is used to shift the anchor to an adjacent region.

If the shift operation causes the range end anchor to move past the start anchor, the start anchor is moved to the same location as the end anchor.

ITfRange::ShiftEnd can be a lengthy operation. For better performance, use [ITfRange::ShiftEndToRange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstarttorange) when possible.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::ShiftEndRegion](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftendregion)

[ITfRange::ShiftStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstart)

[TF_HALTCOND](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_haltcond)