# IModelObject::EnumerateRawReferences

## Description

The EnumerateRawReferences method enumerates references to all native children (e.g.: fields, base classes, etc...) of the given object.

## Parameters

### `kind`

Indicates the kind of native symbol to fetch (e.g.: a base class or a data member).

### `searchFlags`

An optional set of flags specifying the behavior of the search for the native construct.

### `enumerator`

An enumerator which will enumerate a reference (an object that is a ObjectTargetObjectReference style object) to every native child of the kind specified by the kind argument as an [IRawEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-irawenumerator) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)