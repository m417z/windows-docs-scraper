# _NDIS_WWAN_DEVICE_CAPS structure

## Description

The NDIS_WWAN_DEVICE_CAPS structure represents the capabilities of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DEVICE_CAPS structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Windows 8 miniport drivers that follow the NDIS 6.30 specification should set this to NDIS_WWAN_DEVICE_CAPS_REVISION_2. Windows 7 miniport drivers that follow the NDIS 6.20 specification should set this to NDIS_WWAN_DEVICE_CAPS_REVISION_1. |
| Size | sizeof(NDIS_WWAN_DEVICE_CAPS) |

**Note** You must specify NDIS_WWAN_DEVICE_CAPS_REVISION_2 in **Revision** to use the Windows 8 members of [WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the device capabilities query. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_FAILURE | The operation failed to retrieve the capabilities for the device. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation when the ready-state is not **WwanReadyStateOff**. |

### `DeviceCaps`

A formatted
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps) object that represents
the capabilities of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)