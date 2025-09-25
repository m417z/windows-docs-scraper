# IQueryAssociations::GetString

## Description

Searches for and retrieves a file or protocol association-related string from the registry.

## Parameters

### `flags` [in]

Type: **[ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str)**

A flag that can be used to control the search. It can be any combination of the following [ASSOCF](https://learn.microsoft.com/windows/win32/shell/assocf_str) values.

* [ASSOCF_IGNOREBASECLASS](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_NOFIXUPS](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_NOTRUNCATE](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_NOUSERSETTINGS](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_REMAPRUNDLL](https://learn.microsoft.com/windows/win32/shell/assocf_str)
* [ASSOCF_VERIFY](https://learn.microsoft.com/windows/win32/shell/assocf_str)

### `str` [in]

Type: **[ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr)**

An [ASSOCSTR](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-assocstr) value that specifies the type of string that is to be returned.

### `pszExtra` [in, optional]

Type: **LPCWSTR**

A pointer to an optional, null-terminated Unicode string with information about the location of the string. It is typically set to a Shell verb such as **open**. Set this parameter to **NULL** if it is not used.

### `pszOut` [out, optional]

Type: **LPWSTR**

A pointer to a null-terminated Unicode string used to return the requested string. Set this parameter to **NULL** to retrieve the required buffer size.

### `pcchOut` [in, out]

Type: **DWORD***

A pointer to a value that, on entry, is set to the number of characters in the *pwszOut* buffer. When the function returns successfully, it points to the number of characters placed in the buffer.

If the [ASSOCF_NOTRUNCATE](https://learn.microsoft.com/windows/win32/shell/assocf_str) flag is set in *flags* and the buffer specified in *pwszOut* is too small, the function returns E_POINTER and *pcchOut* points to the required size of the buffer.

If *pwszOut* is **NULL**, the function returns S_FALSE and *pcchOut* points to the required size of the buffer.

## Return value

Type: **HRESULT**

Returns a standard COM error value, including the following:

| Error | Meaning |
| --- | --- |
| S_OK | Success. |
| E_POINTER | The *pwszOut* buffer is too small to hold the entire string. |
| S_FALSE | *pwszOut* is **NULL**. *pcchOut* contains the required buffer size. |