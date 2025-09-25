# _NDIS_DEVICE_OBJECT_ATTRIBUTES structure

## Description

The NDIS_DEVICE_OBJECT_ATTRIBUTES structure defines the attributes of a device that an NDIS filter or
miniport driver can pass to the
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_DEVICE_OBJECT_ATTRIBUTES structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEVICE_OBJECT_ATTRIBUTES, the
**Revision** member to NDIS_DEVICE_OBJECT_ATTRIBUTES_REVISION_1, and the
**Size** member to NDIS_SIZEOF_DEVICE_OBJECT_ATTRIBUTES_REVISION_1.

### `DeviceName`

A pointer to a variable of type NDIS_STRING that contains a null-terminated Unicode string that
names the device object. The string must be a full path name--for example,
\Device\\*DeviceName*. For Microsoft Windows 2000 and later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `SymbolicName`

A pointer to a variable of type NDIS_STRING that contains a Unicode string that is the
Win32-visible name of the device being registered. Typically,
**SymbolicName** has the following format:
\DosDevices\\*SymbolicName*.

### `MajorFunctions`

A pointer to an array of one or more entry points for the device driver's dispatch routines. A
driver must set the same number of separate dispatch entry points as the number of IRP_MJ_*XXX* codes that the driver handles for the device object. Each dispatch routine is declared as
follows:

```
NTSTATUS
  (*PDRIVER_DISPATCH) (
    IN PDEVICE_OBJECT  DeviceObject,
    IN PIRP  Irp
);
```

The dispatch routine has the following parameters:

#### DeviceObject

The device object for the dispatch routine.

#### Irp

The IRP for the dispatch routine.

A driver must not supply entry points for PnP or Power Management handlers, because the created
device object is not for a physical device and therefore does not receive PnP or Power Management
IRPs.

### `ExtensionSize`

The driver-determined number of bytes to be allocated for the device extension of the device
object. The internal structure of the device extension is driver-defined.

### `DefaultSDDLString`

A string representation for the default security settings of the device object. The security that
is applied to the device object is derived from this string.

The security setting is specified in a subset of Security Descriptor Definition Language (SDDL). A
set of predefined constants (SDDL_DEVOBJ_*XXX*) is also provided. For more information, see
[Securing Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/securing-device-objects).

### `DeviceClassGuid`

Reserved for NDIS. Set this member to **NULL**.

## Remarks

An NDIS filter or miniport driver can call the
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex) function to
register a device. To specify the device attributes, the driver allocates and initializes an
NDIS_DEVICE_OBJECT_ATTRIBUTES structure and passes the structure to the
*DeviceObjectAttributes* parameter of
**NdisRegisterDeviceEx**.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)