# IBrowserService2::_GetBorderDWHelper

## Description

Deprecated. A helper method for the implementation of [GetBorderDW](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-idockingwindowsite-getborderdw).

## Parameters

### `punkSrc` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) that represents the object for which the border space is being requested.

### `lprectBorder` [in]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the dimensions of the available border space for the browser.

### `bUseHmonitor` [in]

Type: **BOOL**

A value of type **BOOL** that indicates whether to use an **HMONITOR** to determine the display. **TRUE** to use the **HMONITOR**; **FALSE** to ignore the particular display in the size determination.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.