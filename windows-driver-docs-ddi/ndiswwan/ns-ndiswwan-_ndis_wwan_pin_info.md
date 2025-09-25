# _NDIS_WWAN_PIN_INFO structure

## Description

The NDIS_WWAN_PIN_INFO structure represents the type and PIN-entry state of Personal Identification
Number (PIN) information required by the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PIN_INFO structure. The
MB Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PIN_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PIN_INFO) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the PIN info operation. The following table shows the possible values for this
member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Pin info operation succeeded. |
| WWAN_STATUS_SIM_NOT_INSERTED | Pin info operation failed because the SIM card is not inserted. |
| WWAN_STATUS_FAILURE | Pin info operation failed. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |
| WWAN_STATUS_PIN_DISABLED | The operation failed because the PIN is disabled. |
| WWAN_STATUS_PIN_REQUIRED | The operation failed because a PIN must be entered to proceed. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because a *set* on a corresponding PIN type is not supported by the device. |

### `PinInfo`

A formatted
[WWAN_PIN_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_info) object that represents the type
and PIN-entry state of Personal Identification Number (PIN) information required by the device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_PIN_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_info)