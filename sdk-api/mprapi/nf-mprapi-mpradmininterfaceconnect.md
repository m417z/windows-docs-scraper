# MprAdminInterfaceConnect function

## Description

The
**MprAdminInterfaceConnect** function creates a connection to the specified WAN interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. This handle is obtained from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `hEvent` [in]

Handle to an event that is signaled after the attempt to connect the interface has completed. The function initiates the connection attempt and returns immediately. After the event is signaled, you can obtain the result of the connection attempt by calling
[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo).

If this parameter is **NULL**, and *fBlocking* is **TRUE**, then this call is synchronous, that is, the function does not return until the connection attempt has completed.

The calling application must specify **NULL** for this parameter, if *hMprServer* specifies a remote router.

### `fSynchronous` [in]

If *hEvent* is **NULL** and this parameter is set to **TRUE**, the function does not return until the connection attempt has completed.

If *hEvent* is **NULL**, and this parameter is set to **FALSE**, the function will return immediately. A return value of PENDING indicates that the connection attempt was initiated successfully.

If *hEvent* is not **NULL**, this parameter is ignored.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_ALREADY_CONNECTING** | A connection is already in progress on this interface. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_INTERFACE_DISABLED** | The interface is currently disabled. |
| **ERROR_INTERFACE_HAS_NO_DEVICES** | No adapters are available for this interface. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_SERVICE_IS_PAUSED** | The Demand Dial service is currently paused. |
| **PENDING** | The interface is in the process of connecting. The calling application must wait on the *hEvent* handle, if one was specified. After the event is signaled, you can obtain the state of the connection and any associated error by calling [MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo). |

## Remarks

The following table summarizes the relationship between *hEvent* and *fBlocking*.

| hEvent | fBlocking | Result |
| --- | --- | --- |
| Event Handle | Ignored | The call returns immediately. A return value of PENDING indicates that the attempt was initiated successfully. Wait on *hEvent*. When *hEvent* is signaled, use [MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo) to determine the success or failure of the connection attempt. |
| **NULL** | **TRUE** | The call does not return until the connection attempt has completed. |
| **NULL** | **FALSE** | The call returns immediately. A return value of PENDING indicates that the attempt was initiated successfully. |

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceDisconnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedisconnect)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)