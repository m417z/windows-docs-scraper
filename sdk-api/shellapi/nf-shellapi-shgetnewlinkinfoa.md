# SHGetNewLinkInfoA function

## Description

Creates a name for a new shortcut based on the shortcut's proposed target. This function does not create the shortcut, just the name.

## Parameters

### `pszLinkTo` [in]

Type: **LPCTSTR**

A pointer to the path and file name of the shortcut's target. If *uFlags* does not contain the **SHGNLI_PIDL** value, this parameter is the address of a null-terminated string that contains the target. If *uFlags* contains the **SHGNLI_PIDL** value, this parameter is a PIDL that represents the target.

### `pszDir` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the path of the folder in which the shortcut would be created.

### `pszName` [out]

Type: **LPTSTR**

A pointer to a string that receives the null-terminated path and file name for the shortcut. This buffer is assumed to be at least MAX_PATH characters in size.

### `pfMustCopy` [out]

Type: **BOOL***

The address of a **BOOL** value that receives a flag indicating whether the shortcut would be copied. When a shortcut to another shortcut is created, the Shell simply copies the target shortcut and modifies that copied shortcut appropriately. This parameter receives a nonzero value if the target specified in *pszLinkTo* specifies a shortcut that will cause the target shortcut to be copied. This parameter receives zero if the target does not specify a shortcut that would be copied.

### `uFlags` [in]

Type: **UINT**

The options for the function. This can be zero or a combination of the following values.

#### SHGNLI_PIDL (0x000000001)

0x000000001. The target pointed to by *pszLinkTo* is a PIDL that represents the target. If this flag is not included, *pszLinkTo* is regarded as the address of a string that contains the path and file name of the target.

#### SHGNLI_NOUNIQUE (0x000000002)

0x000000002. Skip the normal checks that ensure that the shortcut name is unique within the destination folder. If this flag is not included, the function creates the shortcut name and then determines whether the name is unique in the destination folder. If a file with the same name already exists in the destination folder, the shortcut name will be modified. This process is repeated until a unique name is found.

#### SHGNLI_PREFIXNAME (0x000000004)

0x000000004. The created name will be preceded by the string "Shortcut to ".

#### SHGNLI_NOLNK (0x000000008)

0x000000008. [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) Do not add the .lnk file name extension. You must set the **_WIN32_IE** macro to 5.01 or greater to use this flag. For more information about versioning, see Shell and Common Controls Versions.

#### SHGNLI_NOLOCNAME (0x000000010)

0x000000010. **Windows Vista and later**. Use the non-localized parsing name of the target pointed to by *pszLinkTo* as the name of the shortcut file. If this flag is not set, the localized name is used.

#### SHGNLI_USEURLEXT (0x000000020)

0x000000020. **Windows 7 and later**. Append a .url file name extension (rather than .lnk) to the name pointed to by *pszName*. If this flag is not set, the shortcut name uses a .lnk extension unless SHGNLI_NOLNK is set.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

**SHGetNewLinkInfo** determines whether the destination file system supports long file names. If it does, a long file name is used for the shortcut name. If the destination file system does not support long file names, the shortcut name is returned in an 8.3 format.

> [!NOTE]
> The shellapi.h header defines SHGetNewLinkInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).