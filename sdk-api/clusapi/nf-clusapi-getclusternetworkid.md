# GetClusterNetworkId function

## Description

Returns the identifier of a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The **PCLUSAPI_GET_CLUSTER_NETWORK_ID** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

Handle to a network.

### `lpszNetworkId` [out]

Pointer to the identifier of the network associated with *hNetwork*, including the null-terminating character.

### `lpcchName` [in, out]

Pointer to the size of the *lpszNetworkID* buffer as a count of characters. On input, specify the maximum number of characters the buffer can hold, including the terminating **NULL**. On output, specifies the number of characters in the resulting name, excluding the terminating **NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the possible values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The buffer pointed to by *lpszNetworkID* is not big enough to hold the result. The *lpcchNetworkID* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

Note that *lpcchNetworkID* refers to a count of characters and not a count of bytes, and that the returned size does not include the terminating **NULL** in the count. For more information on sizing buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)