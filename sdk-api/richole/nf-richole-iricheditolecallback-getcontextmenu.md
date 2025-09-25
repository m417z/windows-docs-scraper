# IRichEditOleCallback::GetContextMenu

## Description

Queries the application for a context menu to use on a right-click event.

## Parameters

### `seltype`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Selection type. The value, which specifies the contents of the new selection, can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SEL_EMPTY** | The selection is empty. |
| **SEL_TEXT** | Text. |
| **SEL_OBJECT** | At least one COM object. |
| **SEL_MULTICHAR** | More than one character of text. |
| **SEL_MULTIOBJECT** | More than one COM object. |
| **GCM_RIGHTMOUSEDROP** | Indicates that a context menu for a right-mouse drag drop should be generated. The *lpoleobj* parameter is a pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface for the object being dropped. |

### `lpoleobj`

Type: **LPOLEOBJECT**

Pointer to an interface. If the
*seltype* parameter includes the **SEL_OBJECT** flag,
*lpoleobj* is a pointer to the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface for the first selected COM object. If
*seltype* includes the **GCM_RIGHTMOUSEDROP** flag,
*lpoleobj* is a pointer to an
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface. Otherwise,
*lpoleobj* is **NULL**. If you hold on to the interface pointer, you must call
the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method to increment the object's reference count.

### `lpchrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)***

Pointer to a [CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange) structure containing the current selection.

### `lphmenu`

Type: **[HMENU](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The handle of a context menu to use. This parameter is ignored if an error is returned. A rich edit control destroys the menu when it is finished with it so the client should not.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can be the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |

## Remarks

When the user selects an item from the context window, a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message is sent to the parent window of the rich edit control.

## See also

[CHARRANGE](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-charrange)

[GETCONTEXTMENUEX](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-getcontextmenuex)

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)

**Reference**