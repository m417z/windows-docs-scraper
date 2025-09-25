# IStorage::SetStateBits

## Description

The **SetStateBits** method stores up to 32 bits of state information in this storage object. This method is reserved for future use.

## Parameters

### `grfStateBits` [in]

Specifies the new values of the bits to set. No legal values are defined for these bits; they are all reserved for future use and must not be used by applications.

### `grfMask` [in]

A binary mask indicating which bits in *grfStateBits* are significant in this call.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The state information was successfully set.|
|E_PENDING | Asynchronous Storage only: Part or all of the storage's data is currently unavailable. |
|STG_E_ACCESSDENIED | The caller does not have enough permissions for changing this storage object.|
|STG_E_INVALIDFLAG | The value for the grfStateBits or *grfMask* parameter is not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|

## Remarks

The values for the state bits are not currently defined.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)