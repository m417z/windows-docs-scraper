## Description

The CreateFunctionAliasWithMetadata method is similar to [CreateFunctionAlias](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostextensibility2-createfunctionalias) but allows for passing metadata information about the function.

## Parameters

### `aliasName`

A pointer to a wide-character string that specifies the name of the alias.

### `functionObject`

A pointer to the IModelObject interface of the function object.

### `metadata`

A pointer to the IKeyStore interface for the metadata. This parameter is optional.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostExtensibility2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility2)