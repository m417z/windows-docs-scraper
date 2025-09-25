# _HW_INITIALIZATION_DATA structure (srb.h)

## Description

Each SCSI miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine must initialize with zeros and, then, fill in the relevant HW_INITIALIZATION_DATA (SCSI) information for the OS-specific port driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `HwInitializationDataSize`

Specifies the size of this structure in bytes, as returned by **sizeof**(). In effect, this member indicates the version of this structure being used by the miniport driver. A miniport driver's **DriverEntry** routine should set this member's value for the port driver.

### `AdapterInterfaceType`

Specifies the type of I/O bus to which the HBA is connected, which can be one of the following: **Internal**, **Isa**, **Eisa**, **MicroChannel**, **TurboChannel**, or **PCIBus**. However, additional types of buses will be supported in future. The upper bound on the types of buses supported is always **MaximumInterfaceType**.

If this is set to **PCIBus**, the miniport driver must supply values for the **VendorIdLength**, **VendorId**, **DeviceIdLength**, and **DeviceId** members, described later.

### `HwInitialize`

Pointer to the miniport driver's [HwScsiInitialize](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557302(v=vs.85)) routine, which is a required entry point for all miniport drivers. The prototype for this routine is [PHW_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_initialize).

### `HwStartIo`

Pointer to the miniport driver's [HwScsiStartIo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557323(v=vs.85)) routine, which is a required entry point for all miniport drivers. The prototype for this routine is [PHW_STARTIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_startio).

### `HwInterrupt`

Pointer to the miniport driver's [HwScsiInterrupt](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557312(v=vs.85)) routine, which is a required entry point for any miniport driver of an HBA that generates interrupts. Set this to **NULL** if the miniport driver needs no ISR. The prototype for this routine is [PHW_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_interrupt).

### `HwFindAdapter`

Pointer to the miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine, which is a required entry point for all miniport drivers. The prototype for this routine is [PHW_FIND_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_find_adapter).

### `HwResetBus`

Pointer to the miniport driver's [HwScsiResetBus](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557318(v=vs.85)) routine, which is a required entry point for all miniport drivers. The prototype for this routine is [PHW_RESET_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_reset_bus).

### `HwDmaStarted`

Pointer to the miniport driver's [HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85)) routine if its HBA uses system DMA, that is, a system DMA controller. Set this to **NULL** if the HBA is a bus master or uses PIO. The prototype for this routine is [PHW_DMA_STARTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_dma_started).

### `HwAdapterState`

Pointer to the miniport driver's [HwScsiAdapterState](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557278(v=vs.85)) routine, which is a required entry point for miniport drivers of HBAs with BIOSs that are linked with an operating system-dependent, x86-platform-only port driver that must switch between x86 protected and real processor modes. If the miniport driver needs no *HwScsiAdapterState* routine, set this member to **NULL**. A miniport driver for an HBA that has a BIOS must have a HwScsiAdapterState routine in order to be compatible with the x86-only port driver and portable to an x86-only operating system environment. The prototype for this routine is [PHW_ADAPTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nc-srb-phw_adapter_state).

### `DeviceExtensionSize`

Specifies the size in bytes required by the miniport driver for its per-HBA device extension. A miniport driver uses its device extension as storage for driver-determined HBA information. The OS-specific port driver initializes each device extension it allocates with zeros, and passes a pointer to the HBA-specific device extension in every call to a miniport driver except to its **DriverEntry** routine. The given size does not include any miniport driver-requested per-logical-unit storage, described next.

### `SpecificLuExtensionSize`

Specifies the size in bytes required by the miniport driver for its per-logical-unit storage, if any. A miniport driver can use its LU extensions as storage for driver-determined logical-unit information about SCSI peripherals on the bus. The OS-specific port driver initializes each LU extension it allocates with zeros. Leave this member set to zero if the miniport driver does not maintain per-LU information for which it requires storage. This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as [ScsiPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetuncachedextension).

### `SrbExtensionSize`

Specifies the size in bytes required by the miniport driver for its per-request storage, if any. A miniport driver can use SRB extensions as storage for driver-determined, request-specific information, such as data necessary to process a particular request. The OS-specific port driver does not initialize SRB extensions, but sets a pointer to this storage in each SRB it sends to the miniport driver. An SRB extension can be safely accessed by the HBA hardware. Leave this member set to zero if the miniport driver does not maintain per-SRB information for which it requires storage. This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as [ScsiPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetuncachedextension).

### `NumberOfAccessRanges`

