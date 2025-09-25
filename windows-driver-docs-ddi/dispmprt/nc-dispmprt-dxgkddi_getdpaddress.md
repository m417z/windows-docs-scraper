# DXGKDDI_GETDPADDRESS callback function

## Description

The **DXGKDDI_GETDPADDRESS** callback queries the DisplayPort (DP) address of a monitor connected through DP.

## Parameters

### `Context`

Context pointer provided when querying the interface.

### `pArgs`

Pointer to a [**DXGKARG_GETDPADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdpaddress) structure.

## Return value

**DXGKDDI_GETDPADDRESS** returns STATUS_SUCCESS if it succeeds; otherwise it returns an error code.

## Remarks

**DXGKDDI_GETDPADDRESS** is both for developmental and validation purposes.

For **TargetId** of a monitor connected through DP, the driver should return its DP address in the form of **RootPortIndex**, **NumLinks**, and DP Relative Address in **RelAddress**. **NumLinks** should be 0 if the DP monitor is directly connected to the GPU; otherwise, it should be the number of links between the root port and target device. The format of the Relative Address in **RelAddress** should follow the DP spec.

## See also

[**DXGKARG_GETDPADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdpaddress)