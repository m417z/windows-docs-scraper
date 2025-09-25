# IMDSPStorage3::SetMetadata

## Description

The **SetMetadata** method provides the metadata associated with a specified content.

## Parameters

### `pMetadata` [in]

Pointer to an **IWMDMMetadata** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded, which indicates that SP has successfully processed the metadata. |
| **WMDM_E_NOT_SUPPORTED** | The device does not support setting metadata. |

## Remarks

A service provider calls **IWMDMMetaData::QueryByName** or **IWMDMMetaData::QueryByIndex** to retrieve the metadata.

## See also

[IMDSPStorage3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage3)

[IMDSPStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-getmetadata)

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[IWMDMMetaData::QueryByIndex](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyindex)

[IWMDMMetaData::QueryByName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyname)