## Description

Creates an instance of the object or model implementing the IConstructableConcept interface.

## Parameters

### `argCount`

The count of arguments to be passed to the constructor of the object.

### `ppArguments`

Pointer to the array of arguments passed to the constructor of the object. The array should have at least 'argCount' elements.

### `ppInstance`

Pointer to a location where a pointer to the newly created instance will be written.

## Return value

If the method succeeds, it returns S_OK, and a pointer to the newly created instance is written to 'ppInstance'. Otherwise, it returns an HRESULT error code.

## See also

[IConstructableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iconstructableconcept)