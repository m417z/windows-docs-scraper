## Description

The ReadOrdinalIntrinsics method reads one or more intrinsic values from the target's address space as defined by the given context and location. This method is similar to ReadIntrinsics(), but the type of intrinsic is specified by an ordinal size and an indication of whether the intrinsics are signed. This method supports 8-64 bit signed and unsigned ordinals.

## Parameters

### `context`

The context in effect.

### `location`

The location from where intrinsic values will be read

### `ordinalSize`

Specifies the size of the ordinal intrinsics to read.

### `ordinalIsSigned`

Specifies whether the ordinal intrinsics are signed or not.

### `count`

Specifies the number of intrinsic values to read.

### `vals`

A pointer to the storage location where the read intrinsic values will be stored.

### `intrinsicsRead`

Returns the number of intrinsics successfully read.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory5 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory5)