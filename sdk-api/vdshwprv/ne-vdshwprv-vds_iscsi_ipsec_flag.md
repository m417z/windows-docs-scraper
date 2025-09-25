# VDS_ISCSI_IPSEC_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Not supported.

This enumeration is reserved for future use.

## Constants

### `VDS_IIF_VALID:0x1`

This bit must be set for the field to contain significant information.

### `VDS_IIF_IKE:0x2`

If set, IKE/IPSEC is enabled.

### `VDS_IIF_MAIN_MODE:0x4`

If set, negotiate through main mode is enabled.

### `VDS_IIF_AGGRESSIVE_MODE:0x8`

If set, negotiate through aggressive mode is enabled.

### `VDS_IIF_PFS_ENABLE:0x10`

If set, perfect forward secrecy is enabled.

### `VDS_IIF_TRANSPORT_MODE_PREFERRED:0x20`

If set, transport mode is preferred.

### `VDS_IIF_TUNNEL_MODE_PREFERRED:0x40`

If set, tunnel mode is preferred.

## Remarks

These flags are identical to the definitions for the iSNS portal security
bitmap.

**Note** Additional constants might be added to the **VDS_ISCSI_IPSEC_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ISCSI_IPSEC_FLAG** enumeration constant.