# SHARDAPPIDINFOIDLIST structure

## Description

Contains data used by [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) to identify both an item—in this case by an absolute pointer to an item identifier list (PIDL)—and the process that it is associated with.

## Members

### `pidl`

Type: **PCIDLIST_ABSOLUTE**

An absolute PIDL that gives the full path of the item in the Shell namespace.

### `pszAppID`

Type: **PCWSTR**

The application-defined AppUserModelID associated with the item.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[SHARDAPPIDINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfo)

[SHARDAPPIDINFOLINK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfolink)

[SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs)