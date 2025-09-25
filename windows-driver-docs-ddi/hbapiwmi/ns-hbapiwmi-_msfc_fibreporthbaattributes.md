# _MSFC_FibrePortHBAAttributes structure

## Description

A WMI provider uses the MSFC_FibrePortHBAAttributes WMI class to expose attribute information associated with a fibre channel port.

## Members

### `UniquePortId`

Unique identifier for the port. This identifier must be unique among all ports on all adapters. The same value for the identifier must be used for the same port in other classes that expose port information.

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `Attributes`

Contains a structure of type [MSFC_HBAPortAttributesResults](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults) that contains information about the port attributes.

## See also

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[MSFC_HBAPortAttributesResults](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults)