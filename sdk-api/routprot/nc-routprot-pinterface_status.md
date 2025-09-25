# PINTERFACE_STATUS callback function

## Description

Router manager calls the
**InterfaceStatus** function to change the status of an interface.

The [PINTERFACE_STATUS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *InterfaceStatus* is a placeholder for the application-defined function name.

## Parameters

### `InterfaceIndex` [in]

Specifies the index of the interface to change.

### `InterfaceActive` [in]

Specifies whether the interface is active.

### `StatusType` [in]

Specifies the new interface status. This parameter is one of the following values.

RIS_INTERFACE_ADDRESS_CHANGE

RIS_INTERFACE_ENABLED

RIS_INTERFACE_DISABLED

RIS_INTERFACE_MEDIA_PRESENT

RIS_INTERFACE_MEDIA_ABSENT

### `StatusInfo` [in]

Pointer to a structure that specifies information appropriate to the type of interface status type. For example, if the *StatusType* parameter specifies an address change, the *StatusInfo* parameter points to a structure that contains the new address information, such as
[IP_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_adapter_binding_info). This parameter may be **NULL**.

## Return value

If the function succeeds, the return value should be NO_ERROR.

If the function fails, the return value should be one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Unspecified failure. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index). |

## See also

[AddInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-padd_interface)

[DeleteInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdelete_interface)