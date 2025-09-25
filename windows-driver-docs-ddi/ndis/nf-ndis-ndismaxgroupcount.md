# NdisMaxGroupCount function

## Description

The
**NdisMaxGroupCount** function returns the maximum number of processor groups in the local computer
system.

## Return value

**NdisMaxGroupCount** returns a USHORT value for the maximum number of processor groups that are
included in the local computer system. The number of groups is a zero-based value.

## Remarks

NDIS drivers call the
**NdisMaxGroupCount** function to obtain the maximum number of processor groups that are included in
the local computer system.

To obtain the number of groups that are currently active, call the
[NdisActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisactivegroupcount) function.

## See also

[NdisActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisactivegroupcount)