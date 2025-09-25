# PcAddAdapterDevice function

## Description

The **PcAddAdapterDevice** function adds an adapter device to the WDM device stack.

## Parameters

### `DriverObject` [in]

Pointer to the driver object. This pointer is passed as a parameter to the adapter's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) handler. The driver object is a system structure of type [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object).

### `PhysicalDeviceObject` [in]

Pointer to the device's [physical device object (PDO)](https://learn.microsoft.com/windows-hardware/drivers/). PortCls passes this pointer as a call parameter to the adapter's *AddDevice* handler. The PDO is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `StartDevice` [in]

Pointer to the function that the operating system calls in order to start the device. For more information, see the following **Remarks** section.

### `MaxObjects` [in]

Specifies the maximum number of subdevices to be registered by calls to [PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice). This count sets the upper limit to the total number of miniport objects that the adapter driver can instantiate.

### `DeviceExtensionSize` [in]

Specifies the device extension size. Use zero for default size. See the following **Remarks** section for user-supplied extension sizes.

## Return value

**PcAddAdapterDevice** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

This function does most of the work that the audio adapter driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) handler needs to perform. **PcAddAdapterDevice** creates the device object, initializes the device context, and attaches the device object to the device stack.

An adapter driver calls **PcAddAdapterDevice** when it receives a call to its *AddDevice* handler. The adapter driver typically installs the *AddDevice* handler by calling [PcInitializeAdapterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcinitializeadapterdriver), although the driver can also install the handler by other means. **PcAddAdapterDevice** creates the [functional device object (FDO)](https://learn.microsoft.com/windows-hardware/drivers/) for the PDO that was passed to the *AddDevice* handler.

*DeviceExtensionSize* is typically zero. Some adapter drivers might need to reserve additional space in the device extension, in which case they should specify a *DeviceExtensionSize* greater than PORT_CLASS_DEVICE_EXTENSION_SIZE, which is the default size. Any value greater than zero and less than PORT_CLASS_DEVICE_EXTENSION_SIZE is illegal. Adapter drivers are free to use any part of the device extension after offset PORT_CLASS_DEVICE_EXTENSION_SIZE. They are also free to use bytes in the offset range of 16 to 31 inclusive in a system with 32-bit addressing and bytes in the offset range 32 to 63 in a system with 64-bit addressing. If the extension is regarded as an array of ULONG_PTR, array elements four through seven are available for use by the adapter driver.

The *StartDevice* parameter points to a function of type PCPFNSTARTDEVICE, which header file *portcls.h* defines as:

```
  NTSTATUS
    (*PCPFNSTARTDEVICE)(
      IN PDEVICE_OBJECT  DeviceObject,
      IN PIRP  Irp,
      IN PRESOURCELIST  ResourceList
      );
```

For more information about **PcAddAdapterDevice** and the adapter driver's device-startup and *AddDevice* routines, see [Startup Sequence](https://learn.microsoft.com/windows-hardware/drivers/audio/startup-sequence).

The following example code shows how an adapter driver can use the *DeviceExtensionSize* parameter to append 64 bytes of device-specific extension data to the end of the storage block that PortCls allocates for the device context:

```
  #define MY_EXTENSION_SIZE  64
  NTSTATUS  ntstatus = PcAddAdapterDevice(DriverObject, PhysicalDeviceObject,
                                          MyStartDevice, MAX_MINIPORTS,
                                          MY_EXTENSION_SIZE + PORT_CLASS_DEVICE_EXTENSION_SIZE);
```

The **PcAddAdapterDevice** call above is similar to the example in [Startup Sequence](https://learn.microsoft.com/windows-hardware/drivers/audio/startup-sequence), except that the last parameter that is passed to **PcAddAdapterDevice** is nonzero.

The adapter driver can then access the device-specific extension data, as shown in the following code fragment:

```
  PVOID  pMyExtensionData = (PVOID)((PCHAR)FunctionalDeviceObject->DeviceExtension +
                                              PORT_CLASS_DEVICE_EXTENSION_SIZE);
```

Variable *FunctionalDeviceObject* is a pointer to the audio adapter's FDO, and *pMyExtensionData* is a temporary pointer to the extension data. Avoid confusing the FDO with the PDO, which belongs to the PCI bus driver. The adapter driver must not modify data in the PDO because doing so corrupts memory owned by the PCI bus driver and can cause the system to crash.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice)