# PNP_VETO_TYPE enumeration

## Description

If the PnP manager rejects a request to perform an operation, the PNP_VETO_TYPE enumeration is used to identify the reason for the rejection.

## Constants

### `PNP_VetoTypeUnknown`

The specified operation was rejected for an unknown reason.

### `PNP_VetoLegacyDevice`

The device does not support the specified PnP operation.

### `PNP_VetoPendingClose`

The specified operation cannot be completed because of a pending close operation.

### `PNP_VetoWindowsApp`

A Microsoft Win32 application vetoed the specified operation.

### `PNP_VetoWindowsService`

A Win32 service vetoed the specified operation.

### `PNP_VetoOutstandingOpen`

The requested operation was rejected because of outstanding open handles.

### `PNP_VetoDevice`

The device supports the specified operation, but the device rejected the operation.

### `PNP_VetoDriver`

The driver supports the specified operation, but the driver rejected the operation.

### `PNP_VetoIllegalDeviceRequest`

The device does not support the specified operation.

### `PNP_VetoInsufficientPower`

There is insufficient power to perform the requested operation.

### `PNP_VetoNonDisableable`

The device cannot be disabled.

### `PNP_VetoLegacyDriver`

The driver does not support the specified PnP operation.

### `PNP_VetoInsufficientRights`

The caller has insufficient privileges to complete the operation.

## Remarks

Text strings are associated with most of the veto types, and a function that receives a veto type value can typically request to also receive the value's associated text string. The following table identifies the text string associated with each value.

| pVeto type value | Text String |
| --- | --- |
| **PNP_VetoTypeUnknown** | None. |
| **PNP_VetoLegacyDevice** | A device instance path. |
| **PNP_VetoPendingClose** | A device instance path. |
| **PNP_VetoWindowsApp** | An application module name. |
| **PNP_VetoWindowsService** | A Windows service name. |
| **PNP_VetoOutstandingOpen** | A device instance path. |
| **PNP_VetoDevice** | A device instance path. |
| **PNP_VetoDriver** | A driver name. |
| **PNP_VetoIllegalDeviceRequest** | A device instance path. |
| **PNP_VetoInsufficientPower** | None. |
| **PNP_VetoNonDisableable** | A device instance path. |
| **PNP_VetoLegacyDriver** | A Windows service name. |

## See also

[CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew)

[CM_Query_And_Remove_SubTree_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtree_exw)

[CM_Request_Device_Eject](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_ejectw)

[CM_Request_Device_Eject_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_request_device_eject_exw)