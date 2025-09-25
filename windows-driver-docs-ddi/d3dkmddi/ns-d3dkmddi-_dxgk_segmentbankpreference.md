# _DXGK_SEGMENTBANKPREFERENCE structure

## Description

The **DXGK_SEGMENTBANKPREFERENCE** structure describes bank preferences for paging in an allocation.

## Members

### `Bank0` [out]

The identifier of the highest priority preferred bank, or 0 if no preference is required. Valid values are from 1 to 127.

This member is equivalent to the first 7 bits of the 32-bit **Value** member (0x0000007F).

### `Direction0` [out]

The direction in which **Bank0** should be scanned to locate a free area of memory. A value of 0 indicates a bottom-up search (that is, low address to high address), and a value of 1 indicates a top-bottom search (that is, high address to low address).

This member is equivalent to the eighth bit of the 32-bit **Value** member (0x00000080).

### `Bank1` [out]

The identifier of the next highest priority preferred bank, or 0 if no preference is required. Valid values are from 1 to 127.

This member is equivalent to bits 9 through 15 of the 32-bit **Value** member (0x00007F00).

### `Direction1` [out]

The direction in which **Bank1** should be scanned to locate a free hole of memory. A value of 0 indicates a bottom-up search (that is, low address to high address), and a value of 1 indicates a top-bottom search (that is, high address to low address).

This member is equivalent to the sixteenth bit of the 32-bit **Value** member (0x00008000).

### `Bank2` [out]

The identifier of the next highest priority preferred bank, or 0 if no preference is required. Valid values are from 1 to 127.

This member is equivalent to bits 17 through 23 of the 32-bit **Value** member (0x007F0000).

### `Direction2` [out]

The direction in which **Bank2** should be scanned to locate a free hole of memory. A value of 0 indicates a bottom-up search (that is, low address to high address), and a value of 1 indicates a top-bottom search (that is, high address to low address).

This member is equivalent to the twenty-fourth bit of the 32-bit **Value** member (0x00800000).

### `Bank3` [out]

The identifier of the next highest priority preferred bank, or 0 if no preference is required. Valid values are from 1 to 127.

This member is equivalent to bits 25 through 31 of the 32-bit **Value** member (0x7F000000).

### `Direction3` [out]

The direction in which **Bank3** should be scanned to locate a free hole of memory. A value of 0 indicates a bottom-up search (that is, low address to high address), and a value of 1 indicates a top-bottom search (that is, high address to low address).

This member is equivalent to the thirty-secondbit of the 32-bit **Value** member (0x80000000).

### `Value` [out]

A member in the union that DXGK_SEGMENTBANKPREFERENCE contains that can hold a 32-bit value that identifies bank preferences.

## Remarks

The display miniport driver can indicate up to four bank preferences in the **HintedBank** member of a [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure when the driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function is called. Preferred-bank identifiers are one-based (that is, the first bank has an identifier of one). An identifier of zero indicates that the driver has no preference. The highest priority preference is specified in the **Bank0** member; the lowest priority preference is specified in the **Bank3** member. The driver can specify less than four preferences by setting the lower priority preferences of bank identifiers to zero. For example, the driver can specify two preferences by setting **Bank0** and **Bank1** to valid identifiers and **Bank2** and **Bank3** to zero. The driver can use each **Direction***X* member to specify the scanning direction for each bank preference independently.

 The video memory manager allocates resources from preferred segments that the **PreferredSegment** member of DXGK_ALLOCATIONINFO specifies.

## See also

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DXGK_SEGMENTPREFERENCE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562047(v=vs.85))

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)