# MprAdminInterfaceGetHandle function

## Description

The
**MprAdminInterfaceGetHandle** function retrieves a handle to a specified interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `lpwsInterfaceName` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the interface to be retrieved.

### `phInterface` [out]

Pointer to a **HANDLE** variable that receives a handle to the interface specified by *lpwsInterfaceName*.

### `fIncludeClientInterfaces` [in]

Specifies whether the function returns a client interface. If this parameter is **FALSE**, interfaces of type **ROUTER_IF_TYPE_CLIENT** are ignored in the search for the interface with the name specified by *lpwsInterfaceName*. If this parameter is **TRUE** and an interface with the specified name exists,
**MprAdminInterfaceGetHandle** returns a handle to an interface of type **ROUTER_IF_TYPE_CLIENT**. Since it is possible that there are several interfaces of type **ROUTER_IF_TYPE_CLIENT**, the handle returned references the first interface found with the name specified by *lpwsInterfaceName*.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_NO_SUCH_INTERFACE** | No interface exists with the name specified by *lpwsInterfaceName*. |
| **RPC_S_INVALID_BINDING** | The passed in handle to the server is **NULL**. |
| **RPC_X_NULL_REF_POINTER** | *lpwsInterfaceName* is **NULL**. |

## See also

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)