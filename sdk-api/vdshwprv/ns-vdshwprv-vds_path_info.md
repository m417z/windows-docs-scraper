# VDS_PATH_INFO structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
information for a LUN path. This structure is returned in the *ppPaths* parameter of the [IVdsLunMpio::GetPathInfo](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-getpathinfo) method.

## Members

### `pathId`

The unique ID of the path used by MPIO.

### `type`

The type of interconnect that the hardware provider supports for this LUN path. [VDS_HWT_HYBRID](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type) is not a valid value for this member, even if the provider is a hybrid provider.

### `status`

The status of the path, enumerated by
[VDS_PATH_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_path_status).

### `controllerPortId`

The **VDS_OBJECT_ID** of the controller port object on the other end of the
path.

### `targetPortalId`

The **VDS_OBJECT_ID** of the target portal object on the other end of the
path.

### `hbaPortId`

The **VDS_OBJECT_ID** of the HBA port.

### `initiatorAdapterId`

The **VDS_OBJECT_ID** of the initiator adapter.

### `pHbaPortProp`

A pointer to a [VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop) structure
containing properties of the HBA port on one end of the path.

### `pInitiatorPortalIpAddr`

A pointer to a [VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress) structure containing
the IP address and port information for the initiator portal.

## See also

[IVdsLunMpio::GetPathInfo](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunmpio-getpathinfo)

[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop)

[VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type)

[VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress)

[VDS_PATH_ID](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_id)

[VDS_PATH_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_path_status)