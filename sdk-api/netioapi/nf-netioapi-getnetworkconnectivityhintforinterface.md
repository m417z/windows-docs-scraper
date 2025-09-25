## Description

Retrieves the level and cost of network connectivity for the specified interface.

## Parameters

### `InterfaceIndex` [in]

A value of type **NET_IFINDEX** representing the index of the interface for which to retrieve connectivity information.

### `ConnectivityHint` [out]

A pointer to a value of type [NL_NETWORK_CONNECTIVITY_HINT](https://learn.microsoft.com/windows/win32/api/nldef/ns-nldef-nl_network_connectivity_hint). The function sets this value to the connectivity level and cost hints for the specified interface.

## Return value

In user mode, returns **NO_ERROR** on success, and a Win32 error code on failure. In kernel mode, returns **STATUS_SUCCESS** on success, and an NTSTATUS error code on failure.

## Remarks

## See also