# IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES IOCTL

## Description

The **IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES** request retrieves the banded security capabilities for a storage device. The IOCTL returns the capabilities as a [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities) structure in the system buffer.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The output buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities) structure.

### Output buffer length

The length of a [BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The device supports band management and the security capabilities are returned in the system buffer. |
| STATUS_INVALID_DEVICE_REQUEST | Band management is not supported on the storage device. |
| STATUS_INVALID_DEVICE_STATE | The device provides band management support but not in its present configuration. |
| STATUS_BUFFER_OVERFLOW | A buffer is not provided or its size is set to zero. The required size is returned in the **Information** field. |
| STATUS_BUFFER_TOO_SMALL | The buffer size is too small to return the output. |

## Remarks

A driver or application can query for the necessary output buffer size by setting the output buffer for the request to NULL and the output size to 0. The **IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES** request will return with the **Status** field of the *IoStatus* block set to STATUS_BUFFER_OVERFLOW and the **Information** field will contain the required buffer size.

## See also

[BAND_MANAGEMENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ns-ehstorbandmgmt-_band_management_capabilities)