# NdisRegisterDeviceEx function

## Description

The
**NdisRegisterDeviceEx** function creates a device object that is based upon the specified
attributes.

## Parameters

### `NdisHandle` [in]

A miniport driver handle or filter driver handle that the caller obtained by calling the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function or the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function respectively.

### `DeviceObjectAttributes` [in]

A pointer to an
[NDIS_DEVICE_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_device_object_attributes) structure that contains the attributes for the new device.

### `pDeviceObject` [out]

A pointer that points to a pointer to a newly created
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure, if the call succeeds.
If the call fails,
*pDeviceObject* is set to point to **NULL**.

### `NdisDeviceHandle` [out]

A pointer to a caller-supplied variable in which this function, if it succeeds, returns a handle
to the device object. This handle is a required parameter to the
[NdisDeregisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterdeviceex) function
that the driver calls subsequently.

## Return value

**NdisRegisterDeviceEx** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisRegisterDeviceEx** successfully registered the device. |
| **NDIS_STATUS_NOT_SUPPORTED** | The caller is not an NDIS driver. |
| **NDIS_STATUS_*XXX* or NTSTATUS_*XXX*** | The driver's attempt to register the device failed. Usually, such an error status is propagated from an **Ndis*Xxx*** function or a kernel-mode support routine. |

## Remarks

Miniport drivers and filter drivers can call
**NdisRegisterDeviceEx** to register a virtual device.

**Note** NDIS drivers must not modify the
**DeviceExtension** member of the
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that
**NdisRegisterDeviceEx** created.

If an NDIS driver requires space for context information in the device object, the driver can pass a
nonzero value for the
**ExtensionSize** member in the
[NDIS_DEVICE_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_device_object_attributes) structure at the
*DeviceObjectAttributes* parameter. In this case, NDIS allocates the extension for the driver, and
the driver can call the
[NdisGetDeviceReservedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetdevicereservedextension) function to get a pointer to the extension.

The driver must subsequently call the
[NdisDeregisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterdeviceex) function
when the device is no longer needed. If
**NdisRegisterDeviceEx** allocated an extension,
**NdisDeregisterDeviceEx** frees the extension.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[NDIS_DEVICE_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_device_object_attributes)

[NdisDeregisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterdeviceex)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisGetDeviceReservedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetdevicereservedextension)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)