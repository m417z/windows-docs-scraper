# IMDSPStorage4::GetSpecifiedMetadata

## Description

The **GetSpecifiedMetadata** method retrieves only the specified metadata object for a storage.

## Parameters

### `cProperties` [in]

Count of properties to be retrieved.

### `ppwszPropNames` [in]

Array that contains the property names to be retrieved. The size of this array should be equal to *cProperties*.

### `pMetadata` [out]

Pointer to the returned **IWMDMMetaData** interface pointer.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method gives the client control over which properties are retrieved. The client can specify the property names for the properties that the client needs to retrieve.

In contrast, the **GetMetadata** method retrieves all the storage metadata (properties).

If none of the specified properties can be returned, the service provider should return WMDM_E_NOTSUPPORTED or any suitable error code.

If at least one property can be retrieved, the service provider should return that property and set the return code to a success code of WMDM_S_NOT_ALL_PROPERTIES_RETRIEVED.

## See also

[IMDSPStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage4)