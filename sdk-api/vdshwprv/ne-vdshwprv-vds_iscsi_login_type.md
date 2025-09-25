# VDS_ISCSI_LOGIN_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for logging into an iSCSI target.

## Constants

### `VDS_ILT_MANUAL:0`

A manual, one-time login is performed.

### `VDS_ILT_PERSISTENT:1`

A persistent login is performed.

### `VDS_ILT_BOOT:2`

A persistent login is performed such that the target is present at startup.

## Remarks

**Note** Additional constants might be added to the **VDS_ISCSI_LOGIN_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ISCSI_LOGIN_TYPE** enumeration constant.

## See also

[IVdsIscsiInitiatorAdapter::LoginToTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-logintotarget)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)