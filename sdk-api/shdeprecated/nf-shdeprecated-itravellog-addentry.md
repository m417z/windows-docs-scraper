# ITravelLog::AddEntry

## Description

Deprecated. Adds a new entry for a pending navigation to the travel log.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

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