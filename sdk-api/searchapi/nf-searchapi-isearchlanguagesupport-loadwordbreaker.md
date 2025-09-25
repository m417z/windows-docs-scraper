# ISearchLanguageSupport::LoadWordBreaker

## Description

Retrieves an interface to the word breaker registered for the specified language code identifier (LCID).

## Parameters

### `lcid` [in]

Type: **LCID**

The LCID requested.

### `riid` [in]

Type: **REFIID**

IID of the interface to be queried.

### `ppWordBreaker` [out]

Type: **void****

On return, contains the address of a pointer to the interface of the LCID contained in *pLcidUsed*.

### `pLcidUsed` [out]

Type: **LCID***

On return, contains a pointer to the actual LCID used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.