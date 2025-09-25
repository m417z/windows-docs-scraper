# PFNDAENUMCALLBACK callback function

## Description

Defines the prototype for the callback function used by dynamic structure array (DSA) and dynamic pointer array (DPA) functions.

## Parameters

### `p` [in, optional]

Type: **void***

 A pointer to the structure to be enumerated.

### `pData` [in, optional]

Type: **void***

The value that was passed in the *pData* parameter to function [DSA_EnumCallback](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_enumcallback).

## Return value

Type: **int**

The return value is used to determine whether to terminate or continue the iteration. A return value of zero indicates that the iteration should stop; nonzero indicates that the iteration should continue.

## Remarks

Alternate names for this callback are **PFNDPAENUMCALLBACK** and **PFNDSAENUMCALLBACK**.