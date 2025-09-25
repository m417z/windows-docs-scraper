# TdhEnumerateProviders function

## Description

Retrieves a list of all providers that have registered on the computer.

## Parameters

### `pBuffer` [out]

Array of providers that publicly define their events on the computer. For details, see the [PROVIDER_ENUMERATION_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_enumeration_info) structure.

### `pBufferSize` [in, out]

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| -- | -- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *pBuffer* buffer is too small. Use the required buffer size set in *pBufferSize* to allocate a new buffer. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |

## Remarks

Call [TdhEnumerateProvidersForDecodingSource function](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhenumerateprovidersfordecodingsource) to retrieve a list of providers that have registered a MOF class or manifest file on the computer.

Because the number of registered event providers may fluctuate between calls to this function, you should place this function in a loop that loops until the returned value is no longer ERROR_INSUFFICIENT_BUFFER.

### Examples

For an example that shows how to enumerate providers, see [Enumerating Providers](https://learn.microsoft.com/windows/desktop/ETW/enumerating-providers).

## See also
[TdhEnumerateProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfieldinformation)