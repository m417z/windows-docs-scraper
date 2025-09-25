# ITfRange::SetText

## Description

The **ITfRange::SetText** method replaces the content covered by the range of text. For an empty range object, the method results in an insertion at the location of the range. If the new content is an empty string (*cch* = 0), the method deletes the existing content within the range.

## Parameters

### `ec` [in]

Identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dwFlags` [in]

Specifies optional behavior for correction of content. If set to the value of [TF_ST_CORRECTION](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants), then the operation is a correction of the existing content, not a creation of new content, and original text properties are preserved.

### `pchText` [in]

Pointer to a buffer that contains the text to replace the range contents.

### `cch` [in]

Contains the number of characters in *pchText*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_COMPOSITION_REJECTED** | The context owner rejected a default composition. |
| **TF_E_NOLOCK** | The value of the *ec* parameter is an invalid cookie, or the caller does not have a read/write lock. |
| **TF_E_RANGE_NOT_COVERED** | The range is not within the active composition of the caller. |

## Remarks

When a range covers multiple regions, call **ITfRange::SetText** on each region separately. Otherwise, the method can fail.

By default, text services start and end a temporary composition that covers the range, to ensure that context owners consistently recognize compositions over edited text. If the composition owner rejects a default composition, then the method returns TF_E_COMPOSITION_REJECTED. Default compositions are only created if the caller has not already started one. If the caller has an active composition, the call fails.

The [TF_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants) object placeholder character might not be passed into this method. [ITfRange::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-insertembedded) should be used instead.

For inserting text, the [ITFInsertAtSelection:InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection) method does not require a selection range to be allocated, and avoids the requirement that the range match the selection.

## See also

[ITFInsertAtSelection:InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::GetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-gettext)

[ITfRange::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-insertembedded)

[Miscellaneous Framework Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)