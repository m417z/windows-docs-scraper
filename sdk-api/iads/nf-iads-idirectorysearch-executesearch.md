# IDirectorySearch::ExecuteSearch

## Description

The **IDirectorySearch::ExecuteSearch** method executes a search and passes the results to the caller. Some providers, such as LDAP, will defer the actual execution until the caller invokes the [IDirectorySearch::GetFirstRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getfirstrow) method or the [IDirectorySearch::GetNextRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getnextrow) method.

## Parameters

### `pszSearchFilter` [in]

A search filter string in LDAP format, such as "(objectClass=user)".

### `pAttributeNames` [in]

An array of attribute names for which data is requested. If **NULL**, *dwNumberAttributes* must be 0 or 0xFFFFFFFF.

### `dwNumberAttributes` [in]

The size of the *pAttributeNames* array. The special value 0xFFFFFFFF indicates that *pAttributeNames* is ignored and can be **NULL**. This special value means that all attributes that are set are requested. If this value is 0 the *pAttributeNames* array can be **NULL**. No attribute will be requested.

### `phSearchResult` [out]

The address of a method-allocated handle to the search context. The caller passes this handle to other methods of [IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) to examine the search result. If **NULL**, the search cannot be executed.

## Return value

This method returns the standard return values, as well as the following:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When the search filter (*pszSearchFilter*) contains an attribute of **ADS_UTC_TIME** type, it value must be of the "yymmddhhmmssZ" format where "y", "m", "d", "h", "m" and "s" stand for year, month, day, hour, minute, and second, respectively. In this format, for example, "10:20:00 May 13th, 1999" becomes "990513102000Z". The final letter "Z" is the required syntax and indicated Zulu Time or Universal Coordinated Time.

The caller must call [IDirectorySearch::CloseSearchHandle](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-closesearchhandle) to release the memory allocated for the search handle and the result.

When using the special value of 0xFFFFFFFF for *dwNumberAttributes*, LDAP retrieval of ADsPath or distinguishedName has no extra resource or time cost.

#### Examples

The following C++ code example shows how to invoke **IDirectorySearch::ExecuteSearch**.

```cpp
LPWSTR pszAttr[] = { L"ADsPath", L"Name", L"samAccountName" };
ADS_SEARCH_HANDLE hSearch;
DWORD dwCount= sizeof(pszAttr)/sizeof(LPWSTR);

// Search for users with a last name that begins with "h".
hr = m_pSearch->ExecuteSearch(L"(&(objectClass=user)(sn=h*))", pszAttr, dwCount, &hSearch );
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::CloseSearchHandle](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-closesearchhandle)

[IDirectorySearch::GetFirstRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getfirstrow)

[IDirectorySearch::GetNextRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getnextrow)