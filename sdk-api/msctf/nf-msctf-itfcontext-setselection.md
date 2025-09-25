# ITfContext::SetSelection

## Description

Sets the selection within the document.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit session. This is the value passed to [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `ulCount` [in]

Specifies the number of selections in the *pSelection* array.

### `pSelection` [in]

An array of [TF_SELECTION](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selection) structures that contain the information for each selection.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOSELECTION** | The document has no selection. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid. |

## Remarks

A selection is a span of highlighted text, or an insertion point if the span is empty, identifying the user focus area within a document. Some documents are capable of having multiple selections. There can only be one zero-length selection in *pSelection* as it represents the position of the document caret.

If an application must adjust the text covered by a selection, it should wait until the caller releases the lock. However, applications can adjust any of the **style** members of the **TF_SELECTION** structures while still returning S_OK.

The caller can set the **fInterimChar** flag only if one selection is set. In this case, the selection should span exactly one character and the **ase** member of the **TF_SELECTION** structure is set to TFAE_NONE.

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession), [TF_SELECTION structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_selection), [ITfContext::GetSelection](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-getselection)