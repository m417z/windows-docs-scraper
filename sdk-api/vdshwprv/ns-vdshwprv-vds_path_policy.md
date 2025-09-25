# VDS_PATH_POLICY structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
load balance policy as it applies to a particular path.

## Members

### `pathId`

The ID of the path used by MPIO.

### `bPrimaryPath`

If set, indicates that the path is a primary path for MPIO.

### `ulWeight`

The weight assigned to the path. This is only relevant if the load balance policy for the LUN is
**VDS_LBP_WEIGHTED_PATHS**.

## See also

[IVdsLunMpio::GetLoadBalancePolicy](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-getloadbalancepolicy)

[IVdsLunMpio::SetLoadBalancePolicy](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-setloadbalancepolicy)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)