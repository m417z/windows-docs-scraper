# IBrowserService2::InitializeTravelLog

## Description

Deprecated. Allows the derived class to specify a navigation record to be used in a new window.

## Parameters

### `ptl` [in]

Type: **[ITravelLog](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravellog)***

A pointer to an existing [ITravelLog](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravellog) object to be used for the new window.

### `dw` [in]

Type: **DWORD**

The new browser window's ID.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.