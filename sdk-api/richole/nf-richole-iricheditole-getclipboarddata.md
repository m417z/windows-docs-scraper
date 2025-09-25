# IRichEditOle::GetClipboardData

## Description

Retrieves a clipboard object for a range in an edit control.

## Parameters

### `lpchrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)***

The range for which to create the clipboard object.

### `reco`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Unused.

### `lplpdataobj`

Type: **LPDATAOBJECT***

The [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface of the clipboard object representing the range specified in the
*lpchrg* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can return one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |
| **E_OUTOFMEMORY** | There was not enough memory to do the operation. |

## See also

[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)

**Reference**