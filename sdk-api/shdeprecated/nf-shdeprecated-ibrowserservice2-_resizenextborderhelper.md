# IBrowserService2::_ResizeNextBorderHelper

## Description

Deprecated. A helper method used by the implementation of [IBrowserService2::_ResizeNextBorder](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_resizenextborder).

## Parameters

### `itb` [in]

Type: **UINT**

The index of the browser toolbar.

### `bUseHmonitor` [in]

Type: **BOOL**

A value of type **BOOL** that indicates whether to use an **HMONITOR** to determine the display. **TRUE** to use the **HMONITOR**; **FALSE** to ignore the particular display in the size determination.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.