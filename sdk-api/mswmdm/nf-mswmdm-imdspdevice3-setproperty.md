# IMDSPDevice3::SetProperty

## Description

The **SetProperty** method sets a specific device property that is writable.

## Parameters

### `pwszPropName` [in]

Name of device property being set.

### `pValue` [in]

Value of device property being set.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method sets the specified device property.

For a list of device property names, see [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

This method is similar to the **SetMetadata** method for storages, but this method can set only one property at a time.

## See also

[IMDSPDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice3)

[IMDSPDevice3::GetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice3-getproperty)

[IMDSPStorage3::SetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-setmetadata)

[IMDSPStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-getspecifiedmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)