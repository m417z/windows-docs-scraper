# ISearchCatalogManager2::PrioritizeMatchingURLs

## Description

Instructs the indexer to give a higher priority to indexing items that have URLs that match a specified pattern. These items will then have a higher priority than other indexing tasks.

## Parameters

### `pszPattern` [in]

Type: **LPCWSTR**

A string specifying the URL pattern that defines items that failed indexing and need re-indexing.

### `dwPrioritizeFlags` [in]

Type: **[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)**

A value from the [PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags) enumeration that specifies how to process items that the indexer has failed to index.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

## Remarks

The *pszPattern* string must specify a pattern than matches the entire item URL. You can use the asterisk wildcard character to create your pattern string.

The *PRIORITIZE_FLAG_IGNOREFAILURECOUNT* flag is valid only in combination with the *PRIORITIZE_FLAG_RETRYFAILEDITEMS* flag.

#### Examples

The following examples show the use of the asterisk wildcard character and of the *PRIORITIZE_FLAG_IGNOREFAILURECOUNT*.

```cpp
hr = cpSearchCatalogManager2->PrioritizeMatchingURLs("mapi://{<SID>}/Mailbox - Boyer Zara/*",
            PRIORITIZE_FLAG_RETRYFAILEDITEMS);
```

```cpp
hr = cpSearchCatalogManager2->PrioritizeMatchingURLs("file:f:/Project Files/*",
            PRIORITIZE_FLAG_RETRYFAILEDITEMS);
```

```cpp
hr = cpSearchCatalogManager2->PrioritizeMatchingURLs("file:f:/Project Files/*.docx",
            PRIORITIZE_FLAG_RETRYFAILEDITEMS | PRIORITIZE_FLAG_IGNOREFAILURECOUNT);
```