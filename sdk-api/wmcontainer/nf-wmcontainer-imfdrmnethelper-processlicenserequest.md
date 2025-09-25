# IMFDRMNetHelper::ProcessLicenseRequest

## Description

Gets the license response for the specified request.

## Parameters

### `pLicenseRequest` [in]

Pointer to a byte array that contains the license request.

### `cbLicenseRequest` [in]

Size, in bytes, of the license request.

### `ppLicenseResponse` [out]

Receives a pointer to a byte array that contains the license response. The caller must free the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbLicenseResponse` [out]

Receives the size, in bytes, of the license response.

### `pbstrKID` [out]

Receives the key identifier. The caller must release the string by calling **SysFreeString**.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink was shut down. |

## See also

[IMFDRMNetHelper](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfdrmnethelper)