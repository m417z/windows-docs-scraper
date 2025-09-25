# SHRemoveLocalizedName function

## Description

Removes the localized name of a file in a Shell folder.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string that specifies the fully qualified path of the target file.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a display name string is set by [SHSetLocalizedName](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shsetlocalizedname), Windows Explorer uses that string for display instead of the file name. The path to the file is unchanged.

Applications can use the [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) method to get the display (localized) name through with the SIGDN_NORMALDISPLAY flag and the parsing (non-localized) name with SIGDN_DESKTOPABSOLUTEPARSING.

Calling **SHRemoveLocalizedName** makes the display name identical to the parsing name.