# DPA_DestroyCallback function

## Description

[**DPA_DestroyCallback** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Calls *pfnCB* on each element of the dynamic pointer array (DPA), then frees the DPA.

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `pfnCB`

Type: **[PFNDPAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback)**

A callback function pointer. See [PFNDPAENUMCALLBACK](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallback) for the callback function prototype.

### `pData`

Type: **void***

A callback data pointer. *pData* is passed as a parameter to *pfnCB*.