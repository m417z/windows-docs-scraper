# UFS_DEVICE_HEALTH_DESCRIPTOR structure

## Description

The **UFS_DEVICE_HEALTH_DESCRIPTOR** structure describes the health of a device.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the descriptor's identification value. **UFS_DEVICE_HEALTH_DESCRIPTOR** will have a value of **UFS_DESC_HEALTH_IDN**.

### `bPreEOLInfo`

Contains pre-end-of-life information. This member supplies information about a device's life time as reflected by the average number of reserved blocks. Contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | Member is not defined. |
| 0x01 | Normal. Consumed less than 80% of reserved blocks. |
| 0x02 | Consumed 80% of reserved blocks. |
| 0x03 | Critical. Consumed 90% of reserved blocks. |
| All other values | Reserved for future use. |

### `bDeviceLifeTimeEstA`

**bDeviceLifeTimeEstA** provides an estimation of how much of a device's estimated life time has been used based on the amount of performed program and erase cycles. This calculation is vendor-specific and is referred as method A. Contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | Information about device's life time not found. |
| 0x01 | 0% to 10% of the device's estimated life time has been used. |
| 0x02 | 10% to 20% of the device's estimated life time has been used. |
| 0x03 | 20% to 30% of the device's estimated life time has been used. |
| 0x04 | 30% to 40% of the device's estimated life time has been used. |
| 0x05 | 40% to 50% of the device's estimated life time has been used. |
| 0x06 | 50% to 60% of the device's estimated life time has been used. |
| 0x07 | 60% to 70% of the device's estimated life time has been used. |
| 0x08 | 70% to 80% of the device's estimated life time has been used. |
| 0x09 | 80% to 90% of the device's estimated life time has been used. |
| 0x0A | 90% to 100% of the device's estimated life time has been used. |
| 0x0B | Device has exceeded it's estimated life time. |
| All other values | Reserved for future use. |

### `bDeviceLifeTimeEstB`

**bDeviceLifeTimeEstB** provides an estimation of how much of a device's estimated life time has been used based on the amount of performed program and erase cycles. This calculation is vendor-specific and is referred as method B. Contains the same possible values as **bDeviceLifeTimeEstA**.

### `VendorPropInfo[32]`

Reserved for vendor proprietary health report.

### `dRefreshTotalCount`

**dRefreshTotalCount** specifies how many times the device completed refresh for the entire device. **dRefreshTotalCount** is incremented by one when **dRefreshProgress** reaches 100000 (100.000%).

### `dRefreshProgress`

**dRefreshProgress** specifies the refresh progress in percentage. **dRefreshProgress** indicates 0.000% to 100.000% in decimal. **dRefreshProgress** is 100000 (dec) when it completes 100 percent. **dRefreshProgress** is 1000 (decimal) when it completes one percent. When this value reaches 100000 (100.000%):

 1. Device stops refreshing.
1. **dRefreshProgress** is reset to zero.
1. **dRefreshTotalCount** is incremented by one.

## Remarks

The UFS host controller contains a series of configurable descriptor tables, which allow the driver to query and configure the host controller's capabilities. Query the requested descriptor from the descriptor table on the device.

## See also

- [Universal Flash Storage 4.0 specification](https://www.jedec.org/standards-documents/docs/jesd220f)