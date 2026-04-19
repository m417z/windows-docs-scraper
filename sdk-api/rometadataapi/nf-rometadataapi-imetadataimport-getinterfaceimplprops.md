# IMetaDataImport::GetInterfaceImplProps

## Description

Gets a pointer to the metadata tokens for the implementer-implementee relationship between two types.

## Parameters

### `tkInterfaceImpl` [in]

The metadata token representing the interface implementation relationship.

### `ptkClass` [out]

The metadata token representing the implementer: the class or interface that implements the interface **ptkIface**.

### `ptkIface` [out]

The metadata token representing the implementee: the interface that is implemented by **ptkClass**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **InterfaceImpl** token represents a single mapping between an implementing type and an implemented interface, as stored in the **InterfaceImpl** table.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)