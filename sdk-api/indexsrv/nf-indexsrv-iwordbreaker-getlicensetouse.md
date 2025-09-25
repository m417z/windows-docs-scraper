# IWordBreaker::GetLicenseToUse

## Description

Gets a pointer to the license information for this implementation of the [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) interface.

## Parameters

### `ppwcsLicense` [out]

Type: **WCHAR const****

Pointer to a variable that receives a pointer to the license information for this [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) implementation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.