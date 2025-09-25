# ScsiPortInitialize function

## Description

For a non-Plug and Play miniport driver, the **ScsiPortInitialize** routine sets up the PORT_CONFIGURATION_INFORMATION structure and calls the miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine. **ScsiPortInitialize** also sets up system objects and resources on behalf of miniport drivers. For a Plug and Play miniport driver, **ScsiPortInitialize** stores the miniport driver's initialization data for future use.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Argument1` [in]

Pointer to the driver object that the operating system passed to the miniport driver in the first argument of its **DriverEntry** routine.

### `Argument2` [in]

Pointer to some context information that the operating system passed to the miniport driver in the second argument of its **DriverEntry**.

### `HwInitializationData` [in]

Pointer to the initialization and configuration information supplied by **DriverEntry**.

### `HwContext` [in]

Specifies the address of a context value to be passed to the miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine. Only legacy miniport drivers that scan the bus for HBAs rather than receiving configuration information from the port driver can use this parameter to store state between calls to *HwScsiFindAdapter*.

## Return value

**ScsiPortInitialize** returns a status value that is used as the return value from the miniport driver's **DriverEntry** routine.

## Remarks

Every miniport driver's **DriverEntry** routine must call **ScsiPortInitialize** after the miniport driver has first zeroed and then set up the HW_INITIALIZATION_DATA.

If a miniport driver can support HBAs on different types of I/O buses, such as both **Isa** and **MicroChannel** type I/O buses, the miniport driver should call **ScsiPortInitialize** for each supported interface type.

A miniport driver that calls **ScsiPortInitialize** more than once should check the value returned by **ScsiPortInitialize** at each call and save the lowest value for all its calls. The **DriverEntry** routine must return the lowest value when it returns control to the system. Miniport driver writers can make no assumptions about the values returned by **ScsiPortInitialize**.

## See also

[DriverEntry of SCSI Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[HW_INITIALIZATION_DATA (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data)

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))