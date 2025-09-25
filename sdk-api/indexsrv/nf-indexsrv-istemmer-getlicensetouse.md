# IStemmer::GetLicenseToUse

## Description

Gets the license information for this [IStemmer](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-istemmer) implementation.

## Parameters

### `ppwcsLicense` [out]

Type: **const WCHAR****

Pointer to a variable that receives a pointer to the license information for this [IStemmer](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-istemmer) implementation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Windows Search does not enforce license restrictions. The implementation determines the storage method for the license information.