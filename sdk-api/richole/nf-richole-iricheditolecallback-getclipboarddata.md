# IRichEditOleCallback::GetClipboardData

## Description

Allows the client to supply its own clipboard object.

## Parameters

### `lpchrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)***

The clipboard object range.

### `reco`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The clipboard operation flag can be one of these values.

| Value | Meaning |
| --- | --- |
| **RECO_COPY** | Copy to the clipboard. |
| **RECO_CUT** | Cut to the clipboard. |

### `lplpdataobj`

Type: **LPDATAOBJECT***

Pointer to the pointer variable that receives the address of the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) implementation representing the range specified in the
*lpchrg* parameter. The value of
*lplpdataobj* is ignored if an error is returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the return value is **E_NOTIMPL**, the rich edit control created its own clipboard object. If the return value is a failure other than **E_NOTIMPL**, the operation failed.

## See also

[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)

**Reference**