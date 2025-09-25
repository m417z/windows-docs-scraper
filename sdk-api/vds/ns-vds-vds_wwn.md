# VDS_WWN structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a world-wide name (WWN). This
structure corresponds to the HBA_WWN structure defined by the ANSI HBA API.

## Members

### `rguchWwn`

An array of 8 bytes that together specify the 64-bit WWN value. The first element of the array is the most
significant byte of the WWN, with the most significant bit of that byte being the most significant bit of the
WWN.

## See also

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_HBAPORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hbaport_prop)