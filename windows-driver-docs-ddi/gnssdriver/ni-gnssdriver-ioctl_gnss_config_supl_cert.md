# IOCTL_GNSS_CONFIG_SUPL_CERT IOCTL

## Description

The **IOCTL_GNSS_CONFIG_SUPL_CERT** control code is used by the GNSS adapter to set SUPL certificates.

## Parameters

### Major code

### Input buffer

Pointer to a [GNSS_SUPL_CERT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_supl_cert_config) structure.

### Input buffer length

Set to sizeof(**GNSS_SUPL_CERT_CONFIG**).

### Output buffer

Set to **NULL**.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

The driver sets one of the following NTSTATUS values to indicate result.

* STATUS_SUCCESS, when the driver processes the SUPL certificate information successfully. If the IOCTL tries to delete or purge certificates that don’t exist, it still returns STATUS_SUCCESS.
* Failed, when the driver does not process the SUPL certificate information successfully.
* Ignored, when the driver ignores the SUPL certificate information.

### GNSS adapter notes

For GNSS DDI version 1:

The GNSS adapter does not need to do anything special.

For GNSS DDI version 2 and later:

The GNSS adapter will only refer to certificates by name. It will be up to the GNSS driver to map the certificate names internally to any other representation or reference to the certificates, if needed.

The GNSS adapter will do a full purge or all previously injected certificates if needed before injecting a new set.

### GNSS driver notes

The GNSS driver needs to pass this certificate information to the SUPL component which should use the certificate to set up secure connection with H-SLP.

For GNSS DDI version 2 and later:

The GNSS driver must support receiving multiple calls of the **IOCTL_GNSS_CONFIG_SUPL_CERT**. The GNSS adapter will call this IOCTL multiple times, each time to inject a different root certificate. Different root certificates are identified by having a different **SuplCertName**, which provides the name of the certificate being injected.

* If the name is the same as a previously configured certificate, then the certificate will be replaced.
* If the name is different from certificate, then the new certificate will be added.

If a certificate with the same name as an existing certificate is injected again, the GNSS driver should overwrite the previous certificate with the same name.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)