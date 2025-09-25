# IOCTL_GNSS_EXECUTE_SELFTEST IOCTL

## Description

The **IOCTL_GNSS_EXECUTE_SELFTEST** control code is used by the GNSS manufacturing test application to initiate a self test in the GNSS lower stack.

## Parameters

### Major code

### Input buffer

A pointer to a **GNSS_SELFTESTCONFIG** structure.

### Input buffer length

Set to sizeof(GNSS_SELFTESTCONFIG).

### Output buffer

A pointer to a **GNSS_SELFTESTRESULT** structure.

### Output buffer length

Set to sizeof(GNSS_SELFTESTRESULT).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS test application notes

The GNSS test application must wait for a status response from the test, and be resilient to the GNSS driver not responding.

### GNSS driver notes

The GNSS driver must fail a new self test session request if there is already a test in progress.

Once the GNSS driver accepts the self test session parameters, validates them and starts the test in the GNSS engine. The GNSS driver completes the I/O request after completing the tests and returning the status to the GNSS test application.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)