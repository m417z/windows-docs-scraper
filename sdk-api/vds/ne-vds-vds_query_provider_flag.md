# VDS_QUERY_PROVIDER_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for provider query operations. Callers can query for hardware providers, software providers, or both.

## Constants

### `VDS_QUERY_SOFTWARE_PROVIDERS:0x1`

If set, the operation queries for software providers.

### `VDS_QUERY_HARDWARE_PROVIDERS:0x2`

If set, the operation queries for hardware providers.

### `VDS_QUERY_VIRTUALDISK_PROVIDERS:0x4`

If set, the operation queries for virtual disk providers.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

## Remarks

This enumeration provides the value for the *masks* parameter of the [IVdsService::QueryProviders](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryproviders) method. You can specify more than one value in the same query. For example, to query for software and hardware providers, specify both VDS_QUERY_SOFTWARE_PROVIDERS and VDS_QUERY_HARDWARE_PROVIDERS in the *masks* parameter.

**Note** Additional constants might be added to the **VDS_QUERY_PROVIDER_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_QUERY_PROVIDER_FLAG** enumeration constant.

## See also

[IVdsService::QueryProviders](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryproviders)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)