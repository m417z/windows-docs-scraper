# PFNBTH_INITIALIZE_BRB callback function

## Description

The
*BthInitializeBrb* function initializes a Bluetooth request block (BRB) allocated on the local
stack.

## Parameters

### `pBrb` [in, out]

Pointer to the BRB to initialize.

### `brbType` [in]

Specifies a value from the
[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type) enumeration to initialize the BRB
with.

## Remarks

Profile drivers should use
*BthInitializeBrb* for stack based allocations, such as declaring variables at the beginning of a
function.

It is not necessary to call this function for a BRB that was allocated using
[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb).

Profile drivers obtain a pointer to the
*BthInitializeBrb* function when they query the Bluetooth driver stack for an instance of the
BTHDDI_PROFILE_DRIVER_INTERFACE driver interface. See
[Querying for Bluetooth
Interfaces](https://learn.microsoft.com/previous-versions/ff536769(v=vs.85)) for more information about querying the Bluetooth driver stack.

## See also

[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type)

[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb)