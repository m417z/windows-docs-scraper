# _GET_LOCAL_HOST_INFO4 structure

## Description

The GET_LOCAL_HOST_INFO4 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** = GET_PHYS_ADDR_ROUTINE.

## Members

### `PhysAddrMappingRoutine`

Pointer to the physical address mapping routine, which is of type:

```cpp
NTSTATUS
PhysAddrMappingRoutine (
    IN PVOID Context,
    IN OUT PIRB Irb
);
```

The physical mapping routine is invoked on a [REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) IRB. It fills in the **u.AllocateAddressRange.pAddressRange** member with the physical addresses that the **u.AllocateAddressRange.Mdl** member of the IRB are mapped to. The proper value for the *Context* parameter is the **Context** member below.

### `Context`

Specifies the argument that should be passed as the Context argument of the physical address mapping routine.

## See also

[REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)