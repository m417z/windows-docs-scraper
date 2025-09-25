# ITravelLog::GetTravelEntry

## Description

Deprecated. Gets a travel entry in the travel log relative to the position of the current entry.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

### `iOffset` [in]

Type: **int**

The number of travel entries forward (a positive value) or backward (a negative value) to move in the travel log.

### `ppte` [out, optional]

Type: **[ITravelEntry](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravelentry)****

The address of a pointer to the [ITravelEntry](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravelentry) interface representing the travel entry at the offset specified in *iOffset*. This value is only valid if the method returns successfully.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**ITravelLog::GetTravelEntry** is often used to discover whether the **Back** and **Forward** buttons should be enabled in the browser window.