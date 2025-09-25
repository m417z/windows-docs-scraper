# IFolderViewHost::Initialize

## Description

Initializes the object that hosts an [IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview) object.

## Parameters

### `hwndParent` [in]

Type: **HWND**

The handle of the window that contains the [IFolderViewHost](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ifolderviewhost) object.

### `pdo` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

The address of a pointer to a data object.

### `prc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The address of a pointer to a **RECT** structure that specifies the dimensions of the folder view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.