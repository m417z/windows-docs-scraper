# RawSearchFlags enumeration

## Description

Flags to GetRawValue/EnumerateRawValues.

## Constants

### `RawSearchNone`

There are no search flags.

RawSearchNone = 0x00000000,

### `RawSearchNoBases`

Indicates that the search should not recurse to base children (e.g.: base classes). Only names/typeswhich are in the object itself should be returned.

RawSearchNoBases = 0x00000001,

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)