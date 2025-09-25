# KsAcquireDeviceSecurityLock function

## Description

The **KsAcquireDeviceSecurityLock** function acquires the security lock associated with a device object. An exclusive lock is acquired when changing a security descriptor. When manipulating the security of any object under a particular device object, this lock must be acquired.

## Parameters

### `Header` [in]

Points to a driver-allocated device header, previously allocated by **KsAllocateDeviceHeader,** for the device object described by the KSDEVICE_HEADER structure.

### `Exclusive` [in]

Indicates, if set to **TRUE**, that the lock is to be acquired exclusively.

## Return value

None

## Remarks

A shared lock is acquired when validating access during a create. An exclusive lock is acquired when changing a security descriptor.

## See also

[KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader)