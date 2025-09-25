# IShellLibrary::SetDefaultSaveFolder

## Description

Sets the default target folder that the library will use for save operations.

## Parameters

### `dsft` [in]

Type: **[DEFAULTSAVEFOLDERTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype)**

The [DEFAULTSAVEFOLDERTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype) value that specifies the default save location to set.

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

An [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the folder that to use as the default save location. The folder that this object represents must be a folder that is already in the library.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default save location must be valid, have read/write access, and with either the [SFGAO_STREAM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) or [SFGAO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) attribute set.

If *psi* is not in the library, this method returns an error.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))