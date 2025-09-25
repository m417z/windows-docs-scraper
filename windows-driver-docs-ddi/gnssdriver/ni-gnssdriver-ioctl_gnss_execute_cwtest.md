# IOCTL_GNSS_EXECUTE_CWTEST IOCTL

## Description

The **IOCTL_GNSS_EXECUTE_CWTEST** control code is used by the GNSS manufacturing test application to start a carrier wave test and get the measurement. The test application must wait for the result before starting another iteration of the measurement.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_CWTESTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_cwtestdata) structure.

### Output buffer length

Set to sizeof(GNSS_CWTESTDATA).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS test application notes

The test application must ensure that no more than one carrier wave test is started at the same time.

Once the carrier wave test is started, the test application must wait for the result.

The test application will need to repeat this command if it wants to retrieve more than one measurement.

### GNSS driver notes

The GNSS driver must fail the new carrier wave test session request if there is already a test in progress.

Once the GNSS driver accepts the carrier wave test session parameters, validates them and starts the detection in the GNSS engine. When the measurements are received, the driver immediately completes the IO with a return code and the measurements.

The GNSS stack must return the measurements as soon as they are available.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)