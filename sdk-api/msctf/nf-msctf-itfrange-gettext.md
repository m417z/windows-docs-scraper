# ITfRange::GetText

## Description

The **ITfRange::GetText** method obtains the content covered by this range of text.

## Parameters

### `ec` [in]

Edit cookie that identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dwFlags` [in]

Bit fields that specify optional behavior.

| Value | Meaning |
| --- | --- |
| **TF_TF_MOVESTART** | Start anchor of the range is advanced to the position after the last character returned. |
| **TF_TF_IGNOREEND** | Method attempts to fill *pchText* with the maximum number of characters, instead of halting the copy at the position occupied by the end anchor of the range. |

### `pchText` [out]

Pointer to a buffer to receive the text in the range.

### `cchMax` [in]

Maximum size of the text buffer.

### `pcch` [out]

Pointer to a ULONG representing the number of characters written to the *pchText* text buffer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_NOLOCK** | The value of the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[TF_TF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-tf--constants)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)