# IDebugHostType2::CreatePointerTo

## Description

For any given type, this returns a new [IDebugHostType2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2) which is a pointer to this type.
The kind of pointer is supplied by the "kind" argument.

## Parameters

### `kind`

The kind of pointer to create (e.g.: a standard pointer, a C++ reference, a C++ rvalue reference, etc…)

### `newType`

The newly created pointer type will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)