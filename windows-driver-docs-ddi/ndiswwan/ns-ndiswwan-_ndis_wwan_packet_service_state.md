# _NDIS_WWAN_PACKET_SERVICE_STATE structure

## Description

The NDIS_WWAN_PACKET_SERVICE_STATE structure represents the packet service attachment state of the MB
device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PACKET_SERVICE_STATE
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Windows 10, version 1903 miniport drivers that support 5G set this to NDIS_WWAN_PACKET_SERVICE_STATE_REVISION_2. Miniport drivers that do not support 5G or that are for earlier versions of Windows set this to NDIS_WWAN_PACKET_SERVICE_STATE_REVISION_1. |
| Size | sizeof(NDIS_WWAN_PACKET_SERVICE_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

A miniport driver must set this to WWAN_STATUS_SUCCESS for unsolicited events
(NDIS_STATUS_INDICATION::RequestId = 0).

WWAN_STATUS_SUCCESS is also set for successful execution of
*set* and
*query* requests.

WWAN_STATUS_SUCCESS should be returned by the miniport driver, if the requested state and the current
state are same for a
*set* request.

The following table shows the other possible error status codes.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_PIN_REQUIRED | Device requires PIN value input. |
| WWAN_STATUS_FAILURE | Unable to get or set packet service state. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_SIM_NOT_INSERTED | The operation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |

Miniport drivers can return the error codes (in addition to the above listed) shown in the following
table in the event that a packet-attach
*set* request fails.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_FAILURE | Packet-attach or packet-detach has failed. More information is set at **uNwError** member of WWAN_PACKET_SERVICE structure. For other WWAN_STATUS_XXX errors, **uNwError** should be set to zero. |
| WWAN_STATUS_SERVICE_NOT_ACTIVATED | The device does not allow setting packet service state because of service activation failure or expired subscription. |
| WWAN_STATUS_PROVIDER_NOT_VISIBLE | Provider is not visible for packet service operations. |
| WWAN_STATUS_NOT_REGISTERED | The device is not in registered state to perform a packet-attach operation. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | SET packet service is not supported by this CDMA-based device. |
| WWAN_STATUS_RADIO_POWER_OFF | Unable to packet-attach because the radio is turned off. |
| WWAN_STATUS_SIM_NOT_INSERTED | A SIM card is not inserted. |
| WWAN_STATUS_BAD_SIM | A bad SIM card is detected. |

### `PacketService`

A formatted
[WWAN_PACKET_SERVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_packet_service) object that
represents the packet service attachment state of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_PACKET_SERVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_packet_service)