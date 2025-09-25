# _NDIS_WWAN_DEVICE_SET_SERVICE_SESSION structure

## Description

The NDIS_WWAN_SET_DEVICE_SERVICE_SESSION structure represents a session state operation to be performed on a device service.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_DEVICE_SERVICE_SESSION
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_DEVICE_SERVICE_SESSION_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_DEVICE_SERVICE_SESSION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `Session`

The requested session state set operation.

## See also

[WWAN_DEVICE_SERVICE_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_session)