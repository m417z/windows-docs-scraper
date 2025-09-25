# _NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE structure

## Description

The NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE structure represents device service session data to be sent from the host to the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `WriteData`

The data to be sent to the MB device.

## See also

[WWAN_DEVICE_SERVICE_SESSION_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_session_write)