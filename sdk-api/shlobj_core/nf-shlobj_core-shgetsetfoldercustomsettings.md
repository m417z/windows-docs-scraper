# SHGetSetFolderCustomSettings function

## Description

[**SHGetSetFolderCustomSettings** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Sets or retrieves custom folder settings. This function reads from and writes to Desktop.ini.

## Parameters

### `pfcs` [in, out]

Type: **LPSHFOLDERCUSTOMSETTINGS**

A pointer to a [SHFOLDERCUSTOMSETTINGS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shfoldercustomsettings) structure that provides or receives the custom folder settings.

### `pszPath` [in]

Type: **PCTSTR**

A pointer to a null-terminated Unicode string that contains the path to the folder. The length of **pszPath** must be MAX_PATH or less, including the terminating null character.

### `dwReadWrite`

Type: **DWORD**

A flag that controls the action of the function. It may be one of the following values.

#### FCS_READ (0x00000001)

Retrieve the custom folder settings in *pfcs*.

#### FCS_FORCEWRITE (0x00000002)

Use *pfcs* to set the custom folder's settings regardless of whether the values are already present.

#### FCS_WRITE (FCS_READ | FCS_FORCEWRITE)

Use *pfcs* to set the custom folder's settings if the values are not already present.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only Unicode strings are supported.

**Windows Server 2003 and Windows XP:** **SHGetSetFolderCustomSettings** supports both ANSI and Unicode strings.