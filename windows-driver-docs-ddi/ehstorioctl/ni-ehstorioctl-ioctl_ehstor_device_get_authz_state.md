# IOCTL_EHSTOR_DEVICE_GET_AUTHZ_STATE IOCTL

## Description

This IOCTL is used to inform the owning driver for the IEEE 1667 device PDOs that the authorization state has changed. The owning driver may choose to change the state of the disk PDO in response to this IOCTL. In the case of  *EhStorClass.sys*, the disk PDO is added or removed based on the authorization value in the input buffer of this IOCTL. Typically this IOCTL is issued by a UMDF authentication silo driver, such as the password or certificate driver, immediately following a successful silo operation which has changed the authentication state of the silo.

## Parameters

### Major code

### Input buffer

The input buffer at Irp->AssociatedIrp.SystemBuffer must contain a structure of type [ACT_AUTHZ_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagact_authz_state).

### Input buffer length

The length of an [ACT_AUTHZ_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagact_authz_state) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values may be returned in the Status field:

STATUS_SUCCESS - The authorization state for the ACT was successfully set according to the data contained in the input buffer.

STATUS_INVALID_BUFFER_SIZE - The input buffer length supplied is of incorrect size.