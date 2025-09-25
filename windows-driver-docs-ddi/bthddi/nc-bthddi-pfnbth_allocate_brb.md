# PFNBTH_ALLOCATE_BRB callback function

## Description

The
*BthAllocateBrb* function allocates a Bluetooth request block (BRB) of the specified type.

## Parameters

### `brbType` [in]

Specifies a value from the
[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type) enumeration to initialize the BRB
with.

### `tag` [in]

Specifies a 4-byte
pool tag that uniquely identifies the driver that does the memory
allocation. For more information about pool tags, see
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Return value

*BthAllocateBrb* returns a pointer to the newly allocated BRB, or **NULL** if the system is out of
memory.

## Remarks

Profile drivers obtain a pointer to the
*BthAllocateBrb* function when they query the Bluetooth driver stack for an instance of the
BTHDDI_PROFILE_DRIVER_INTERFACE driver interface. See
[Querying for Bluetooth
Interfaces](https://learn.microsoft.com/previous-versions/ff536769(v=vs.85)) for more information about querying the Bluetooth driver stack.

## See also

[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

pool tag