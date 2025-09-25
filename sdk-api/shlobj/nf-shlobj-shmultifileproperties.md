# SHMultiFileProperties function

## Description

Displays a merged property sheet for a set of files. Property values common to all the files are shown while those that differ display the string **(multiple values)**.

## Parameters

### `pdtobj` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to a data object that supplies the PIDLs of all of the files for which to display the merged property sheet. The data object must use the [CFSTR_SHELLIDLIST](https://learn.microsoft.com/windows/desktop/shell/clipboard) clipboard format. The parent folder's implementation of [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) must return a fully qualified file system path for each item in response to the [SHGDN_FORPARSING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) flag.

### `dwFlags`

Type: **DWORD**

Reserved. Must be set to 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Shell Clipboard Formats](https://learn.microsoft.com/windows/desktop/shell/clipboard)