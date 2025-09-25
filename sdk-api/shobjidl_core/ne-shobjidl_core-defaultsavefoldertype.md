# DEFAULTSAVEFOLDERTYPE enumeration

## Description

Specifies the default save location.

## Constants

### `DSFT_DETECT:1`

The current user determines the save folder. If the current user is the library's owner, use the private save location ([DSFT_PRIVATE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype)). If the current user is not the library's owner, use the public save location ([DSFT_PUBLIC](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-defaultsavefoldertype)).

### `DSFT_PRIVATE`

The library's private save location, which can only be accessed by the library's owner.

### `DSFT_PUBLIC`

The library's public save location, which can be accessed by all users.

## Remarks

These values cannot be combined.

### Used By

* [IShellLibrary::GetDefaultSaveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-getdefaultsavefolder)
* [IShellLibrary::SetDefaultSaveFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-setdefaultsavefolder)

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)