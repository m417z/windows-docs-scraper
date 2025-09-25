# DPA_EnumCallback function

## Description

[**DPA_EnumCallback** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Iterates through the Dynamic Pointer Array (DPA) and calls *pfnCB* on each item.

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

## See also

[PFNDAENUMCALLBACKCONST](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndaenumcallbackconst)