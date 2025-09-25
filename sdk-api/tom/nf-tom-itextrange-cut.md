# ITextRange::Cut

## Description

Cuts the plain or rich text to a data object or to the Clipboard, depending on the
*pVar* parameter.

## Parameters

### `pVar`

Type: **VARIANT***

The cut text.
*pVar*->ppunkVal is the out parameter for an
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object, provided that the following conditions exist:

* pVar->vt = (VT_UNKNOWN | VT_BYREF)
* pVar is not null
* pVar->ppunkVal is not null

Otherwise, the clipboard is used.

## Return value

Type: **HRESULT**

This method returns an
**HRESULT** value. If successful, it returns **S_OK**. Otherwise it returns one of the following values. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **E_OUTOFMEMORY** | Out of memory. |

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)