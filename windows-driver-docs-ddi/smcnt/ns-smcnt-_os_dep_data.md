# _OS_DEP_DATA structure

## Description

The OS_DEP_DATA structure defines the data that is stored in the **OsData** member of the [SMARTCARD_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension) structure, which holds smart card information that is specific to the operating system.

## Members

### `DeviceObject`

A pointer to the smart card reader device object. (Must be set by the driver.)

### `CurrentIrp`

A pointer to the current IRP to process. Access to this field must be sequentialized by using the spin lock pointed to by the **OsData->SpinLock** member of [SMARTCARD_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension).

### `NotificationIrp`

A pointer to an IRP that the smart card reader driver uses to notify applications when a smart card has been inserted or removed. Access to this field must be sequentialized by using the spin lock that is pointed to by the **OsData->SpinLock** member of SMARTCARD_EXTENSION.

### `Mutex`

Contains a mutex that applications use to synchronize access to the reader driver.

### `SpinLock`

Contains a mutex that drivers use to synchronize access to protected members of the OS_DEP_DATA structure. For more information, see [SCARD_CARD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_scard_card_capabilities).

### `RemoveLock`

A structure with the following members:

### `RemoveLock.Removed`

If this Boolean value is non-zero, it indicates that the spin lock was removed.

### `RemoveLock.RefCount`

If this long integer is non-zero, it indicates the number of references to the spin lock that are currently active.

### `RemoveLock.RemoveEvent`

A pointer to an event that synchronizes spin lock removal.

### `RemoveLock.TagList`

A pointer to a linked list of structures, each of which contains a tag string that identifies a remove spin lock.

### `DebugDeviceObject`

Unused.

## Remarks

To allocate this structure, drivers must call [SmartcardInitialize (WDM)](https://learn.microsoft.com/previous-versions/ff548944(v=vs.85)). After this call, drivers should copy the pointer of the smart card device object to **DeviceObject**. Otherwise, the smart card driver library will not work. Do not use this structure to store driver-dependent information. However, when the smart card driver library calls one of your driver's callback functions, it sets **CurrentIrp** to the requesting IRP, unless the request is a smart card tracking request. For smart card tracking requests, the driver library sets **NotificationIrp** to the requesting IRP. For more information about smart card tracking, see [RDF_CARD_TRACKING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548920(v=vs.85)).