## Description

The **PCI_COMMON_CONFIG** structure is obsolete. It defines standard PCI configuration information returned by the obsolete [HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) or [HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85)) routine for the input *BusDataType* PCIConfiguration, assuming the caller-allocated *Buffer* is of sufficient *Length*.

## Members

### `DeviceSpecific`

Contains any device-specific initialization information that is available.

## Remarks

Certain members of this structure have read-only values, so attempts to reset them are ignored. These members include the following: **VendorID**, **DeviceID**, **RevisionID**, **ProgIf**, **SubClass**, **BaseClass**, **HeaderType**, **InterruptPin**, **MinimumGrant**, and **MaximumLatency.**

Other members are provisionally read-only: that is, the system initializes them to their correct values, so drivers can safely treat them as read-only. However, they can be reset if a bus-master driver finds it necessary. These members include the following: **CacheLineSize** and **LatencyTimer**.

## See also

[HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalSetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))