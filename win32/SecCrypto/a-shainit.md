# A\_SHAInit function

Initiates the hashing of a stream of data.

## Parameters

*Context* \[in, out\]

The SHA context.

## Return value

This function does not return a value.

## Remarks

This function is very similar to SHAInit, but is called directly from the library, rather than being routed through the cryptography infrastructure. For more information, see [Windows NTCryptographic Providers](https://learn.microsoft.com/previous-versions/tn-archive/cc723484(v=technet.10)).

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | Sha.h |
| Library<br> | Ntdll.dll |
| DLL<br> | Ntdll.dll |

