# VDS_LOADBALANCE_POLICY_ENUM enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a set of valid load balance policies for a path. These policies correspond to the
definitions in the DSM MOF.

## Constants

### `VDS_LBP_UNKNOWN:0`

The policy is unknown.

### `VDS_LBP_FAILOVER:1`

The policy uses one primary path with other paths being backup paths.

### `VDS_LBP_ROUND_ROBIN:2`

The policy uses all paths in round-robin fashion.

### `VDS_LBP_ROUND_ROBIN_WITH_SUBSET:3`

The policy uses primary paths in round-robin fashion. The backup paths are used if all of the primary paths
fail.

### `VDS_LBP_DYN_LEAST_QUEUE_DEPTH:4`

The policy uses the path with the least number of active requests.

### `VDS_LBP_WEIGHTED_PATHS:5`

The policy uses the path with the least weight (each path is assigned a weight).

### `VDS_LBP_LEAST_BLOCKS:6`

The policy uses the path with the least blocks.

### `VDS_LBP_VENDOR_SPECIFIC:7`

The policy is a vendor-specific policy.

## Remarks

**Note** Additional constants might be added to the **VDS_LOADBALANCE_POLICY_ENUM** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LOADBALANCE_POLICY_ENUM** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)