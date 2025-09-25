# ITravelLog::Travel

## Description

Deprecated. Navigates to a travel entry in the travel log relative to the position of the current entry.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) that represents the nearest browser or frame within which the travel generating the log is taking place.

### `iOffset` [in]

Type: **int**

The number of travel entries forward (a positive value) or backward (a negative value) to move in the travel log.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling **ITravelLog::Travel** has the same result as calling [Invoke](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-itravelentry-invoke).