# ITfRange::IsEqualEnd

## Description

The [ITfRange::IsEqualStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-isequalstart) method verifies that the end anchor of this range of text matches an anchor of another specified range.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pWith` [in]

Pointer to a specified range in which an anchor is to be compared to this range end anchor.

### `aPos` [in]

Enumeration element that indicates which anchor of the specified *pWith* range to compare with this range end anchor.

| Value | Meaning |
| --- | --- |
| **TF_ANCHOR_START** | Compares this range end anchor with the specified range start anchor. |
| **TF_ANCHOR_END** | Compares this range end anchor with the specified range end anchor. |

### `pfEqual` [out]

Pointer to a Boolean value. Upon return, **TRUE** indicates that the specified *pWith* range anchor matches this range end anchor. **FALSE** indicates otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_NOLOCK** | The value of the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |

## Remarks

This method is identical to **ITfRange::IsEqualStart**, except that the end anchor of this range is compared to an anchor of another specified range.

This method is functionally equivalent to, but more efficient than, [ITfRange::CompareEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-compareend).

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::CompareEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-compareend)

[ITfRange:IsEqualStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-isequalstart)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)