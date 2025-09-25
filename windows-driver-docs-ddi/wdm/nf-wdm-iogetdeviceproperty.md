# IoGetDeviceProperty function

## Description

The **IoGetDeviceProperty** routine retrieves information about a device such as configuration information and the name of its PDO.

## Parameters

### `DeviceObject` [in]

Pointer to the physical device object (PDO) for the device being queried.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator that identifies the device property to be retrieved.

### `BufferLength` [in]

Specifies the size, in bytes, of the caller-supplied *PropertyBuffer*.

### `PropertyBuffer` [out, optional]

Pointer to a caller-supplied buffer to receive the property information. The buffer can be allocated from pageable memory. The type of the buffer is determined by the *DeviceProperty* (see above).

### `ResultLength` [out]

Pointer to a ULONG to receive the size of the property information returned at *PropertyBuffer*. If **IoGetDeviceProperty** returns STATUS_BUFFER_TOO_SMALL, it sets this parameter to the required buffer length.

## Return value

**IoGetDeviceProperty** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following.

|Return code|Description|
|----|----|
|**STATUS_BUFFER_TOO_SMALL**|The buffer at *PropertyBuffer* was too small. *ResultLength* points to the required buffer length.|
|**STATUS_INVALID_PARAMETER_2**|The given *DeviceProperty* is not one of the properties handled by this routine.|
|**STATUS_INVALID_DEVICE_REQUEST**|Possibly indicates that the given *DeviceObject* was not a valid PDO pointer.|

## Remarks

**IoGetDeviceProperty** retrieves device setup information from the registry. Use this routine, rather than accessing the registry directly, to insulate a driver from differences across platforms and from possible changes in the registry structure.

For many *DeviceProperty* requests, it can take two or more calls to **IoGetDeviceProperty** to determine the required *BufferLength*. The first call should use a best-guess value. If the return status is STATUS_BUFFER_TOO_SMALL, the driver should free its current buffer, allocate a buffer of the size returned in *ResultLength*, and call **IoGetDeviceProperty** again. Because some of the setup properties are dynamic, the data size can change between the time the required size is returned and driver calls this routine again. Therefore, drivers should call **IoGetDeviceProperty** inside a loop that runs until the return status is not STATUS_BUFFER_TOO_SMALL.

Function drivers that support devices on a legacy bus and a PnP bus can use the **DevicePropertyBusNumber**, **DevicePropertyBusTypeGuid**, and **DevicePropertyLegacyBusType** properties to distinguish between the buses.

## See also

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[DEVICE_REMOVAL_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_device_removal_policy)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[GUID](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-shell-setup-notificationarea-promotedicon2-guid)

[INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type)

[IO_RESOURCE_REQUIREMENTS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_requirements_list)