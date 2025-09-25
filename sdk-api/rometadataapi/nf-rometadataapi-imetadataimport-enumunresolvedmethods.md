# IMetaDataImport::EnumUnresolvedMethods

## Description

Enumerates MemberDef tokens representing the unresolved methods in the current metadata scope.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be NULL for the first call of this method.

### `rgMethods` [out]

The array used to store the MemberDef tokens.

### `cMax` [in]

The maximum size of the *rgMethods* array.

### `pcTokens` [out]

The number of MemberDef tokens returned in *rgMethods*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumUnresolvedMethods** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## Remarks

An unresolved method is one that has been declared but not implemented. A method is included in the enumeration if the method is marked **miForwardRef** and either **mdPinvokeImpl** or **miRuntime** is set to zero. In other words, an unresolved method is a class method that is marked **miForwardRef** but which is not implemented in unmanaged code (reached via PInvoke) nor implemented internally by the runtime itself.

The enumeration excludes all methods that are defined either at module scope (globals) or in interfaces or abstract classes.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)