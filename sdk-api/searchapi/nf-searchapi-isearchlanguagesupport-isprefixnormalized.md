# ISearchLanguageSupport::IsPrefixNormalized

## Description

Determines whether the query token is a prefix of the document token, disregarding case, width, and (optionally) diacritics.

## Parameters

### `pwcsQueryToken` [in]

Type: **LPCWSTR**

Pointer to the prefix to search for.

### `cwcQueryToken` [in]

Type: **ULONG**

The size of *pwcsQueryToken*.

### `pwcsDocumentToken` [in]

Type: **LPCWSTR**

Pointer to the document to be searched.

### `cwcDocumentToken` [in]

Type: **ULONG**

The size of *pwcsDocumentToken*.

### `pulPrefixLength` [out]

Type: **ULONG***

Returns a pointer to the number of characters matched in *pwcsDocumentToken*. Typically, but not necessarily, the number of characters in *pwcsQueryToken*.

## Return value

Type: **HRESULT**

If *pwcsQueryToken* is a prefix of *pwcsDocumentToken*, returns S_OK; otherwise returns S_FALSE, and *pulPrefixLength* is set to zero.