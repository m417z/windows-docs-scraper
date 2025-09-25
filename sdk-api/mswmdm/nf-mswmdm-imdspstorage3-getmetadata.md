# IMDSPStorage3::GetMetadata

## Description

The **GetMetadata** method retrieves metadata from the service provider.

## Parameters

### `pMetadata` [in]

Pointer to an **IWMDMMetaData** interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The service provider calls [IWMDMMetaData::AddItem](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-additem) for each of the metadata properties to be sent to the application. The service provider should use the predefined metadata name tags (g_wszWMDMTitle, g_wszAlbumTitle, g_dwBitrate, and so on) contained in the mswmdm.h file.

## See also

[IMDSPStorage3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage3)

[IMDSPStorage3::SetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-setmetadata)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)