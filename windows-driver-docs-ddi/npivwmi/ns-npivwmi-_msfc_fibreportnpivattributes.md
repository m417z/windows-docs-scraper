# _MSFC_FibrePortNPIVAttributes structure

## Description

The MSFC_FibrePortNPIVAttributes structure contains attribute information for the virtual ports on an adapter.

## Members

### `WWPN`

The world wide port name of the physical port.

### `WWNN`

The world wide node name of the physical port.

### `NumberVirtualPorts`

The number of virtual ports on the adapter.

### `VirtualPorts`

An array of virtual ports. The array length is specified in the **NumberVirtualPorts** member.

## See also

[MSFC_FibrePortNPIVAttributes WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-fibreportnpivattributes-wmi-class)