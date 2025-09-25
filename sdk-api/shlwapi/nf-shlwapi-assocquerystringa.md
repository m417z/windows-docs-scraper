# AssocQueryStringA function

## Description

Searches for and retrieves a file or protocol association-related string from the registry.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

The flags that can be used to control the search. It can be any combination of [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) values, except that only one ASSOCF_INIT value can be included.

### `str` [in]

Type: **[ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr)**

The [ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr) value that specifies the type of string that is to be returned.

### `pszAssoc` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that is used to determine the root key. The following four types of strings can be used.

1. **File name extension**: A file name extension, such as .txt.
2. **CLSID**: A CLSID GUID in the standard "{GUID}" format.
3. **ProgID**: An application's ProgID, such as [Word.Document.8](https://learn.microsoft.com/windows/win32/shell/fa-progids).
4. **Executable name**: The name of an application's .exe file. The [ASSOCF_OPEN_BYEXENAME](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-url_scheme) flag must be set in *flags*.

### `pszExtra` [in, optional]

Type: **LPCTSTR**

An optional null-terminated string with additional information about the location of the string. It is typically set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `pszOut` [out, optional]

Type: **LPTSTR**

Pointer to a null-terminated string that, when this function returns successfully, receives the requested string. Set this parameter to **NULL** to retrieve the required buffer size.

### `pcchOut` [in, out]

Type: **DWORD***

A pointer to a value that, when calling the function, is set to the number of characters in the *pszOut* buffer. When the function returns successfully, the value is set to the number of characters actually placed in the buffer.

If the [ASSOCF_NOTRUNCATE](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-url_scheme) flag is set in *flags* and the buffer specified in *pszOut* is too small, the function returns E_POINTER and the value is set to the required size of the buffer.

If *pszOut* is **NULL**, the function returns S_FALSE and *pcchOut* points to the required size, in characters, of the buffer.

## Return value

Type: **HRESULT**

Returns a standard COM error value, including the following:

| Error | Meaning |
| --- | --- |
| S_OK | Success. |
| E_POINTER | The *pszOut* buffer is too small to hold the entire string. |
| S_FALSE | *pszOut* is **NULL**. *pcchOut* contains the required buffer size. |

## Remarks

This function is a wrapper for the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface. The **AssocQueryString** function is intended to simplify the process of using **IQueryAssociations** interface.

Once an item is selected, the host must decide which (if any) preview handler is available for that item. Preview handlers are typically registered on file name extensions or ProgID, but some preview handlers are only instantiated for items within particular shell folders (the MAPI preview handler is associated with any items that came from the MAPI Shell folder, for example). Thus, the host must use [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) to determine which preview handler to use. For further discussion of how the file and protocol association functions work, see [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations).

> [!NOTE]
> The shlwapi.h header defines AssocQueryString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).