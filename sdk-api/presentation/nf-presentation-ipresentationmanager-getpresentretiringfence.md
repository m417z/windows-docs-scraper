## Description

Gets a fence that signals when a present is retiring.

## Parameters

### `riid`

Type: **REFIID**

A reference to the interface identifier (IID) of the interface being queried for.

### `fence`

Type: **[void](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)\*\***

The address of a pointer to an interface with the IID specified in the _`riid`_ parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

This fence will be signaled to the Present ID of each present when that present has begun retiring - that is, a subsequent present has been queued to take its place.

## See also