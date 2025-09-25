# ITfRange::ShiftEndRegion

## Description

Moves the end anchor into an adjacent region.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dir` [in]

Contains one of the [TfShiftDir](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfshiftdir) values that specify which adjacent region the end anchor is moved to.

### `pfNoRegion` [out]

Pointer to a **BOOL** value that receives a flag that indicates if the anchor is positioned adjacent to another region. Receives a nonzero value if the anchor is not adjacent to another region or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfNoRegion* is invalid. |
| **TF_E_NOLOCK** | The edit context identified by *ec* does not have a read-only lock. |

## Remarks

The start and end positions of a range are known as anchors.

The anchor must be positioned adjacent to the desired region prior to calling this method. If it is not, then *pfNoRegion* receives a nonzero value and the anchor is not moved. If the anchor is adjacent to the desired region, *pfNoRegion* receives zero and the anchor is moved into the region.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::ShiftEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftend)

[ITfRange::ShiftStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstart)

[ITfRange::ShiftStartRegion](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstartregion)

[TfShiftDir](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfshiftdir)