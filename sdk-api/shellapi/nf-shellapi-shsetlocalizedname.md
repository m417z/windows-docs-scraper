# SHSetLocalizedName function

## Description

Sets the localized name of a file in a Shell folder.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a string that specifies the fully qualified path of the target file.

### `pszResModule` [in]

Type: **PCWSTR**

A pointer to a string resource that specifies the localized version of the file name.

### `idsRes`

Type: **int**

An integer ID that specifies the localized file name in the string resource.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When this string is set, Explorer displays this string instead of the file name. The path to the file is unchanged.

Applications can get the display (localized) name with [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) with the [SIGDN_NORMALDISPLAY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn) flag and the parsing (non-localized) name with [IShellItem::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getdisplayname) using the [SIGDN_DESKTOPABSOLUTEPARSING](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-sigdn) flag.

Calling [SHRemoveLocalizedName](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shremovelocalizedname) makes the display name identical to the parsing name.