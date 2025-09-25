# IShellFolder::SetNameOf

## Description

Sets the display name of a file object or subfolder, changing the item identifier in the process.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the owner window of any dialog or message box that the client displays.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that uniquely identifies the file object or subfolder relative to the parent folder. The structure must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero.

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated string that specifies the new display name.

### `uFlags` [in]

Type: **[SHGDNF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf)**

Flags that indicate the type of name specified by the *pszName* parameter. For a list of possible values and combinations of values, see [SHGDNF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf).

### `ppidlOut` [out]

Type: **PITEMID_CHILD***

Optional. If specified, the address of a pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that receives the **ITEMIDLIST** of the renamed item. The caller requests this value by passing a non-null *ppidlOut*. Implementations of **IShellFolder::SetNameOf** must return a pointer to the new **ITEMIDLIST** in the *ppidlOut* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Changing the display name of a file system object, or a folder within it, renames the file or directory.

Before calling this method, applications should call [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) and check that the SFGAO_CANRENAME flag is set. Note that this flag is essentially a hint to namespace clients. It does not necessarily imply that **IShellFolder::SetNameOf** will succeed or fail.

Implementers of **IShellFolder::SetNameOf** must call [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) with both the old and new absolute PIDLs once the renaming of an object is complete. This following example shows the call to **SHChangeNotify** following the renaming of a folder object.

```
SHChangeNotify(SHCNE_RENAMEFOLDER, SHCNF_IDLIST, pidlFullOld, pidlFullNew);
```

This call prevents both the old and new names being displayed in the view.