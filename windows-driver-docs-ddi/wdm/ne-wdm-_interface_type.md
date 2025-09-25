# _INTERFACE_TYPE enumeration (wdm.h)

## Description

The **INTERFACE_TYPE** enumeration indicates the bus type.

## Constants

### `InterfaceTypeUndefined`

Indicates that the interface type is undefined.

### `Internal`

For internal use only.

### `Isa`

Indicates that the interface is published by the ISA bus driver.

### `Eisa`

Indicates that the interface is published by the EISA bus driver.

### `MicroChannel`

Indicates that the interface is published by the MicroChannel bus driver.

### `TurboChannel`

Indicates that the interface is published by the TurboChannel bus driver.

### `PCIBus`

Indicates that the interface is published by the PCI bus driver.

### `VMEBus`

Indicates that the interface is published by the VME bus driver.

### `NuBus`

Indicates that the interface is published by the NuBus driver.

### `PCMCIABus`

Indicates that the interface is published by the PCMCIA bus driver.

### `CBus`

Indicates that the interface is published by the Cbus driver.

### `MPIBus`

Indicates that the interface is published by the MPI bus driver.

### `MPSABus`

Indicates that the interface is published by the MPSA bus driver.

### `ProcessorInternal`

Indicates that the interface is published by the ISA bus driver.

### `InternalPowerBus`

Indicates that the interface is published for an internal power bus. Some devices have power control ports that allow them to share power control with other devices. The Windows architecture represents these devices as slots on a virtual bus called an "internal power bus."

### `PNPISABus`

Indicates that the interface is published by the PNPISA bus driver.

### `PNPBus`

Indicates that the interface is published by the PNP bus driver.

### `Vmcs`

Reserved for use by the operating system.

### `ACPIBus`

Indicates that the interface is published by the ACPI bus driver. The ACPI bus driver enumerates devices that are described in the ACPI firmware of the hardware platform. These devices might physically reside on buses that are controlled by other bus drivers, but the ACPI bus driver must enumerate these devices because the other bus drivers cannot detect them. This interface type is defined starting with Windows 8.

### `MaximumInterfaceType`

Marks the upper limit of the possible bus types.

## See also

[HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data)

[PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information)

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)

[ScsiPortValidateRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportvalidaterange)

[StorPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase)

[StorPortValidateRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportvalidaterange)