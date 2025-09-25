# DFS_TARGET_PRIORITY structure

## Description

Contains the priority class and rank of a specific DFS target.

## Members

### `TargetPriorityClass`

[DFS_TARGET_PRIORITY_CLASS](https://learn.microsoft.com/windows/win32/api/lmdfs/ne-lmdfs-dfs_target_priority_class~r1) enumeration
value that specifies the priority class of the target.

### `TargetPriorityRank`

Specifies the priority rank value of the target. The default value is 0, which indicates the highest
priority rank within a priority class.

### `Reserved`

This member is reserved and must be zero.

## Remarks

This structure is used as the **TargetPriority** member of the
[DFS_INFO_104](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_104),
[DFS_INFO_106](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_106), and
[DFS_STORAGE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_storage_info_1) structures. There are no functions
that use this structure directly.

The order of priority classes from highest to lowest is as follows:

* **DfsGlobalHighPriorityClass**
* **DfsSiteCostHighPriorityClass**
* **DfsSiteCostNormalPriorityClass**
* **DfsSiteCostLowPriorityClass**
* **DfsGlobalLowPriorityClass**

Server targets are initially grouped into global high priority, normal priority, and low priority classes. The
normal priority class is then subdivided, based on Active Directory site cost, into site-cost high priority,
site-cost normal priority, and site-cost low priority classes.

For example, all of the server targets with a site-cost value of 0 are first grouped into site-cost high,
normal, and low priority classes. Then, all server targets with higher site costs are likewise separated into
site-cost high, normal, and low priority classes. Thus, a server target with a site-cost value of 0 and a
site-cost low priority class is still ranked higher than a server target with a site-cost value of 1 and site-cost
high priority class.

Note that the value for a "normal priority class" is set to 0 even though it is lower in priority than
**DfsGlobalHighPriorityClass** and **DfsSiteCostHighPriorityClass**. This is the default
setting for priority class. Priority rank can be used to discriminate within a priority class for added
granularity.

For more information about how server target priority is determined, see
[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization).

## See also

[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization)

[DFS_INFO_104](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_104)

[DFS_INFO_106](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_106)

[DFS_STORAGE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_storage_info_1)

[DFS_TARGET_PRIORITY_CLASS](https://learn.microsoft.com/windows/win32/api/lmdfs/ne-lmdfs-dfs_target_priority_class~r1)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsSetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfssetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)