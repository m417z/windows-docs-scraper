# IMetaDataImport::CountEnum

## Description

Gets the number of elements in the enumeration that was retrieved by the specified enumerator.

## Parameters

### `hEnum` [in]

The handle for the enumerator.

### `pulCount` [out, retval]

The number of elements enumerated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The handle specified by *hEnum* is obtained from a previous **Enum***Name* call (for example, [IMetaDataImport::EnumTypeDefs](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-enumtypedefs)).

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)