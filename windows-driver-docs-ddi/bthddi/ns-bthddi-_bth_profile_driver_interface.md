# _BTH_PROFILE_DRIVER_INTERFACE structure

## Description

The BTH_PROFILE_DRIVER_INTERFACE structure provides functions to allocate, free, initialize, and
reuse BRBs, and to determine the currently installed Bluetooth version.

## Members

### `Interface`

A structure that describes the
**BTH_PROFILE_DRIVER_INTERFACE** interface for use by profile drivers. For more information about this
structure, see
[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `BthAllocateBrb`

Pointer to the
[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb) function.

### `BthFreeBrb`

Pointer to the
[BthFreeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_free_brb) function.

### `BthInitializeBrb`

Pointer to the
[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb) function.

### `BthReuseBrb`

Pointer to the
[BthReuseBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_reuse_brb) function.

### `IsBluetoothVersionAvailable`

Pointer to the
[IsBluetoothVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_is_bluetooth_version_available) function.

## Remarks

Profile drivers should specify the
**GUID_BTHDDI_PROFILE_DRIVER_INTERFACE** GUID to query for an instance of the
BTH_PROFILE_DRIVER_INTERFACE structure from the Bluetooth driver stack.

All the members of this structure, other than the
**Interface** member, are function pointers.

## See also

[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb)

[BthFreeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_free_brb)

[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb)

[BthReuseBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_reuse_brb)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IsBluetoothVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_is_bluetooth_version_available)