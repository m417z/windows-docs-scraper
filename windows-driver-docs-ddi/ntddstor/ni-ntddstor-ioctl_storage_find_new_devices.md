# IOCTL_STORAGE_FIND_NEW_DEVICES IOCTL

## Description

Determines whether another device that the driver supports has been connected to the I/O bus, either since the system was booted or since the driver last processed this request.

This IOCTL is obsolete in the Plug and Play environment. Plug and Play class drivers handle this request by calling [IoInvalidateDeviceRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinvalidatedevicerelations) with the device relations type **BusRelations**. If a new device is found, the class driver's *AddDevice* routine will be called.

Legacy class drivers can continue to handle this IOCTL without modifications. If a new device is found, the driver sets up any necessary system objects and resources to handle I/O requests for its new device. It also initializes the device on receipt of this request dynamically, that is, without requiring the machine to be rebooted. Such a driver is assumed to support devices connected on a dynamically configurable I/O bus.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field can be set to STATUS_SUCCESS or to any other value returned by a Plug and Play driver's **IoInvalidateDeviceRelations** call or a legacy driver's (re)initialization code.