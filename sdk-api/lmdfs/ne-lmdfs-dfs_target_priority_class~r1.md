# DFS_TARGET_PRIORITY_CLASS enumeration

## Description

Defines the set of possible DFS target priority class settings.

## Constants

### `DfsInvalidPriorityClass:-1`

The priority class is not valid.

### `DfsSiteCostNormalPriorityClass:0`

The middle or "normal" site cost priority class for a DFS target.

### `DfsGlobalHighPriorityClass`

The highest priority class for a DFS target. Targets assigned this class receive global preference.

### `DfsSiteCostHighPriorityClass`

The highest site cost priority class for a DFS target. Targets assigned this class receive the most preference among targets of the same site cost for a given DFS client.

### `DfsSiteCostLowPriorityClass`

The lowest site cost priority class for a DFS target. Targets assigned this class receive the least preference among targets of the same site cost for a given DFS client.

### `DfsGlobalLowPriorityClass`

The lowest level of priority class for a DFS target. Targets assigned this class receive the least preference globally.

## Remarks

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
normal, and low priority classes. Then, all server targets with lower site costs are likewise separated into
site-cost high, normal, and low priority classes. Thus, a server target with a site-cost value of 0 and a
site-cost low priority class is still ranked higher than a server target with a site-cost value of 1 and
site-cost high priority class.

For more information about how server target priority is determined, see
[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization).

## See also

[DFS Server Target Prioritization](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/dfs-server-target-prioritization)