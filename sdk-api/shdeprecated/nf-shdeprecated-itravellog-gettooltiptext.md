# ITravelLog::GetToolTipText

## Description

Deprecated. Gets tooltip text for a travel entry, which is used as a Unicode display string in the UI.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

### `iOffset` [in]

Type: **int**

The number of travel entries forward (a positive value) or backward (a negative value) to move in the travel log to arrive at the travel entry from which text should be retrieved.

### `idsTemplate` [in]

Type: **int**

Not used.

### `pwzText` [out]

Type: **LPWSTR**

A pointer to a buffer that receives the Unicode tooltip text string.

### `cchText` [in]

Type: **DWORD**

The number of characters in the buffer pointed to by *pwzText*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.