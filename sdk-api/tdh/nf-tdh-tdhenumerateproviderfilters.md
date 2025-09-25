# TdhEnumerateProviderFilters function

## Description

The **TdhEnumerateProviderFilters** function enumerates the filters that the specified provider defined in the manifest.

## Parameters

### `Guid` [in]

GUID that identifies the provider whose filters you want to retrieve.

### `TdhContextCount` [in]

Not used.

### `TdhContext` [in, optional]

Not used.

### `FilterCount` [in]

The number of filter structures that the *pBuffer* buffer contains. Is zero if the *pBuffer* buffer is insufficient.

### `Buffer` [out, optional]

User-allocated buffer to receive the filter information. For details, see the [PROVIDER_FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_filter_info) structure.

### `BufferSize` [in, out]

Size, in bytes, of the *pBuffer* buffer. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_INSUFFICIENT_BUFFER and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *pBuffer* buffer is too small. Use the required buffer size set in *pBufferSize* to allocate a new buffer. |
| **ERROR_NOT_FOUND** | The schema for the event was not found. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_FILE_NOT_FOUND** | The **resourceFileName** attribute in the manifest contains the location of the provider binary. When you register the manifest, the location is written to the registry. TDH was unable to find the binary based on the registered location. |

## Remarks

This function uses the XML manifest to retrieve the information.