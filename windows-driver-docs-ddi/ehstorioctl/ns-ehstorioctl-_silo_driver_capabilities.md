# _SILO_DRIVER_CAPABILITIES structure

## Description

This structure is used to specify the capabilities and support for IOCTL redirection of a storage silo driver. **SILO_DRIVER_CAPABILITIES** is included in the system buffer of an [IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities) request.

## Members

### `StructSize`

The size of this structure. This is set to **sizeof**(SILO_DRIVER_CAPABILITIES).

### `Capabilities`

Capability flags for the silo driver. This is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **CAP_ON_DEMAND_AUTHENTICATION** | The silo driver supports on-demand authentication and unauthentication. |
| **CAP_BANDING_SUPPORT** | The silo driver supports banding of LBA ranges. |

### `MaxLbaFilterCount`

Maximum number of LBA filter entries the silo driver can provide in an [IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table) request.

### `RedirectedIoctlListCount`

The number of redirected IOCTLs in the list following this structure.

### `RedirectedIoctlListOffset`

The offset of the redirected IOCTL list from the beginning of this structure. This will typically be **sizeof**(SILO_DRIVER_CAPABILITIES).

## Remarks

To support receiving [IOCTL_EHSTOR_DRIVER_PERFORM_AUTHZ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_perform_authz) from the enhanced storage class driver, a silo driver must set **CAP_ON_DEMAND_AUTHENTICATION** in **Capabilities**. Also, to support sending [IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table), a silo driver must set **CAP_BANDING_SUPPORT** in **Capabilities**.

To receive band management requests from the enhanced storage class driver, a silo driver must register a list of IOCTL codes it wants to receive. The redirected IOCTL list is an array of **ULONG** IOCTL codes with a length of **RedirectedIoctlListCount**. This list is included with the **SILO_DRIVER_CAPABILITIES** structure in the system buffer. The list is located in the system buffer following **SILO_DRIVER_CAPABILITIES** at the offset indicated by **RedirectedIoctlListOffset**.

## See also

[IOCTL_EHSTOR_DRIVER_PERFORM_AUTHZ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_perform_authz)

[IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_report_capabilities)

[IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_driver_update_lba_filter_table)