# IEnumNetworks::Next

## Description

The **Next** method gets the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements requested in the enumeration.

### `rgelt` [out]

Pointer to the enumerated list of pointers returned by [INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork).

### `pceltFetched` [out]

Pointer to the number of elements returned.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The number of elements returned was not equal to *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |

## See also

[IEnumNetworks](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworks)