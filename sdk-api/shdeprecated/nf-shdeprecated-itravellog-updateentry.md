# ITravelLog::UpdateEntry

## Description

Deprecated. Saves the browser state of the current entry in preparation for a pending navigation.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) that represents the nearest browser or frame within which the travel generating the log is taking place.

### `fIsLocalAnchor` [in]

Type: **BOOL**

A value specifying whether the new entry is a local anchor.

#### TRUE

The entry is an anchor link within the same page.

#### FALSE

The entry is another page or an anchor on another page.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.