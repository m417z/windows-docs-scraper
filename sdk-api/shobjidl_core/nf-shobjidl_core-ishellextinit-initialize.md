# IShellExtInit::Initialize

## Description

Initializes a property sheet extension, shortcut menu extension, or drag-and-drop handler.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that uniquely identifies a folder. For property sheet extensions, this parameter is **NULL**. For shortcut menu extensions, it is the item identifier list for the folder that contains the item whose shortcut menu is being displayed. For nondefault drag-and-drop menu extensions, this parameter specifies the target folder.

### `pdtobj` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface object that can be used to retrieve the objects being acted upon.

### `hkeyProgID` [in]

Type: **HKEY**

The registry key for the file object or folder type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The meanings of some parameters depend on the extension type. For drag-and-drop handlers, the *pidlFolder* parameter specifies the destination folder (the drop target), the *pdtobj* parameter identifies the items being dropped, and the *hkeyProgID* parameter specifies the file type of the destination folder.

For [shortcut menu extensions](https://learn.microsoft.com/windows/desktop/shell/context-menu-handlers), *pdtobj* identifies the selected file objects, *hkeyProgID* identifies the [file type](https://learn.microsoft.com/windows/desktop/shell/fa-file-types) of the object with focus, and *pidlFolder* is either **NULL** (for file objects) or specifies the folder for which the shortcut menu is being requested (for folder background shortcut menus).

For property sheet extensions, *pidlFolder* is **NULL**, *pdtobj* identifies the selected file objects, and *hkeyProgID* specifies the file type of the file object that has the focus.

### Notes to Implementers

This is the first method that the Shell calls after it creates an instance of a property sheet extension, shortcut menu extension, or drag-and-drop handler.