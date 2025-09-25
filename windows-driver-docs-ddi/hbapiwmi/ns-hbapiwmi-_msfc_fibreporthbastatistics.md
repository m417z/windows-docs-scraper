# _MSFC_FibrePortHBAStatistics structure

## Description

The MSFC_FibrePortHBAStatistics structure is used by an HBA miniport driver that is a WMI provider to report statistics related to a fibre channel port.

## Members

### `UniquePortId`

Contains a unique identifier for the port.

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `Statistics`

Contains a structure of type [MSFC_HBAPortStatistics](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportstatistics) with statistical information about the port.

## See also

[MSFC_FibrePortHBAStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-fibreporthbastatistics-wmi-class)