# NPGetConnectionPerformance function

## Description

Returns information about the expected performance of a connection used to access a network resource. The request can only be for a network resource that is currently connected.

## Parameters

### `lpRemoteName` [in]

Pointer to the local name or remote name for a connected resource.

### `lpNetConnectInfo` [out]

Pointer to a
[NETCONNECTINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netconnectinfostruct) structure, which is filled in by the network provider if the provider has a connection to the network resource. All other fields of this structure, except the **cbStructure** field, are filled with zeros before the MPR passes the request on to the network providers. As a result, the provider has to write only to fields for which it has information available. Also, for rate values, a value of 1 means that the performance is better than can be represented in the unit.

The information returned may be an estimate. If the network cannot obtain information about the resource on the network, it can return information about the network adapter and its associated performance and then set the **dwFlags** field accordingly.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which can be one of the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_CONNECTED** | *lpRemoteName* is not a connected network resource. |
| **WN_NO_NETWORK** | The network is not present. |