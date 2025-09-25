# _PORT_CONFIGURATION_INFORMATION structure (strmini.h)

## Description

PORT_CONFIGURATION_INFORMATION describes the hardware settings of a streaming minidriver's device. The class driver fills in most members with information provided by the operating system.

## Members

### `SizeOfThisPacket`

The size of this structure, in bytes. The class driver fills in this member.

### `HwDeviceExtension`

Pointer to the minidriver's device extension. The minidriver may use this buffer to record private information global to the minidriver. The minidriver sets the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver also passes pointers to this buffer in the **HwDeviceExtension** member of the [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), and [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) structures it passes to the minidriver.

### `ClassDeviceObject`

Points to the class-driver-provided functional device object (FDO) for the driver's device.

### `PhysicalDeviceObject`

Points to the device object for the driver at the top of the driver stack when the class driver attaches to the driver stack. Drivers use this member when calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) to communicate with the driver stack. The **RealPhysicalDeviceObject** member points to the actual PDO for the driver's device.

### `SystemIoBusNumber`

The class driver fills in this member with the system bus ID number of the device. Bus 0 is the primary system bus.

### `AdapterInterfaceType`

Specifies the type of system bus the device is connected to. Possible values include **Isa**, **Eisa**, **MicroChannel**, **PCIBus**, and **PCMCIABus**.

### `BusInterruptLevel`

The class driver fills in this member with the IRQL for interrupts on this bus.

### `BusInterruptVector`

The class driver fills in this member with the interrupt vector used by the device.

### `InterruptMode`

The class driver fills in this member with the interrupt mode, either Latched or LevelSensitive.

### `DmaChannel`

If the device connects to the ISA bus, the class driver fills in this member with the DMA channel of the device.

### `NumberOfAccessRanges`

The number of entries in the **AccessRanges** array.

### `AccessRanges`

The number of entries in the **AccessRanges** array.

### `StreamDescriptorSize`

The minidriver fills in this member with the size of its [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure.

### `Irp`

Pointer to the PnP device start IRP that triggered this SRB_INITIALIZE_DEVICE request.

### `InterruptObject`

If the device uses interrupts, the class driver fills in this member with a pointer to the associated Interrupt object.

### `DmaAdapterObject`

If the device uses DMA, the class driver fills in this member with a pointer to the associated DmaAdapter object.

### `RealPhysicalDeviceObject`

Pointer to the PDO for the driver's device.

### `Reserved`

Reserved for system use. Do not use.

## Remarks

Most of the members of PORT_CONFIGURATION_INFORMATION provide information to the minidriver about its use of hardware resources, such as its interrupt vector and the IRQL for its interrupts.