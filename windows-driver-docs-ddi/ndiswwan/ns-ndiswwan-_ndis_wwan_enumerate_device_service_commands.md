# _NDIS_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS structure

## Description

The NDIS_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS structure represents the commands supported by a device service.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `DeviceServiceGuid`

The GUID of the device service for which commands should be enumerated.