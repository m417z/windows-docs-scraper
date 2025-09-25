# ITfRange::CompareStart

## Description

The **ITfRange::CompareStart** method compares the start anchor position of this range of text to an anchor in another range.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pWith` [in]

Pointer to a specified range in which an anchor is to be compared to this range start anchor.

### `aPos` [in]

Enumeration element that indicates which anchor of the specified *pWith* range to compare to this range start anchor.

| Value | Meaning |
| --- | --- |
| **TF_ANCHOR_START** | Compare this range start anchor with the specified range start anchor. |
| **TF_ANCHOR_END** | Compare this range start anchor with the specified range end anchor. |

### `plResult` [out]

Pointer to the result of the comparison between this range start anchor and the specified *pWith* range anchor.

| Value | Meaning |
| --- | --- |
| **-1** | This start anchor is behind the anchor of the specified range (position of this start anchor < position of the anchor of the specified range). |
| **0** | This start anchor is at the same position as the anchor of the specified range. |
| **+1** | This start anchor is ahead of the anchor of the specified range (position of this start anchor > position of the anchor of the specified range). |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_NOLOCK** | The value of the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |

## Remarks

This method will never return 0 unless the two anchors are in a single region. If the caller only requires information about whether the two anchors are positioned at the same location, [ITfRange::IsEqualStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-isequalstart) is more efficient.

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::CompareEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-compareend)

[ITfRange::IsEqualStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-isequalstart)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)