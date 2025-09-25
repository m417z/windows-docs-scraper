# _NDIS_WWAN_DEVICE_SERVICE_SESSION_READ structure

## Description

The NDIS_WWAN_DEVICE_SERVICE_SESSION_READ structure represents device service session data that has been read by the miniport driver from the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DEVICE_SERVICE_SESSION_READ
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DEVICE_SERVICE_SESSION_READ_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DEVICE_SERVICE_SESSION_READ) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ReadData`

The data that has been read from a device service session.

## See also

[WWAN_DEVICE_SERVICE_SESSION_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_session_read)