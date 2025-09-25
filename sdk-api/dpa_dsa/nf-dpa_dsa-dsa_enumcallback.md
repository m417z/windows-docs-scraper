# DSA_EnumCallback function

## Description

Iterates through the dynamic structure array (DSA) and calls *pfnCB* on each item.

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to an existing DSA.

### `pfnCB` [in]

Type: **[PFNDAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback)***

A callback function pointer. See [PFNDSAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback) for the callback function prototype.

### `pData` [in]

Type: **void***

A callback data pointer. *pData* is passed as a parameter to *pfnCB*.

## See also

[PFNDAENUMCALLBACKCONST](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallbackconst)