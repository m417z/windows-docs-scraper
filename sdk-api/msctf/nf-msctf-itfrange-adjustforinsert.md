# ITfRange::AdjustForInsert

## Description

The **ITfRange::AdjustForInsert** method expands or contracts a range of text to adjust for text insertion.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `cchInsert` [in]

Character count of the inserted text. This count is used in a futurecall to [ITfRange::SetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-settext). If the character count is unknown, 0 can be used.

### `pfInsertOk` [out]

Pointer to a flag that indicates whether the context owner will accept (**TRUE**) or reject (**FALSE**) the insertion.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The application was unable to replace the selection. |
| **TF_E_NOLOCK** | The value in the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |

## Remarks

This method should be used to prepare a range to initiate a new composition, before editing begins. It should be used only when the text is not inserted at the current selection. [ITFInsertAtSelection:InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection) or [ITfInsertAtSelection::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-insertembeddedatselection) are the correct methods to use when text is inserted at the current selection.

The context owner can use this method to preserve behavior and help maintain a consistent user experience. For example, certain characters or objects in the context can be preserved from modifications, or overtyping can be supported.

This method is not necessary when modifying an existing composition. It is acceptable to call **ITfRange::SetText** directly to modify text previously entered by the caller.

On exit, if **pfInsertOk* is set to **FALSE**, a future call to **ITfRange::SetText** or [ITfRange::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-insertembedded) with this range is likely to fail. Otherwise, **pfInsertOk* will be set to **TRUE**, and the range start anchor or end anchor can be repositioned at the discretion of the context owner.

## See also

[ITFInsertAtSelection:InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfInsertAtSelection::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-insertembeddedatselection)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-insertembedded)

[ITfRange::SetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-settext)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)