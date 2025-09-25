# VDS_ISCSI_LOGIN_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for specifying iSCSI target login options.

## Constants

### `VDS_ILF_REQUIRE_IPSEC:0x1`

Reserved for future use.

### `VDS_ILF_MULTIPATH_ENABLED:0x2`

If this flag is set, the login is allowed to proceed and create a new login session even if there is already a login session to the target.

**Note** Multipathing software must be present or else data corruption may occur.

## Remarks

**Note** Additional constants might be added to the **VDS_ISCSI_LOGIN_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ISCSI_LOGIN_FLAG** enumeration constant.

## See also

[IVdsIscsiInitiatorAdapter::LoginToTarget](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-logintotarget)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)