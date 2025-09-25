# MprAdminInterfaceDeviceGetInfo function

## Description

The
**MprAdminInterfaceDeviceGetInfo** retrieves information about a device that is used in a router demand-dial interface.

## Parameters

### `hMprServer` [in]

Handle to router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. Obtain this handle from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate), or by calling
[MprAdminInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceenum)

### `dwIndex` [in]

Specifies the one-based index of the device. A multi-linked demand-dial interface uses multiple devices.

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpBuffer* parameter. Acceptable values for *dwLevel* include 0 or 1 as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | [MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0) |
| 1 | [MPR_DEVICE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_1) |

### `lplpBuffer` [out]

On successful completion, a pointer to a [MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0) or [MPR_DEVICE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_1) structure. The *dwLevel* parameter indicates the type of structure.
Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* value is invalid. |

## See also

[MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0)

[MPR_DEVICE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_1)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceDeviceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicesetinfo)