# IEnumExtraSearch::Next

## Description

Used to request information on one or more search objects.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of search objects to be enumerated, starting from the current object. If *celt* is too large, the method should stop and return the actual number of search objects in *pceltFetched*.

### `rgelt` [out]

Type: **[EXTRASEARCH](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-extrasearch)***

A pointer to an array of *pceltFetched* [EXTRASEARCH](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-extrasearch) structures containing information on the enumerated objects.

### `pceltFetched` [out]

Type: **ULONG***

The number of objects actually enumerated. This may be less than *celt*.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.