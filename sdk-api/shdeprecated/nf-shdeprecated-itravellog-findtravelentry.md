# ITravelLog::FindTravelEntry

## Description

Deprecated. Determines whether a specific travel entry is present in the travel log.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

### `pidl` [in]

Type: **LPCITEMIDLIST**

A PIDL of the travel entry, typically obtained through [GetPidl](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-itravelentry-getpidl).

### `ppte` [out]

Type: **[ITravelEntry](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravelentry)****

The address of a pointer to the [ITravelEntry](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravelentry) interface representing the travel entry, if found.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.