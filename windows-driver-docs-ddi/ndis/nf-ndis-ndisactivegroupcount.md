# NdisActiveGroupCount function

## Description

The
**NdisActiveGroupCount** function returns the number of processor groups that are currently active in the
local computer system.

## Return value

**NdisActiveGroupCount** returns a USHORT value for the number of processor groups that are currently
active and are included in the local computer system. The number of groups is a zero-based value.

## Remarks

NDIS drivers call the
**NdisActiveGroupCount** function to obtain the number of processor groups that are currently active
and are included in the local computer system.

To obtain the maximum number of groups, call the
[NdisMaxGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismaxgroupcount) function.

## See also

[NdisMaxGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismaxgroupcount)