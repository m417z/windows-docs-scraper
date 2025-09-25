# RepairInfoEx structure

## Description

Contains detailed repair information that can be used to help resolve the root cause of an incident.

## Members

### `repair`

Type: **[RepairInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfo)**

The detailed repair information.

### `repairRank`

Type: **USHORT**

The rank of the repair, relative to other repairs in the [RootCauseInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-rootcauseinfo) structure associated with the incident. A repair with rank 1 is expected to be more relevant to the problem and thus will be the first repair to be attempted. The success of any individual repair is not guaranteed, regardless of its rank.

## See also

[FreeRepairInfoExs](https://learn.microsoft.com/windows/desktop/NDF/freerepairinfoexs)

[RepairInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfo)

[RootCauseInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-rootcauseinfo)