Specifies how many access ranges the adapter uses. Each is a range either of memory addresses or I/O port addresses. A typical HBA uses two ranges, one for its I/O ports and another for its device memory range.

### `Reserved`

Reserved for system use and not available for use by miniport drivers.

### `MapBuffers`

Indicates, when **TRUE**, that all data buffer addresses must be mapped to virtual addresses for access by the miniport driver. When **FALSE**, data buffer addresses do not have to be mapped to virtual addresses.

### `NeedPhysicalAddresses`

Indicates, when **TRUE**, that the miniport driver needs to translate its device, any per-LU, and any per-SRB extension addresses, as well as SRB buffer addresses, to physical addresses, as required by the HBA. When **FALSE**, none of these addresses have to be translated to physical addresses.

### `TaggedQueuing`

Indicates, when **TRUE**, that miniport driver can support SCSI tagged queuing. When **FALSE**, the miniport driver cannot support SCSI-tagged queuing.

### `AutoRequestSense`

Indicates, when **TRUE**, that the HBA can perform a request-sense operation without requiring an explicit request to do so. When **FALSE**, the HBA requires an explicit request before it can perform a request-sense operation. Only miniport drivers driving HBAs with built-in firmware to perform request-sense operations should set this member to **TRUE**.

### `MultipleRequestPerLu`

Indicates, when **TRUE**, that the miniport driver can queue multiple requests per logical unit, in particular, within the HBA. When **FALSE**, the miniport driver cannot queue multiple requests per logical unit. Note that an HBA must support auto request sense for its miniport driver to enable this functionality. If a miniport driver sets this member to **TRUE**, it must use each SRB **QueueTag** member for requests of this type, but the SRB_FLAGS_QUEUE_ACTION_ENABLE is not set in the **SrbFlags** member of the SCSI_REQUEST_BLOCK structure.

### `ReceiveEvent`

Indicates, when **TRUE**, that the miniport driver drives an HBA that can support the receive-event SRB for SCSI asynchronous events. When **FALSE**, the HBA cannot support the receive-event SRB for SCSI asynchronous events.

### `VendorIdLength`

Specifies the size in bytes of the **VendorId** string, described next.

### `VendorId`

Pointer to an ASCII byte string identifying the manufacturer of the HBA. This member is irrelevant for Plug and Play drivers.

If the given **AdapterInterfaceType** is **PCIBus**, the vendor ID is a USHORT value allocated by the PCI SIG, which must be converted into a byte string by the miniport driver. For example, if the assigned PCI vendor ID value is 1001, the miniport driver-supplied **VendorId** string would be ('1', '0', '0', '1').

### `ReservedUshort`

Reserved for system use and is not available for use by miniport drivers.

### `PortVersionFlags`

### `DeviceIdLength`

Specifies the size in bytes of the **DeviceId** string, described next.

### `DeviceId`

Pointer to an ASCII byte string identifying the HBA model(s) supported by the miniport driver. This member is irrelevant for Plug and Play drivers.

If the given **AdapterInterfaceType** is **PCIBus**, a device ID is a USHORT value assigned by the manufacturer of the HBA. The miniport driver must convert any PCI device ID value(s) for the HBA(s) it can support into **DeviceId** byte string(s), as for the **VendorId** member. For example, if a miniport driver can support HBAs with the PCI device IDs 8040 and 8050, it might set **DeviceId** with a pointer to the byte string ('8', '0').

### `HwAdapterControl`

Pointer to the miniport driver's [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)) routine, which is a required entry point for all PnP miniport drivers. Set this to **NULL** if the miniport driver does not support Plug and Play.

## Remarks

Each miniport driver must initialize the HW_INITIALIZATION_DATA structure with zeros before it sets the values of relevant members in this structure and calls **ScsiPortInitialize**.

The **Dma64BitAddresses** member of HW_INITIALIZATION_DATA has been eliminated in Windows 2000 (See the discussion under PORT_CONFIGURATION_DATA for further details).

Both HW_INITIALIZATION_DATA and PORT_CONFIGURATION_INFORMATION have a pair of members called **SpecificLuExtensionSize** and **SrbExtensionSize** whose values are handled differently than they were prior to Windows 2000. The miniport driver must calculate the initial values of **SpecificLuExtensionSize** and **SrbExtensionSize** in HW_INITIALIZATION_DATA based on the assumption that the HBA is capable of handling 32-bit addresses, regardless of what the controller can actually support. (See the discussion under PORT_CONFIGURATION_DATA for further details.)

## See also

[DriverEntry of SCSI Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[HwScsiInitialize](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557302(v=vs.85))

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize)