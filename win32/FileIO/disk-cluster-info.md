# DISK\_CLUSTER\_INFO structure

Represents information maintained on the partition manager about a disk that is part of a cluster.

## Members

**Version**

The version number. This value must be set to the size of this structure.

**Flags**

A combination of flags related to disks and clusters.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| **DISK\_CLUSTER\_FLAG\_ENABLED**

1 | The disk is used as part of the cluster service.\ | | **DISK\_CLUSTER\_FLAG\_CSV**

2 | Volumes on the disk are exposed by CSVFS on all nodes of the cluster.\ | | **DISK\_CLUSTER\_FLAG\_IN\_MAINTENANCE**

4 | The cluster resource associated with this disk is in maintenance mode.\ | | **DISK\_CLUSTER\_FLAG\_PNP\_ARRIVAL\_COMPLETE**

8 | The cluster disk driver for kernel mode (clusdisk) has received PnP notification of the arrival of the disk.\ |

**FlagsMask**

The flags that are being modified in the **Flags** member.

**Notify**

**TRUE** to send a layout change notification; otherwise, **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ntdddisk.h |

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/win32/fileio/disk-management-structures)

[**IOCTL\_DISK\_GET\_CLUSTER\_INFO**](https://learn.microsoft.com/windows/win32/fileio/ioctl-disk-get-cluster-info)

[**IOCTL\_DISK\_SET\_CLUSTER\_INFO**](https://learn.microsoft.com/windows/win32/fileio/ioctl-disk-set-cluster-info)

