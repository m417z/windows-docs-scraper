# _PCI_COMMON_CONFIG structure (wdm.h)

## Description

The **PCI_COMMON_CONFIG** structure defines standard PCI configuration information returned by the [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) or [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) routine for the input *BusDataType* PCIConfiguration, assuming the caller-allocated *Buffer* is of sufficient *Length*.

## Members

### `DeviceSpecific`

Contains any device-specific initialization information that is available.

#### type0

Drivers call [HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) to configure these values and to get back the bus-relative values passed to other configuration routines.

##### BaseAddresses

Base addresses.

##### Reserved1

Reserved.

##### ROMBaseAddress

ROM base address.

##### Reserved2

Reserved.

##### InterruptLine

Interrupt line number.

##### InterruptPin

Interrupt pin number.

##### MinimumGrant

Minimum grant.

##### MaximumLatency

Maximum latency.

##### - u.type0

Drivers call [HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) to configure these values and to get back the bus-relative values passed to other configuration routines.

##### type0.BaseAddresses

Base addresses.

##### type0.Reserved1

Reserved.

##### type0.ROMBaseAddress

ROM base address.

##### type0.Reserved2

Reserved.

##### type0.InterruptLine

Interrupt line number.

##### type0.InterruptPin

Interrupt pin number.

##### type0.MinimumGrant

Minimum grant.

##### type0.MaximumLatency

Maximum latency.

###### - u.type0.BaseAddresses

Base addresses.

###### - u.type0.InterruptLine

Interrupt line number.

###### - u.type0.InterruptPin

Interrupt pin number.

###### - u.type0.MaximumLatency

Maximum latency.

###### - u.type0.MinimumGrant

Minimum grant.

###### - u.type0.ROMBaseAddress

ROM base address.

###### - u.type0.Reserved1

Reserved.

###### - u.type0.Reserved2

Reserved.

## Remarks

Certain members of this structure have read-only values, so attempts to reset them are ignored. These members include the following: **VendorID**, **DeviceID**, **RevisionID**, **ProgIf**, **SubClass**, **BaseClass**, **HeaderType**, **InterruptPin**, **MinimumGrant**, and **MaximumLatency.**

Other members are provisionally read-only: that is, the system initializes them to their correct values, so drivers can safely treat them as read-only. However, they can be reset if a bus-master driver finds it necessary. These members include the following: **CacheLineSize** and **LatencyTimer**.

## See also

[HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))