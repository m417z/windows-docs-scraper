# AuthzInitializeRemoteResourceManager function

## Description

The **AuthzInitializeRemoteResourceManager** function allocates and initializes a remote resource manager. The caller can use the resulting handle to make AuthZ calls over RPC to a remote instance of the resource manager configured on a server.

## Parameters

### `pRpcInitInfo` [in]

Pointer to an [AUTHZ_RPC_INIT_INFO_CLIENT](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_rpc_init_info_client) structure containing the initial information needed to configure the connection.

### `phAuthzResourceManager` [out]

A handle to the resource manager. When you have finished using the handle, free it by calling the [AuthzFreeResourceManager](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreeresourcemanager) function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).