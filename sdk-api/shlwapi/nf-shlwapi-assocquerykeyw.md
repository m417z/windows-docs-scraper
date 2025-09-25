# AssocQueryKeyW function

## Description

Searches for and retrieves a key related to a file or protocol association from the registry.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

The flags that can be used to control the search. It can be any combination of [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) values, except that only one ASSOCF_INIT value can be included.

### `key` [in]

Type: **[ASSOCKEY](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assockey)**

The [ASSOCKEY](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assockey) value that specifies the type of key that is to be returned.

### `pszAssoc` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that is used to determine the root key. Four types of strings can be used.

#### File name extension

A file name extension, such as .txt.

#### CLSID

A CLSID GUID in the standard "{GUID}" format.

#### ProgID

An application's ProgID, such as **Word.Document.8**.

#### Executable name

The name of an application's .exe file. The [ASSOCF_OPEN_BYEXENAME](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-url_scheme) flag must be set in *flags*.

### `pszExtra` [in]

Type: **LPCTSTR**

A pointer to an optional null-terminated string with additional information about the location of the string. It is normally set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `phkeyOut` [out]

Type: **HKEY***

A pointer to the key's HKEY value.

##### - pszAssoc.CLSID

A CLSID GUID in the standard "{GUID}" format.

##### - pszAssoc.Executable name

The name of an application's .exe file. The [ASSOCF_OPEN_BYEXENAME](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-url_scheme) flag must be set in *flags*.

##### - pszAssoc.File name extension

A file name extension, such as .txt.

##### - pszAssoc.ProgID

An application's ProgID, such as **Word.Document.8**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This function is a wrapper for the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface. It is intended to simplify the process of using the interface. For further discussion of how the file and protocol association functions work, see **IQueryAssociations**.

> [!NOTE]
> The shlwapi.h header defines AssocQueryKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).