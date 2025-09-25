# IMDSPDevice3::GetProperty

## Description

The **GetProperty** method retrieves a specific device property.

## Parameters

### `pwszPropName` [in]

Name of property being retrieved from the device.

### `pValue` [out]

Returned value for the property.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The variant that *pValue* points to is set to an empty **PROPVARIANT**, that is, its VT is set to VT_EMPTY.

Service provider should set this variant to the appropriate property value for the property *pwszPropName*.

If *pwszPropName* is **g_wszWMDMSupportedDeviceProperties**, service provider should return an array of the supported device properties. In such case, the VT of variant should be VT_BSTR | VT_ARRAY.

For a list of standard device property names, see [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

This method is similar to the [IMDSPStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-getmetadata) and [IMDSPStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-getspecifiedmetadata) methods for storages, but this method can get only one property at a time.

## See also

[IMDSPDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice3)

[IMDSPDevice3::SetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice3-setproperty)

[IMDSPStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-getmetadata)

[IMDSPStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-getspecifiedmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)