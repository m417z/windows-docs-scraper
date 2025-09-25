# GetInterfaceContextTableForHostName function

## Description

This function retrieves an interface context table for the given hostname and connection profile filter.

## Parameters

### `HostName` [in, optional]

The destination hostname.

### `ProxyName` [in, optional]

The HTTP proxy name.

### `Flags` [in]

You can use the following flags.

|  |  |
| --- | --- |
| **Flag** | **Description** |
| **NET_INTERFACE_FLAG_NONE** | Use the default behavior. |
| **NET_INTERFACE_FLAG_CONNECT_IF_NEEDED** | Indicates whether the underlying connection should be activated or not. |

### `ConnectionProfileFilterRawData` [in, optional]

The connection profile filter blog which is a byte cast of wcm_selection_filters.

### `ConnectionProfileFilterRawDataSize` [in]

The size of the *ConnectionProfileFilterRawData* in bytes.

### `InterfaceContextTable` [out]

This is set to the list of [NET_INTERFACE_CONTEXT](https://learn.microsoft.com/windows/win32/api/ondemandconnroutehelper/ns-ondemandconnroutehelper-net_interface_context) structures containing the interface indices and configuration names that can be used for the hostname and filter.

## Return value

This function returns the following **HRESULT** values depending on the status.

|  |  |
| --- | --- |
| **HRESULT** | **Description** |
| **S_OK** | This is returned if a connection that satisfies the parameters and internal policies exists. [NET_INTERFACE_CONTEXT_TABLE](https://learn.microsoft.com/windows/win32/api/ondemandconnroutehelper/ns-ondemandconnroutehelper-net_interface_context) will contain a list of interfaces indices and configuration names of those connections. When S_OK is returned, [FreeInterfaceContextTable](https://learn.microsoft.com/windows/desktop/api/ondemandconnroutehelper/nf-ondemandconnroutehelper-freeinterfacecontexttable) should be called to release the context table. |
| **S_FALSE** | This is returned to indicate that any connection or default interface can be used for this hostname and filter. The [NET_INTERFACE_CONTEXT_TABLE](https://learn.microsoft.com/windows/win32/api/ondemandconnroutehelper/ns-ondemandconnroutehelper-net_interface_context) will be null in this case because the caller can use the default route to satisfy the requirements. |
| **E_NOTFOUND** | This is returned if no connection is currently available or existing connection don't meet the connection filter and the internal policy for the host. The exact return code would be **HRESULT(ERROR_NOT_FOUND)** |
| **E_INVALIDARG** | This is returned if the caller passes an invalid argument, uses an unsupported flag, has a bad connection filter data, incorrect size or null [NET_INTERFACE_CONTEXT_TABLE](https://learn.microsoft.com/windows/win32/api/ondemandconnroutehelper/ns-ondemandconnroutehelper-net_interface_context) |
| **E_OUTOFMEMORY** | This is returned if there is not enough memory to complete the operation. |
| **FAILED(HRESULT)** | This is returned because of failures that are outside the control of this function. |

## See also

[FreeInterfaceContextTable](https://learn.microsoft.com/windows/desktop/api/ondemandconnroutehelper/nf-ondemandconnroutehelper-freeinterfacecontexttable)

[NET_INTERFACE_CONTEXT_TABLE](https://learn.microsoft.com/windows/win32/api/ondemandconnroutehelper/ns-ondemandconnroutehelper-net_interface_context)