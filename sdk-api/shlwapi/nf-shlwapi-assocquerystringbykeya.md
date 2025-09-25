# AssocQueryStringByKeyA function

## Description

Searches for and retrieves a file association-related string from the registry starting from a specified key.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

The flags that can be used to control the search. It can be any combination of [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) values, except that only one ASSOCF_INIT value can be included.

### `str` [in]

Type: **[ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr)**

The [ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr) value that specifies the type of string that is to be returned.

### `hkAssoc` [in]

Type: **HKEY**

The HKEY value of the key that will be used as a root key. The search looks only below this key.

### `pszExtra` [in, optional]

Type: **LPCTSTR**

A pointer to an optional null-terminated string with additional information about the location of the string. It is normally set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `pszOut` [out, optional]

Type: **LPTSTR**

A pointer to a null-terminated string used to return the requested string. Set this parameter to **NULL** to retrieve the required buffer size.

### `pcchOut` [in, out]

Type: **DWORD***

A pointer to a value that, on entry, specifies the number of characters in the *pszOut* buffer. When the function returns, it points to the number of characters placed in the buffer.

If the [ASSOCF_NOTRUNCATE](https://learn.microsoft.com/windows/win32/api/shlwapi/ne-shlwapi-url_scheme) flag is set in *flags* and the buffer specified in *pszOut* is too small, the function returns E_POINTER and the value is set to the required size of the buffer.

If *pszOut* is **NULL**, the function returns S_FALSE and *pcchOut* points to the required size of the buffer.

## Return value

Type: **HRESULT**

Returns a standard COM error value, including the following:

| Error | Meaning |
| --- | --- |
| S_OK | Success. |
| E_POINTER | The *pszOut* buffer is too small to hold the entire string. |
| S_FALSE | *pszOut* is **NULL**. *pcchOut* contains the required buffer size. |

## Remarks

This function is a wrapper for the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface. It is intended to simplify the process of using this interface. For further discussion of how the file association functions work, see **IQueryAssociations**.

> [!NOTE]
> The shlwapi.h header defines AssocQueryStringByKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).