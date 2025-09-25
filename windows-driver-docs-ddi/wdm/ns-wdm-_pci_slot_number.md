# _PCI_SLOT_NUMBER structure (wdm.h)

## Description

The **PCI_SLOT_NUMBER** structure is obsolete. It defines the format of the *Slot* parameter to the obsolete **Hal*Xxx*BusData** routines when they are called with the *BusDataType* value **PCIConfiguration**.

## Members

### `u`

### `u.bits`

Specifies the particular device on a multifunction adapter at the given slot that is being configured. The **DeviceNumber** indicates the logical slot number for the adapter; the **FunctionNumber** indicates the particular device on that adapter.

### `u.bits.DeviceNumber`

### `u.bits.FunctionNumber`

### `u.bits.Reserved`

### `u.AsULONG`

Specifies the logical slot number of the device being configured.

## Remarks

Drivers of PCI devices can call [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) or [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) more than once for the same slot number to get the configuration information for their device(s).

For example, a driver might search for devices it supports on all PCI buses in the machine first, and then call `HalGetBusData(ByOffset)` again to request more configuration information about devices of interest. Such a driver could code a loop that calls `HalGetBusData(ByOffset)` with an input `Buffer` of sufficient `Length` only to contain enough of the [PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85)) to determine the `VendorID` and `DeviceID` of each PCI device. After finding the `Slot` numbers for any promising PCI devices, the driver would call [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) or [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) one or more times with additional buffer space to get the information needed to configure its devices.

## See also

[HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85))