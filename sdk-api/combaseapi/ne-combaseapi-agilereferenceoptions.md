# AgileReferenceOptions enumeration

## Description

Specifies options for the [RoGetAgileReference](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-rogetagilereference) function.

## Constants

### `AGILEREFERENCE_DEFAULT:0`

Use the default marshaling behavior, which is to marshal interfaces when an agile reference to the interface is obtained.

### `AGILEREFERENCE_DELAYEDMARSHAL:1`

Marshaling happens on demand. Use this option only in situations where it's very likely that an object is resolved only from the same apartment in which it was registered.

## See also

[RoGetAgileReference](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-rogetagilereference)