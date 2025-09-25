# eHeapEnumerationLevel enumeration

## Description

Determines whether the enumeration operation should continue or stop.

## Constants

### `HeapEnumerationEverything:0x0`

A constant that specifies the enumeration should continue.

### `HeapEnumerationStop:0xFFFFFFFF`

A constant that specifies to the [VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource) function when the enumeration operation should stop.

Codes from 0x1 to 0xFFFFFFE are reserved.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)