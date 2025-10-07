# A\_SHAUpdate function

Adds data to a specified hash object.

## Parameters

*Context* \[in, out\]

The SHA context.

*Buffer* \[in\]

A pointer to a buffer that contains the data to be added to the hash object.

*BufferSize*

The size of the buffer.

## Return value

This function does not return a value.

## Remarks

This function can be called multiple times to compute the hash on long data streams or discontinuous data streams. The [**A\_SHAFinal**](https://learn.microsoft.com/windows/win32/seccrypto/a-shafinal) function must be called before retrieving the hash value.

This function is very similar to SHAUpdate, but is called directly from the library, rather than being routed through the cryptography infrastructure. For more information, see [Windows NTCryptographic Providers](https://learn.microsoft.com/previous-versions/tn-archive/cc723484(v=technet.10)).

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | Sha.h |
| Library<br> | Ntdll.dll |
| DLL<br> | Ntdll.dll |

