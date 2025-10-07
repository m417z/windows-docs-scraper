# ORGetVersion function

This function retrieves the version of the offline registry library.

## Parameters

*pdwMajorVersion* \[out\]

A pointer to a variable to receive the major version of the offline registry library. For the initial release of the library, the value is 1.

*pdwMinorVersion* \[out\]

A pointer to a variable to receive the minor version of the offline registry library. For the initial release of the library, the value is 0.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

