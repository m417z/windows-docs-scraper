# ITfRange::Collapse

## Description

The **ITfRange::Collapse** method clears the range of text by moving its start anchor and end anchor to the same position.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `aPos` [in]

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor) enumeration that describes how to collapse the range.

| Value | Meaning |
| --- | --- |
| **TF_ANCHOR_START** | The end anchor is moved to the location of the start anchor. |
| **TF_ANCHOR_END** | The start anchor is moved to the location of the end anchor. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The object does not support the interface, or a new range cannot be created. |
| **E_INVALIDARG** | *aPos* is invalid. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid, or the caller does not have a read-only lock. |

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)