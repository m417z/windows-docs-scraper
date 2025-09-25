# DSA_DestroyCallback function

## Description

[**DSA_DestroyCallback** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Iterates through a dynamic structure array (DSA), calling a specified callback function on each item. Upon reaching the end of the array, the DSA is freed.

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to a DSA to walk and destroy.

### `pfnCB` [in]

Type: **[PFNDSAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback)**

A callback function pointer. For the callback function prototype, see [PFNDSAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback).

### `pData` [in]

Type: **void***

A callback data pointer. This pointer is, in turn, passed as a parameter to *pfnCB*.