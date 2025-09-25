# IShellIcon::GetIconOf

## Description

Gets an icon for an object inside a specific folder.

## Parameters

### `pidl`

Type: **LPCITEMIDLIST**

The address of the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that specifies the relative location of the folder.

### `flags`

Type: **UINT**

Flags specifying how the icon is to display. This parameter can be zero or one of the following values.

#### GIL_FORSHELL

The icon is to be displayed in a Shell folder.

#### GIL_OPENICON

The icon should be in the open state if both open-state and closed-state images are available. If this flag is not specified, the icon should be in the closed state. This flag is typically used for folder objects.

### `pIconIndex`

Type: **LPINT**

The address of the index of the icon in the system image list. The following standard image list indexes can be returned.

#### 0

Document (blank page, not associated)

#### 1

Document (with data on the page)

#### 2

Application (file name extension must be .exe, .com, or .bat)

#### 3

Folder (plain)

#### 4

Folder (open)

## Return value

Type: **HRESULT**

Returns S_OK if *lpIconIndex* contains the correct system image list index, or S_FALSE if an icon can't be obtained for this object.

## Remarks

If you are unable to retrieve an icon for this object using **GetIconOf**, use the [GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof) method to retrieve an object that supports the [Extract](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-extract) method.

**IShellIcon::GetIconOf** fails if [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) is not called first.

### Note to Calling Applications

The index returned is from the system image list.

### Note to Implementers

If the icon index used is not one of the standard images listed, it is the implementer's responsibility to add the image to the system image list and then place the index into the *lpIconIndex* parameter. To prevent the system image list from growing too large, each image should only be added once.

## See also

[IShellIcon](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellicon)