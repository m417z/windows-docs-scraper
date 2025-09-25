# IShellLibrary::GetDefaultSaveFolder

## Description

Retrieves the default target folder that the library uses for save operations.

## Parameters

### `dsft` [in]

Type: **[DEFAULTSAVEFOLDERTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype)**

The [DEFAULTSAVEFOLDERTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype) value that specifies the save folder to get.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to get in *ppv* that will represent the save location. This value is typically IID_IShellItem, but it can also be IID_IShellItem2 or the IID of any other interface that is implemented by CShellItem.

### `ppv` [out]

Type: **void****

A pointer to the interface requested in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For best results, use the **IID_PPV_ARGS** macro, defined in Objbase.h, for the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

## See also

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)

[IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2)

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))