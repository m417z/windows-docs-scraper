# SRV_INSTANCE_TYPE enumeration

## Description

The **SRV_INSTANCE_TYPE** enumeration type describes the SRV instance type for an [SRV_OPEN_ECP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_srv_open_ecp_context).

## Constants

### `SrvInstanceTypeUndefined`

The SRV instance type is undefined.

### `SrvInstanceTypePrimary`

The open request came from a primary instance of SRV with user-facing shares.

### `SrvInstanceTypeCsv`

The open request came from an internal instance of SRV used by CSVFS.

### `SrvInstanceTypeSBL`

The open request came from an internal instance of SRV used by S2D at Software Layer Bus (SBL).

### `SrvInstanceTypeSR`

The open request came from an internal instance of SRV used by Storage Replica.

### `SrvInstanceTypeVSMB`

The open request came from an internal instance of SRV used by Hyper-V over SMB.

## See also

[SRV_OPEN_ECP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_srv_open_ecp_context)