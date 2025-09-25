# ITfContext::GetSelection

## Description

Obtains the selection within the document.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit session. This is the value passed to [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `ulIndex` [in]

Specifies the zero-based index of the first selection to obtain. Use TF_DEFAULT_SELECTION to obtain the default selection. If TF_DEFAULT_SELECTION is used, only one selection is obtained.

### `ulCount` [in]

Specifies the maximum number of selections to obtain.

### `pSelection` [out]

An array of [TF_SELECTION](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selection) structures that receives the data for each selection. The array must be able to hold at least *ulCount* elements.

### `pcFetched` [out]

Pointer to a ULONG value that receives the number of selections obtained.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOSELECTION** | The document has no selection. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

A selection is a highlighted range of text, or an insertion point if the range is empty, that identifies the user focus area within a document.

If this method is successful, the caller must release the **range** member of all **TF_SELECTION** structures obtained.

Normally, a context only supports a single selection. It is possible, however, for a context to support multiple, simultaneous selections. This method can be used to obtain multiple selections.

## Examples

```cpp

HRESULT         hr;
TF_SELECTION    tfSel;
ULONG           uFetched;

//Obtain the default selection.
hr = pContext->GetSelection(ec, TF_DEFAULT_SELECTION, 1, &tfSel, &uFetched);
if(SUCCEEDED(hr) && (uFetched > 0))
{
    //Work with the selection.

    //Release the selection range object.
    tfSel.range->Release();
}

```

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession), [TF_SELECTION structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_selection), [ITfContext::SetSelection](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-setselection)