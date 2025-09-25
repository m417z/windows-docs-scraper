# IOCTL_EHSTOR_DEVICE_QUERY_PROPERTIES IOCTL

## Description

A silo driver sends this IOCTL to the storage device stack to query for storage device properties. The Enhanced Storage Class Driver (EHSTOR) will handle the request and return the available properties.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The output buffer at **Irp->AssociatedIrp.SystemBuffer** contains an **EHSTOR_DEVICE_PROPERTIES** structure. **EHSTOR_DEVICE_PROPERTIES** is declared in *ehstorioctl.h* as the following.

```
typedef struct _EHSTOR_DEVICE_PROPERTIES
{
    ULONG  StructSize;
    ULONG  BytesPerSector;
} EHSTOR_DEVICE_PROPERTIES;
```

### Output buffer length

an **EHSTOR_DEVICE_PROPERTIES** structure.

### Input/output buffer

### Input/output buffer length

### Status block

STATUS_SUCCESS is returned in the **Status** field if device properties are returned in the system buffer. Otherwise, another appropriate status code is returned.

## -BytesPerSector

The size, in bytes, of a sector on the underlying storage device.

## -StructSize

The size of the structure. This is set to **sizeof**(EHSTOR_DEVICE_PROPERTIES).

## Remarks

Currently, bytes per sector is the only property available in **EHSTOR_DEVICE_PROPERTIES**.

## See also

[SILO_DRIVER_CAPABILITES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagact_authz_state)