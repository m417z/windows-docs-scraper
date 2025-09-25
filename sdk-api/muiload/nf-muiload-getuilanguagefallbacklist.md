# GetUILanguageFallbackList function

## Description

Gets a fallback list of UI languages represented as language names.

## Parameters

### `pFallbackList` [out, optional]

Pointer to a double null-terminated buffer in which the function retrieves an ordered, null-delimited list of language names. Alternatively, this parameter contains **NULL** if *cchFallbackList* is set to 0. In this case, the function retrieves the required size of the language buffer in *pcchFallbackListOut*.

### `cchFallbackList` [in]

Size, in characters, of the language buffer indicated by pFallbackList. Alternatively, the application can set this parameter to 0. In this case, the function retrieves the required size of the language buffer in *pcchFallbackListOut*.

### `pcchFallbackOut` [out, optional]

Pointer to a buffer in which the function retrieves the size of the retrieved language list. Alternatively, if *cchFallbackList* specifies 0, the function retrieves the required size of the language buffer.

## Return value

Returns **TRUE** if the function retrieves a list of fallback languages or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management)