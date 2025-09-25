# IBrowserService2::GetBaseBrowserData

## Description

Deprecated. Gets a read-only structure containing the protected elements owned by the base class, for the purpose of determining state.

## Parameters

### `pbbd` [in, out]

Type: **LPCBASEBROWSERDATA***

A pointer to a [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure that receives the read-only state of the base browser.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used as an optimization to access the internal state of the base browser. The state should be updated only by the base browser.