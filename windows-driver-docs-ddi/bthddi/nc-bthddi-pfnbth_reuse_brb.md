# PFNBTH_REUSE_BRB callback function

## Description

The
*BthReuseBrb* function reinitializes a Bluetooth request block (BRB) to be reused.

## Parameters

### `pBrb` [in, out]

Pointer to the BRB to reuse.

### `brbType` [in]

Specifies a value from the
[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type) enumeration to initialize the BRB
with.

## Remarks

Profile drivers obtain a pointer to the
*BthReuseBrb* function when they query the Bluetooth driver stack for an instance of the
BTHDDI_PROFILE_DRIVER_INTERFACE driver interface. See
[Querying for Bluetooth
Interfaces](https://learn.microsoft.com/previous-versions/ff536769(v=vs.85)) for more information about querying the Bluetooth driver stack.

## See also

[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type)