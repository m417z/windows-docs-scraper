# PFNDAENUMCALLBACKCONST callback function

## Description

Defines the prototype for the callback function used by dynamic structure array (DSA) and dynamic pointer array (DPA) functions when the items involved are pointers to constant data.

## Parameters

### `p` [in, optional]

Type: **const void***

A pointer to the constant structure to be enumerated.

### `pData` [in, optional]

Type: **void***

A value that was passed in the *pData* parameter to function [DSA_EnumCallback](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_enumcallback) or function [DPA_EnumCallback](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_enumcallback).

## Return value

Type: **int**

The return value is used to determine whether to terminate or continue the iteration. A return value of zero indicates that the iteration should stop; nonzero indicates that the iteration should continue.

## Remarks

Alternate names for this callback are **PFNDPAENUMCALLBACKCONST** and **PFNDSAENUMCALLBACKCONST**.