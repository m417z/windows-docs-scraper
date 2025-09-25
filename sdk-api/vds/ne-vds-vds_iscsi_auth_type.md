# VDS_ISCSI_AUTH_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for authentication when logging into an iSCSI target.

## Constants

### `VDS_IAT_NONE:0`

No authentication is performed.

### `VDS_IAT_CHAP:1`

One-way CHAP authentication is performed (target authenticates initiator). The target CHAP secret must be
specified during login.

### `VDS_IAT_MUTUAL_CHAP:2`

Mutual CHAP authentication is performed (target authenticates initiator and initiator authenticates
target). The target CHAP secret must be specified and the initiator CHAP secret must also have been set.

## Remarks

**Note** Additional constants might be added to the **VDS_ISCSI_AUTH_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ISCSI_AUTH_TYPE** enumeration constant.

## See also

[IVdsIscsiInitiatorAdapter::LoginToTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-logintotarget)