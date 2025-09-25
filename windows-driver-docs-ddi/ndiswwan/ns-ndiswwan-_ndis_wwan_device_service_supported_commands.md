# _NDIS_WWAN_DEVICE_SERVICE_SUPPORTED_COMMANDS structure

## Description

The NDIS_WWAN_DEVICE_SERVICE_SUPPORTED_COMMANDS structure represents a list of commands supported by a device service.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_DEVICE_SERVICE_SUPPORTED_COMMANDS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_DEVICE_SERVICE_SUPPORTED_COMMANDS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_DEVICE_SERVICE_SUPPORTED_COMMANDS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the device services command enumeration operation.

### `SupportedCommands`

 A formatted WWAN_LIST_HEADER object that represents the list of command supported on a device services.

This member points to the list of the command ID (ULONG) by using the WWAN_LIST_HEADER structure.