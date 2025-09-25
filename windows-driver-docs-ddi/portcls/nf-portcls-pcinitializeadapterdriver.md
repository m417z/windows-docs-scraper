# PcInitializeAdapterDriver function

## Description

The **PcInitializeAdapterDriver** function binds an adapter driver to the PortCls system driver. IRP handlers and handlers for device addition and removal are installed in the driver object. Adapter drivers that need to bind to more than one class driver should not call this function.

## Parameters

### `DriverObject` [in]

Pointer to the driver object, which is a system structure of type [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object). This pointer is passed as a parameter to the adapter's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

### `RegistryPathName` [in]

Specifies the registry path name that is to be passed as a parameter to the adapter's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function.

### `AddDevice` [in]

Pointer to the adapter's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) function. This is a pointer of type PDRIVER_ADD_DEVICE, which is defined in ntddk.h to be:

```
  NTSTATUS
    (*PDRIVER_ADD_DEVICE)(
      IN struct _DRIVER_OBJECT  *DriverObject,
      IN struct _DEVICE_OBJECT  *PhysicalDeviceObject
        );
```

## Return value

**PcInitializeAdapterDriver** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) handler supplied in the call to this function should call [PcAddAdapterDevice](https://learn.microsoft.com/windows-hardware/drivers/devtest/audio-pcaddadapterdevice). For more information, see [Startup Sequence](https://learn.microsoft.com/windows-hardware/drivers/audio/startup-sequence).

The **PcInitializeAdapterDriver** function loads pointers to handlers for the following IRPs into the driver object:

* IRP_MJ_CLOSE
* IRP_MJ_CREATE
* IRP_MJ_DEVICE_CONTROL
* IRP_MJ_FLUSH_BUFFERS
* IRP_MJ_PNP
* IRP_MJ_POWER
* IRP_MJ_QUERY_SECURITY
* IRP_MJ_READ
* IRP_MJ_SET_SECURITY
* IRP_MJ_SYSTEM_CONTROL
* IRP_MJ_WRITE

PortCls uses its own internal handlers for the CREATE, PNP, POWER, and SYSTEM_CONTROL IRPs above. It uses the default KS handlers for the other seven IRPs.

An adapter driver that overwrites one or more of the pointers above with a pointer to its own IRP handler can call [PcDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdispatchirp) from within its handler routine in order to forward the IRP to PortCls. For a code example, see the SB16 sample audio driver in the Microsoft Windows Driver Kit (WDK).

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[PcAddAdapterDevice](https://learn.microsoft.com/windows-hardware/drivers/devtest/audio-pcaddadapterdevice)

[PcDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdispatchirp)