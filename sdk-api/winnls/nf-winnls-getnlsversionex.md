# GetNLSVersionEx function

## Description

Retrieves information about the current version of a specified NLS capability for a locale specified by name.

**Note** The application should call this function in preference to [GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion) if designed to run only on Windows Vista and later.

## Parameters

### `function` [in]

The NLS capability to query. This value must be COMPARE_STRING. See the [SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function) enumeration.

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `lpVersionInformation` [in, out]

Pointer to an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure. The application must initialize the **dwNLSVersionInfoSize** member to  `sizeof(NLSVERSIONINFOEX)`.

**Note** On Windows Vista and later, the function can alternatively provide version information in an [NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1) structure.

## Return value

Returns **TRUE** if and only if the application has supplied valid values in *lpVersionInformation*, or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function allows an application such as Active Directory to determine if an NLS change affects the locale used for a particular index table. If it does not, there is no need to re-index the table. For more information, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications). In particular, to tell if a sort version changed and you need to reindex:

1. Use **GetNLSVersionEx** to retrieve an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure when doing the original indexing of your data.
2. Store the following properties with your index to identify the version:
   * **NLSVERSIONINFOEX.dwNLSVersion**. This specifies the version of the sorting table you're using.
   * **NLSVERSIONINFOEX.dwEffectiveId**. This specifies the effective locale of your sort. A custom locale will point to an in-box locale's sort.
   * **NLSVERSIONINFOEX.guidCustomVersion**. This is a GUID specifying a specific custom sort for custom locales that have them.
3. When using the index use **GetNLSVersionEx** to discover the version of your data.
4. If any of the three properties has changed, the sorting data you're using could return different results and any indexing you have may fail to find records.
5. If you know that your data doesn't contain invalid Unicode code points (that is, all of your strings passed a call to [IsNLSDefinedString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isnlsdefinedstring)) then you may consider them the same if only the low byte of **dwNLSVersion** changed (the minor version described above).

This is covered in more detail in the blog entry ["How to tell if the collation version changed"](https://learn.microsoft.com/archive/blogs/shawnste/) (http://blogs.msdn.com/shawnste/archive/2007/06/01/how-to-tell-if-the-collation-version-changed.aspx).

This function supports [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). If *lpLocaleName* specifies a supplemental locale, the data retrieved is the correct data for the sort order associated with that supplemental locale.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[How to tell if the collation version changed](https://learn.microsoft.com/archive/blogs/shawnste/)

[NLSVERSIONINFO](https://learn.microsoft.com/windows/win32/api/winnls/ns-winnls-nlsversioninfo-r1)

[NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSNLS_FUNCTION](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysnls_function)