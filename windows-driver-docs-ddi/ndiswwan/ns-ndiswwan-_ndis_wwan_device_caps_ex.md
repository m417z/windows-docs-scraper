# _NDIS_WWAN_DEVICE_CAPS_EX structure

## Description

The **NDIS_WWAN_DEVICE_CAPS_EX** structure represents the capabilities of the MB device. **NDIS_WWAN_DEVICE_CAPS_EX** extends the capability of the existing **NDIS_WWAN_DEVICE_CAPS** structure by changing its **WWAN_DEVICE_CAPS** structure to a **WWAN_DEVICE_CAPS_EX** structure.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_DEVICE_CAPS_EX** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Miniport drivers in Windows 10, version 1903 that support 5G set this to NDIS_WWAN_DEVICE_CAPS_EX_REVISION_2. Miniport drivers in earlier versions of Windows or that do not support 5G set this to NDIS_WWAN_DEVICE_CAPS_EX_REVISION_1. |
| Size | sizeof(NDIS_WWAN_DEVICE_CAPS_EX) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed to retrieve the capabilities for the device. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation when the ready-state is not **WwanReadyStateOff**. |

### `DeviceCaps`

A formatted
[WWAN_DEVICE_CAPS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps_ex) structure that has an **ExecutorIndex** member and Microsoft service extension member added to the existing [WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps) structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_caps)

[OID_WWAN_DEVICE_CAPS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-caps-ex)

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)

[WWAN_DEVICE_CAPS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps_ex)