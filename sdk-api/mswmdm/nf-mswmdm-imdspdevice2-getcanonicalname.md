# IMDSPDevice2::GetCanonicalName

## Description

The **GetCanonicalPName** method gets the canonical name of a device.

## Parameters

### `pwszPnPName` [out]

A wide character, null-terminated buffer holding the canonical name. The caller allocates and releases this buffer.

### `nMaxChars` [in]

Integer containing the maximum number of characters that can be placed in *pwszCanonicalName*, including the termination character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

## Remarks

This method returns a canonical name for the device. The service provider should return the device path name of the device as its canonical name. The service provider is passed the device path name in the **CreateDevice** method on the [IMDServiceProvider2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider2) interface.

This is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice2)

[IMDServiceProvider2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider2)

[IMDServiceProvider2::CreateDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdserviceprovider2-createdevice)