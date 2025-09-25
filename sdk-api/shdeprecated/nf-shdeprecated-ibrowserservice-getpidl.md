# IBrowserService::GetPidl

## Description

Deprecated. Retrieves a copy of the current pointer to an item identifier list (PIDL).

## Parameters

### `ppidl` [out]

Type: **LPITEMIDLIST***

A pointer to the current PIDL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The calling application is responsible for freeing the PIDL by calling [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree) when the PIDL is no longer needed.