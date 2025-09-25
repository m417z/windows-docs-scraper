# _PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER structure (ntddk.h)

## Description

The PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER structure describes a PCI Express (PCIe) slot capabilities register of a PCIe capability structure.

## Members

### `DUMMYSTRUCTNAME`

### `AsULONG`

A ULONG representation of the contents of the PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER structure.

### `DUMMYSTRUCTNAME.AttentionButtonPresent`

A single bit that indicates that an attention button exists for the slot.

### `DUMMYSTRUCTNAME.AttentionIndicatorPresent`

A single bit that indicates that an attention indicator exists for the slot.

### `DUMMYSTRUCTNAME.ElectromechanicalLockPresent`

A single bit that indicates that an electromechanical interlock exists for the slot.

### `DUMMYSTRUCTNAME.HotPlugCapable`

A single bit that indicates that the slot is capable of supporting hot-plug operations.

### `DUMMYSTRUCTNAME.HotPlugSurprise`

A single bit that indicates that an adapter that is present in the slot can be removed from the system without any prior notification.

### `DUMMYSTRUCTNAME.MRLSensorPresent`

A single bit that indicates that a manually operated retention latch (MRL) sensor exists for the slot.

### `DUMMYSTRUCTNAME.NoCommandCompletedSupport`

A single bit that indicates that the slot does not generate software notification when an issued command is completed by the hot-plug controller.

### `DUMMYSTRUCTNAME.PhysicalSlotNumber`

The physical slot number in the system chassis that is attached to this port. This value is zero for ports that are connected to devices that are either integrated on the system board or integrated within the same physical component as the switch device or root port.

### `DUMMYSTRUCTNAME.PowerControllerPresent`

A single bit that indicates that a software programmable power controller exists for the slot or for the adapter that is plugged into the slot.

### `DUMMYSTRUCTNAME.PowerIndicatorPresent`

A single bit that indicates that a power indicator exists for the slot.

### `DUMMYSTRUCTNAME.SlotPowerLimit`

The maximum amount of power that can be supplied by the slot. This value is used in combination with the value of the **SlotPowerLimitScale** member to compute the power in watts.

### `DUMMYSTRUCTNAME.SlotPowerLimitScale`

The scale used for the value contained in the **SlotPowerLimit** member to compute the maximum power, in watts, that can be supplied by the slot. Possible values are:

#### 0

Multiply the value in the **SlotPowerLimit** member by 1.0.

#### 1

Multiply the value in the **SlotPowerLimit** member by 0.1.

#### 2

Multiply the value in the **SlotPowerLimit** member by 0.01.

#### 3

Multiply the value in the **SlotPowerLimit** member by 0.001.

## Syntax

```cpp
typedef union _PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER {
  struct {
    ULONG AttentionButtonPresent  :1;
    ULONG PowerControllerPresent  :1;
    ULONG MRLSensorPresent  :1;
    ULONG AttentionIndicatorPresent  :1;
    ULONG PowerIndicatorPresent  :1;
    ULONG HotPlugSurprise  :1;
    ULONG HotPlugCapable  :1;
    ULONG SlotPowerLimit  :8;
    ULONG SlotPowerLimitScale  :2;
    ULONG ElectromechanicalLockPresent  :1;
    ULONG NoCommandCompletedSupport  :1;
    ULONG PhysicalSlotNumber  :13;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER, *PPCI_EXPRESS_SLOT_CAPABILITIES_REGISTER;
```

## Remarks

The PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER structure is available in Windows Server 2008 and later versions of Windows.

A PCI_EXPRESS_SLOT_CAPABILITIES_REGISTER structure is contained in the [PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure.

## See also

[PCI_EXPRESS_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)