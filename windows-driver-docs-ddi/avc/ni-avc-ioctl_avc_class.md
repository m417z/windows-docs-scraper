# IOCTL_AVC_CLASS IOCTL

## Description

The IOCTL_AVC_CLASS I/O control code is supported only from kernel mode, using the IRP_MJ_INTERNAL_DEVICE_CONTROL dispatch.

*Avc.sys* supports two device interfaces, depending upon the type of instance (peer or virtual). These interfaces define the functionality that the driver exposes for subunit drivers, other drivers, and applications. During initialization, *avc.sys* calls **IoRegisterDeviceInterface** with either GUID_AVC_CLASS (a peer, or nonvirtual instance) or GUID_VIRTUAL_AVC_CLASS (a virtual instance), then uses **IoSetDeviceInterfaceState** as appropriate for the started or stopped state of the driver.

Peer instances of *avc.sys* register the device interface identified by GUID_AVC_CLASS. This interface supports one I/O control code, IOCTL_AVC_CLASS, which in turn supports multiple function codes. Child drivers of peer *avc.sys* instances are guaranteed to have access to this interface through their parent device object.

Virtual instances of *avc.sys* register the device interface identified by GUID_VIRTUAL_AVC_CLASS. This interface supports four I/O control codes:

- IOCTL_AVC_CLASS

- IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO

- IOCTL_AVC_REMOVE_VIRTUAL_SUBUNIT_INFO

- IOCTL_AVC_BUS_RESET

The GUID_AVC_CLASS interface supports all IOCTL_AVC_CLASS function codes, although some have limitation on their use. However, the GUID_VIRTUAL_AVC_CLASS interface does not support all IOCTL_AVC_CLASS function codes. The reference page for each individual function code specifies whether it is supported for GUID_VIRTUAL_AVC_CLASS instances of *avc.sys*.

The IOCTL_AVC_CLASS function codes (and any restrictions) are described in each function code.

For more information about IRPs and IOCTLs, see [Handling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irps).

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

**Parameters->Others.Argument1** points to either an AVC_COMMAND_IRB structure or AVC_MULTIFUNC_IRB structure. Both structures contain an AVC_IRB structure as a header, as illustrated in the following example:

```cpp
typedef struct _AVC_COMMAND_IRB {
  AVC_IRB  Common;
  .
  .
  .
} AVC_COMMAND_IRB, *PAVC_COMMAND_IRB;
```

```cpp
typedef struct _AVC_MULTIFUNC_IRB {
  AVC_IRB  Common;
  .
  .
  .
} AVC_MULTIFUNC_IRB, *PAVC_MULTIFUNC_IRB;
```

The AVC_IRB structure contains a single **Function** member. This member must be set to the desired function code from the AVC_FUNCTION enumeration.

The AVC_MULTIFUNC_IRB structure contains a union member that specifies the function I/O request block type-specific parameters for the function code. The parameters and their meanings are documented with each function code.

**Parameters->Others.Argument1** points to the same AVC_COMMAND_IRB or AVC_MULTIFUNC_IRB structure that was passed as input. As part of completing the function, the subunit driver fills in certain submembers of the union within the structure with information for the driver. The returned information is documented with each request.

### Input/output buffer length

### Status block

The information the AV/C protocol driver returns in the I/O Status Block (Irp->IoStatus.Status) is documented with each request.

## Remarks

Most AV/C functions must be called IRQL = PASSIVE_LEVEL. A few may be called at IRQL <= DISPATCH_LEVEL. The respective IRQL is documented in each AV/C function.

## See also

[AVC_COMMAND_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_command_irb)

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_irb)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)

[IOCTL_AVC_BUS_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_bus_reset)

[IOCTL_AVC_REMOVE_VIRTUAL_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_remove_virtual_subunit_info)

[IOCTL_AVC_UPDATE_VIRTUAL_SUBUNIT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_update_virtual_subunit_info)