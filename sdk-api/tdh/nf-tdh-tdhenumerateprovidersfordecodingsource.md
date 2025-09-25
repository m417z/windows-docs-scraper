# TdhEnumerateProvidersForDecodingSource function (tdh.h)

## Description

Retrieves a list of providers that have registered a MOF class or manifest file on the computer.

## Parameters

### `filter`

One or more values from [DECODING_SOURCE enumeration](https://learn.microsoft.com/windows/win32/api/tdh/ne-tdh-decoding_source).

### `buffer` [out]

Array of providers that publicly define their events on the computer. For details, see the [PROVIDER_ENUMERATION_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-provider_enumeration_info).

### `bufferSize` [in, out]

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

### `bufferRequired` [out]

The buffer required.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| -- | -- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *pBuffer* buffer is too small. Use the required buffer size set in *pBufferSize* to allocate a new buffer. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |

## Remarks

Use [TdhEnumerateProviders](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhenumerateproviders) to retrieve all providers that have registered on the computer.

## See also