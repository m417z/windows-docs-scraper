# IOCTL_GNSS_GET_DEVICE_CAPABILITY IOCTL

## Description

The IOCTL_GNSS_GET_DEVICE_CAPABILITY control code is used by the GNSS adapter to get the GNSS driver and device capabilities. The GNSS driver also specifies various support requirements from the HLOS components. This information is needed by the GNSS driver as well as the location service for deferring location-specific functionality to the GNSS device.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

Pointer to a [GNSS_DEVICE_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_device_capability) structure.

### Output buffer length

Set to sizeof(GNSS_DEVICE_CAPABILITY).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS adapter notes

On completion, the GNSS adapter stores the capability information in its state variables and communicates the same to other location components. Depending on the specific device capabilities and/or support requirements, the GNSS adapter can also load/unload other components to provide the needed support.

### GNSS driver notes

Driver fills the output buffer and completes the I/O.

This should be called when the GNSS adapter is initializing the GNSS driver.

Even if the driver supports a specific functionality or needs a specific functionality support from the HLOS, it is not guaranteed that the HLOS will leverage a specific driver capability, or will provided the needed level of support to the driver.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)