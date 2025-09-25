# PFNDPASTREAM callback function

## Description

Defines the prototype for the callback function used by [DPA_LoadStream](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_loadstream) and [DPA_SaveStream](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_savestream).

## Parameters

### `pinfo` [in]

Type: **DPASTREAMINFO***

A pointer to a [DPASTREAMINFO](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/ns-dpa_dsa-dpastreaminfo) structure.

### `pstream` [in]

Type: **struct IStream***

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object to read from or write to.

### `pvInstData` [in, optional]

Type: **void***

A void pointer to callback data that the client passed to [DPA_LoadStream](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_loadstream) or [DPA_SaveStream](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_savestream).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.