# SHARDAPPIDINFO structure

## Description

Contains data used by [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) to identify both an item—in this case as an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)—and the process that it is associated with.

## Members

### `psi`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the object in the Shell namespace.

### `pszAppID`

Type: **PCWSTR**

The application-defined AppUserModelID associated with the item.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[SHARDAPPIDINFOIDLIST](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfoidlist)

[SHARDAPPIDINFOLINK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfolink)

[SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs)