# VDS_SERVICE_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of the [service object](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects).

## Members

### `pwszVersion`

The version of VDS; a zero-terminated, human-readable string.

### `ulFlags`

A bitmask of [VDS_SERVICE_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_service_flag) enumeration values that describe the service.

## Remarks

 The [IVdsService::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getproperties) method returns this structure to report the properties of the [service object](https://learn.microsoft.com/windows/desktop/VDS/startup-and-service-objects).

## See also

[IVdsService::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)