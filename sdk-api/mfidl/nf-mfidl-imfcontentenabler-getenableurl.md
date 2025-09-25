# IMFContentEnabler::GetEnableURL

## Description

Retrieves a URL for performing a manual content enabling action.

## Parameters

### `ppwszURL` [out]

Receives a pointer to a buffer that contains the URL. The caller must release the memory for the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcchURL` [out]

Receives the number of characters returned in *ppwszURL*, including the terminating NULL character.

### `pTrustStatus` [in, out]

Receives a member of the [MF_URL_TRUST_STATUS](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_url_trust_status) enumeration indicating whether the URL is trusted.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_AVAILABLE** | No URL is available. |

## Remarks

If the enabling action can be performed by navigating to a URL, this method returns the URL. If no such URL exists, the method returns a failure code.

The purpose of the URL depends on the content enabler type, which is obtained by calling [IMFContentEnabler::GetEnableType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenabletype).

| Enable type | Purpose of URL |
| --- | --- |
| Individualization | Not applicable. |
| License acquisition | URL to obtain the license. Call [IMFContentEnabler::GetEnableData](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenabledata) and submit the data to the URL as an HTTP POST request. To receive notification when the license is acquired, call [IMFContentEnabler::MonitorEnable](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-monitorenable). |
| Revocation | URL to a webpage where the user can download and install an updated component. |

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)