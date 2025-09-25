# IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES IOCTL

## Description

This IOCTL is used to inform the enhanced storage (EHSTOR) class driver of the silo driver's capabilities. The silo driver sends this IOCTL with a [SILO_DRIVER_CAPABILITES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagact_authz_state) structure that indicates whether authentication and banding are supported along with a list of EHSTOR IOCTLs it will handle.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** must contain a structure of type [SILO_DRIVER_CAPABILITES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagact_authz_state). This structure is followed immediately by a list of which redirected IOCTLs the silo driver will handle.

### Input buffer length

The length of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The silo driver's capabilities were registered with the EHSTOR class driver. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer length supplied is of incorrect size. |
| STATUS_INVALID_PARAMETER | A capability parameter is incorrect. |
| STATUS_INSUFFICIENT_RESOURCES | The IOCTL redirection list cannot be copied. |
| STATUS_NOT_SUPPORTED | The sending device is not a silo device. |

## Remarks

This IOCTL is used by the Trusted Computing Group (TCG) standard authentication silo driver in Windows 8. On device initialization, the TCG silo driver will notify the EHSTOR class driver (EhStorClass.sys) of its capabilities by sending a **IOCTL_EHSTOR_DRIVER_REPORT_CAPABILITIES** request with a [SILO_DRIVER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_silo_driver_capabilities) structure.

Silo device objects exist outside the storage device stack. Any EHSTOR request intended for a silo driver must be explicitly forwarded to it. This is the case for all band management IOCTLs. Band management requests are made on a file object representing a physical drive. These requests are sent down the storage device stack. If the silo driver has registered support for the IOCTL, the EHSTOR class driver will redirect the request to the silo driver.

IOCTL requests supported by a silo driver are included in an array following [SILO_DRIVER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_silo_driver_capabilities) in the system buffer. The size of the information in the system buffer should be specified as **sizeof**(SILO_DRIVER_CAPABILITIES) + (**sizeof**(ULONG) * *RedirectedIoctlListCount*).

 A vendor supplied non-TCG authentication silo driver must notify the EHSTOR class driver of its capabilities using this IOCTL.

## See also

[SILO_DRIVER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_silo_driver_capabilities)