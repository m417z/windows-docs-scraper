# PGET_LOCATION_STRING callback function

## Description

The *PnpGetLocationString* routine provides the device-specific part of the device's SPDRP_LOCATION_PATHS property.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [PNP_LOCATION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pnp_location_interface) structure.

### `LocationStrings` [out]

A pointer to a sequence of null-terminated Unicode strings, that is terminated by another zero. Each string serves as a location string for the device. Drivers typically return a single string.

## Return value

The routine returns an NTSTATUS value to indicate the status of the operation.

## Remarks

The [PNP_LOCATION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pnp_location_interface) structure supplies a pointer to the *PnpGetLocationString* routine.

The *PnpGetLocationString* routine provides the device-specific part of the location string for the device. The Plug and Play (PnP) manager assembles the location string for a device by querying the driver for the device, for the device's bus, and any parent buses, and concatenating the provided strings together.

The routine must return a string that is unique to the device relative to its bus. The string must be the same for the device across all versions of the operating system. Once you select a string for this purpose, you must not change it.

By convention, the location string takes the form *ServiceName(BusSpecificLocation)*. For example, PCI devices use PCI(*XXYY*), where *XX* is the device number, and *YY* is the function number.

The *PnpGetLocationString* routine calls a routine such as [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) to allocate the memory for the location string. The caller is responsible for calling the [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) routine to free the memory pointed to by *LocationStrings* when the location string is no longer needed.

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[PNP_LOCATION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pnp_location_interface)