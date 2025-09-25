# FILEMUIINFO structure

## Description

Contains information about a file, related to its use with MUI. Most of this data is stored in the resource configuration data for the particular file. When this structure is retrieved by [GetFileMUIInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getfilemuiinfo), not all fields are necessarily filled in. The fields used depend on the flags that the application has passed to that function.

**Note** Your MUI applications can use the MUI macros to access this structure.

## Members

### `dwSize`

Size of the structure, including the buffer, which can be extended past the 8 bytes declared. The minimum value allowed is `sizeof(FILEMUIINFO)`.

### `dwVersion`

Version of the structure. The current version is 0x001.

### `dwFileType`

The file type. Possible values are:

* MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL. The input file does not have resource configuration data. This file type is typical for older executable files. If this file type is specified, the other file types will not provide useful information.
* MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN. The input file is an LN file.
* MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI. The input file is a language-specific resource file.

### `pChecksum`

Pointer to a 128-bit checksum for the file, if it is either an LN file or a language-specific resource file.

### `pServiceChecksum`

Pointer to a 128-bit checksum for the file, used for servicing.

### `dwLanguageNameOffset`

Offset, in bytes, from the beginning of the structure to the language name string for a language-specific resource file, or to the ultimate fallback language name string for an LN file.

### `dwTypeIDMainSize`

Size of the array for which the offset is indicated by *dwTypeIDMainOffset*. The size also corresponds to the number of strings in the multi-string array indicated by *dwTypeNameMainOffset*.

### `dwTypeIDMainOffset`

Offset, in bytes, from the beginning of the structure to a DWORD array enumerating the resource types contained in the LN file.

### `dwTypeNameMainOffset`

Offset, in bytes, from the beginning of the structure to a series of null-terminated strings in a multi-string array enumerating the resource names contained in the LN file.

### `dwTypeIDMUISize`

Size of the array with the offset indicated by *dwTypeIDMUIOffset*. The size also corresponds to the number of strings in the series of strings indicated by *dwTypeNameMUIOffset*.

### `dwTypeIDMUIOffset`

Offset, in bytes, from the beginning of the structure to a DWORD array enumerating the resource types contained in the LN file.

### `dwTypeNameMUIOffset`

Offset, in bytes, from the beginning of the structure to a multi-string array enumerating the resource names contained in the LN file.

### `abBuffer`

Remainder of the allocated memory for this structure. See the Remarks section for correct use of this array.

## Remarks

All offsets are from the base of the structure. An offset of 0 indicates that the data is not available.

The following is an example showing how to access data for the position in the structure that is described by an offset. This example accesses the language name string with the position defined by *dwLanguageNameOffset*.

```cpp
PFILEMUIINFO pFileMUIInfo = NULL;

Allocate_pFileMUIInfo_AndPassTo_GetFileMUIInfo(&pFileMUIInfo);

LPWSTR lpszLang = reinterpret_cast<LPWSTR>(reinterpret_cast<BYTE*>(pFileMUIInfo) + pFileMUIInfo->dwLanguageNameOffset);

```

This example uses two reinterpret casts. First the code casts to BYTE* so the pointer arithmetic for the offset will be done in bytes. Then the code casts the resulting pointer to the desired type.

Alternatively, the code can be written as shown below. The effect is the same; the choice is strictly one of style.

```cpp
PFILEMUIINFO pFileMUIInfo = NULL;

Allocate_pFileMUIInfo_AndPassTo_GetFileMUIInfo(&pFileMUIInfo);

DWORD ix = pFileMUIInfo->dwLanguageNameOffset - offsetof(struct _FILEMUIINFO, abBuffer);
LPWSTR lpszLang = reinterpret_cast<LPWSTR>(&(pFileMUIInfo->abBuffer[ix]));

```

### C# Signature

```cpp
unsafe public struct FILEMUIINFO
        {
            public System.UInt32 dwSize;
            public System.UInt32 dwVersion;
            public System.UInt32 dwFileType;
            public fixed System.Byte pChecksum[16];
            public fixed System.Byte pServiceChecksum[16];
            public System.UInt32 dwLanguageNameOffset;
            public System.UInt32 dwTypeIDMainSize;
            public System.UInt32 dwTypeIDMainOffset;
            public System.UInt32 dwTypeNameMainOffset;
            public System.UInt32 dwTypeIDMUISize;
            public System.UInt32 dwTypeIDMUIOffset;
            public System.UInt32 dwTypeNameMUIOffset;
            public fixed System.Byte abBuffer[8];
        }

```

## See also

[GetFileMUIInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getfilemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Macros](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-macros)

[Multilingual User Interface Structures](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-structures)