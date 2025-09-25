# NVME_SCSI_NAME_STRING structure

## Description

Contains information that is used to construct the SCSI name string identifier.

The SCSI name string identifier is used for the descriptor in NVMe to SCSI translation for NVMe devices compliant with revision 1.0.

## Members

### `PCIVendorID`

The company vendor identifier that is assigned by the [Peripheral Component Interconnect - Special Interest Group (PCI-SIG)](https://pcisig.com/).

This value is also in the **VID** field of the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `ModelNumber`

The model number for the NVM subsystem that is assigned by the vendor as an ASCII string.

This value is also in the **MN** field of the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `NamespaceID`

The namespace identifier.

This value is also in the **NSID** field of the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

### `SerialNumber`

The serial number for the NVM subsystem that is assigned by the vendor as an ASCII string.

This value is also in the **SN** field of the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

## Remarks

## See also

- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)
- [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)