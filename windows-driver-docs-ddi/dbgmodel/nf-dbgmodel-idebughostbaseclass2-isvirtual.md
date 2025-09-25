## Description

The IsVirtual method indicates whether a particular base class is a virtual base class. This distinction is important in the context of class hierarchies, especially when handling virtual inheritance scenarios.

## Parameters

### `pIsVirtual`

A pointer to a boolean that will be set to true if the base class is a virtual base class; otherwise, it will be set to false.

## Return value

## Remarks

If a base class is determined to be virtual, it signifies that the memory location cannot be resolved with a simple offset. In such cases, calling methods like GetOffset may fail, returning an error code of E_NOT_SET, and developers will need to utilize other methods available through the IDebugHostBaseClass2 interface.

## See also

[IDebugHostBaseClass2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostbaseclass2)