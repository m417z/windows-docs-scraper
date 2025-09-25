## Description

CanonicalizeLocation is a method that transforms a given location to its "canonical representation", which is a chosen standard form. It can handle different types of locations, for example, virtual memory and register, that can be represented in several ways.

A classic example where this function might be helpful involve the Debugging Tools for Windows (dbgeng) that historically sign extends 32-bit addresses to 64-bits, creating difficulties in representing and distinguishing certain address regions in high address aware 32-bit processes.

Note that comparing locations or addresses gotten from components which report sign extended addresses against zero extended ones could result in unforeseen failures. You can evade such mishaps by calling CanonicalizeLocation() beforehand. Keep in mind that this method doesn't transform the type of a location. To transform the type, you should call LinearizeLocation().

## Parameters

### `context`

The current context.

### `location`

The location you want to canonicalize.

### `pCanonicalizedLocation`

Pointer to where the canonicalized location will be stored.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

Although this method changes a location's representation to its canonical form, it doesn't alter the actual type of the location. Use the [LinearizeLocation() method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostmemory3-linearizelocation) to perform such type transformation.

## See also

[IDebugHostMemory5 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory5)