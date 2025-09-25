# IShellImageData::RegisterAbort

## Description

Sets a callback abort object, optionally returning a pointer to the previous object.

## Parameters

### `pAbort` [in]

Type: **[IShellImageDataAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedataabort)***

A pointer to an abort object. If this parameter is **NULL**, an unhandled exception results.

### `ppAbortPrev` [out, optional]

Type: **[IShellImageDataAbort](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedataabort)****

The address of a pointer to the previous abort object. This parameter can be **NULL** if the previous object is not of interest.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise.