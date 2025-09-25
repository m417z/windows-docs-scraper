## Description

The **PCI_EXPRESS_SLOT_CONTROL_REGISTER** union describes a PCI Express (PCIe) slot control register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

The **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.AttentionButtonEnable`

A single bit that indicates that the attention button for the slot is enabled to generate events.

### `DUMMYSTRUCTNAME.PowerFaultDetectEnable`

A single bit that indicates that power fault detection for the slot is enabled to generate events.

### `DUMMYSTRUCTNAME.MRLSensorEnable`

A single bit that indicates that the manually operated retention latch (MRL) sensor for the slot is enabled to generate events.

### `DUMMYSTRUCTNAME.PresenceDetectEnable`

A single bit that indicates that card presence detection for the slot is enabled to generate events.

### `DUMMYSTRUCTNAME.CommandCompletedEnable`

A single bit that indicates that notification is enabled for the slot when an issued command is completed by the hot-plug controller.

### `DUMMYSTRUCTNAME.HotPlugInterruptEnable`

A single bit that indicates that interrupts for the slot are enabled for hot-plug events.

### `DUMMYSTRUCTNAME.AttentionIndicatorControl`

The state of the slot's attention indicator. Possible values are:

**IndicatorOn**
The indicator is on.

**IndicatorBlink**
The indicator is blinking.

**IndicatorOff**
The indicator is off.

### `DUMMYSTRUCTNAME.PowerIndicatorControl`

The state of the slot's power indicator. Possible values are:

**IndicatorOn**
The indicator is on.

**IndicatorBlink**
The indicator is blinking.

**IndicatorOff**
The indicator is off.

### `DUMMYSTRUCTNAME.PowerControllerControl`

The state of the slot's power controller. Possible values are:

**PowerOn**
The power is on.

**PowerOff**
The power is off.

### `DUMMYSTRUCTNAME.ElectromechanicalLockControl`

This member always contains zero.

### `DUMMYSTRUCTNAME.DataLinkStateChangeEnable`

A single bit that indicates that notification is enabled for the slot for changes to the data link layer active bit of the link status register of the PCIe capability structure.

### `DUMMYSTRUCTNAME.Rsvd`

Reserved.

### `AsUSHORT`

A **USHORT** representation of the contents of the **PCI_EXPRESS_SLOT_CONTROL_REGISTER** structure.

## Remarks

The **PCI_EXPRESS_SLOT_CONTROL_REGISTER** structure is available in Windows Server 2008 and later versions of Windows.

A **PCI_EXPRESS_SLOT_CONTROL_REGISTER** structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)