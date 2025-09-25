# RootCauseInfo structure

## Description

Contains detailed information about the root cause of an incident.

## Members

### `pwszDescription`

Type: **LPWSTR**

A string that describes the problem that caused the incident.

### `rootCauseID`

Type: **GUID**

The GUID that corresponds to the problem identified.

### `rootCauseFlags`

Type: **DWORD**

A numeric value that provides more information about the problem.

| Value | Meaning |
| --- | --- |
| **RCF_ISLEAF**<br><br>0x1 | The root cause corresponds to a leaf in the diagnostics tree. Root causes that are leafs are more likely to be closer to the problem that the user is trying to diagnose. |
| **RCF_ISCONFIRMED**<br><br>0x2 | The root cause corresponds to a node with a [DIAGNOSIS_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-diagnosis_status) value of **DS_CONFIRMED**. Problems with confirmed low health are more likely to correspond to the problem the user is trying to diagnose. |
| **RCF_ISTHIRDPARTY**<br><br>0x4 | The root cause comes from a third-party helper class extension rather than a native Windows helper class. |

### `networkInterfaceID`

Type: **GUID**

GUID of the network interface on which the problem occurred. If the problem is not interface-specific, this value is zero (0).

### `pRepairs`

Type: **[RepairInfoEx](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfoex)***

The repairs that are available to try and fix the problem.

### `repairCount`

Type: **USHORT**

The number of repairs available.

## See also

[CopyRootCauseInfo](https://learn.microsoft.com/windows/desktop/NDF/copyrootcauseinfo)

[DIAGNOSIS_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-diagnosis_status)

[FreeRootCauseInfos](https://learn.microsoft.com/windows/desktop/NDF/freerootcauseinfos)

[RepairInfoEx](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfoex)