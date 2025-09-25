# _IRB_REQ_FREE_ADDRESS_RANGE structure

## Description

This structure contains the fields necessary for the 1394 stack to carry out a free address range request.

## Members

### `nAddressesToFree`

Specifies the number of [ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_address_range) structures pointed to by **IRB.u.FreeAddressRange.p1394AddressRange**

### `p1394AddressRange`

Specifies a pointer to an array of [ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_address_range) data structures to be released. These address ranges were returned in a prior successful call to **AllocateAddressRange**.

### `pAddressRange`

Points to the handle that was previously received in **IRB.u.AllocateAddressRange.hAddressRange** in the [REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request.

### `DeviceExtension`

Points to the device extension associated with the device object. Not setting this member can lead to unexpected behavior when the driver tries to access the allocated address space.