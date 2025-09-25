# ITravelEntry::Update

## Description

Deprecated. Updates the travel entry.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the browser or frame within which the travel operation generating the entry is taking place.

### `fIsLocalAnchor` [in]

Type: **BOOL**

The value specifying whether the new entry is a local anchor.

#### TRUE

The entry is an anchor link within the same page.

#### FALSE

The entry is another page or an anchor on another page.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.