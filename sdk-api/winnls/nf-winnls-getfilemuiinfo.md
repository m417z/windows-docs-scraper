# GetFileMUIInfo function

## Description

Retrieves resource-related information about a file.

## Parameters

### `dwFlags` [in]

Flags specifying the information to retrieve. Any combination of the following flags is allowed. The default value of the flags is MUI_QUERY_TYPE | MUI_QUERY_CHECKSUM.

| Value | Meaning |
| --- | --- |
| **MUI_QUERY_TYPE** | Retrieve one of the following values in the **dwFileType** member of [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo):<br><br>* MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL: The specified input file does not have resource configuration data. Thus it is neither an LN file nor a language-specific resource file. This type of file is typical for older executable files. If this file type is specified, the function will not retrieve useful information for the other types.<br>* MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN. The input file is an LN file.<br>* MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI. The input file is a language-specific resource file associated with an LN file. |
| **MUI_QUERY_CHECKSUM** | Retrieve the resource checksum of the input file in the **pChecksum** member of [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo). If the input file does not have resource configuration data, this member of the structure contains 0. |
| **MUI_QUERY_LANGUAGE_NAME** | Retrieve the language associated with the input file. For a language-specific resource file, this flag requests the associated language. For an LN file, this flag requests the language of the ultimate fallback resources for the module, which can be either in the LN file or in a separate language-specific resource file referenced by the resource configuration data of the LN file. For more information, see the Remarks section. |
| **MUI_QUERY_RESOURCE_TYPES** | Retrieve lists of resource types in the language-specific resource files and LN files as they are specified in the resource configuration data. See the Remarks section for a way to access this information. |

### `pcwszFilePath` [in]

Pointer to a null-terminated string indicating the path to the file. Typically the file is either an LN file or a language-specific resource file. If it is not one of these types, the only significant value that the function retrieves is MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL. The function only retrieves this value if the MUI_QUERY_RESOURCE_TYPES flag is set.

### `pFileMUIInfo` [in, out, optional]

Pointer to a buffer containing file information in a [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure and possibly in data following that structure. The information buffer might have to be much larger than the size of the structure itself. Depending on flag settings, the function can store considerable information following the structure, at offsets retrieved in the structure. For more information, see the Remarks section.

Alternatively, the application can set this parameter to **NULL** if *pcbFileMUIInfo* is set to 0. In this case, the function retrieves the required size for the information buffer in *pcbFileMUIInfo*.

**Note** If the value of *pFileMUIInfo* is not **NULL**, the **dwSize** member must be set to the size of the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure (including the information buffer), and the **dwVersion** member must be set to the current version of 0x001.

### `pcbFileMUIInfo` [in, out]

Pointer to the buffer size, in bytes, for the file information indicated by *pFileMUIInfo*. On successful return from the function, this parameter contains the size of the retrieved file information buffer and the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure that contains it.

Alternatively, the application can set this parameter to 0 if it sets **NULL** in *pFileMUIInfo*. In this case, the function retrieves the required file information buffer size in *pcbFileMUIInfo*. To allocate the correct amount of memory, this value should be added to the size of the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure itself.

**Note** The value of this parameter must match the value of the **dwSize** member of [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) if the value of *pFileMUIInfo* is not **NULL**.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For the MUI_QUERY_LANGUAGE_NAME flag, this function retrieves an offset, in bytes, from the beginning of [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) in the **dwLanguageNameOffset** member.

The following is sample code that accesses the language name associated with the input file:

```cpp
LPWSTR lpszLang = reinterpret_cast<LPWSTR>(
        reinterpret_cast<BYTE*>(pFileMUIInfo) +
        pFileMUIInfo->dwLanguageNameOffset);

```

For the MUI_QUERY_RESOURCE_TYPES flag, this function retrieves language-specific resource file information in the following [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) members:

* The **dwTypeIDMUIOffset** member contains the offset to an array of identifiers of resources contained in the language-specific resource file.
* The **dwTypeIDMUISize** member contains the size of the array of resource identifiers for the language-specific resource file.
* The **dwTypeNameMUIOffset** member contains the offset to an array of names of resources contained in the language-specific resource file.

If the input file is an LN file, the function fills in all the above structure members. In addition, it fills in the following members:

* The **dwTypeIDMainOffset** member contains the offset to an array of identifiers of resources contained in the LN file.
* The **dwTypeIDMainSize** member contains the size of the array of resource identifiers for the LN file.
* The **dwTypeNameMainOffset** member contains the offset to an array of names of resources contained in the file.

The following is sample code that accesses the array of resource identifiers in the LN file.

```cpp
DWORD *pdwTypeID = reinterpret_cast<DWORD *>(
        reinterpret_cast<BYTE*>(pFileMUIInfo) +
        pFileMUIInfo->dwTypeIDMainOffset);

```

**Note** The lists of language-specific resources are accessed in the same way.

The following is sample code to access the multistring array of resource names in the LN file.

```cpp
LPWSTR lpszNames = reinterpret_cast<LPWSTR>(
        reinterpret_cast<BYTE*>(pFileMUIInfo) +
        pFileMUIInfo->dwTypeNameMainOffset);

```

**Note** The lists of language-specific resources are accessed in the same way.

Each of the code samples uses two reinterpret casts. First the code casts to BYTE* so that the pointer arithmetic for the offset is done in bytes. Then the code casts the resulting pointer to the desired type.

Another approach is to write the following instead of the code shown in the samples. The effect is the same and the choice is strictly one of style.

```cpp
DWORD ix = pFileMUIInfo->dwLanguageNameOffset -
        offsetof(struct _FILEMUIINFO, abBuffer);
LPWSTR lpszLang = reinterpret_cast<LPWSTR>(&(pFileMUIInfo->abBuffer[ix]));

```

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetFileMUIInfo(
            System.UInt32 dwFlags,
            System.String pcwszFilePath,
            ref FILEMUIINFO pFileMUIInfo,
            ref System.UInt32 pcbFileMUIInfo
            );

```

## See also

[FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo)

[GetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreaduilanguage)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages)

[SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage)