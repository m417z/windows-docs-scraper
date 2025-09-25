# WdfFdoInitAllocAndQueryPropertyEx function

## Description

[Applies to KMDF and UMDF]

The **WdfFdoInitAllocAndQueryPropertyEx** method allocates a buffer and retrieves a specified device property.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `DeviceProperty` [in]

A pointer to a [WDF_DEVICE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_property_data) structure that identifies the device property to be retrieved.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed enumerator that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that the function will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

### `Type` [out]

A pointer to a **DEVPROPTYPE** variable. If the method is successful, upon return this parameter contains the property type value
of the property
data stored in *PropertyMemory*.

## Return value

If the operation succeeds, **WdfFdoInitAllocAndQueryPropertyEx** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The specified *DeviceProperty* value is invalid. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfFdoInitAllocAndQueryPropertyEx** method determines the amount of memory that is necessary to hold the requested device interface property. It allocates enough memory to hold the data, and returns a handle to a framework memory object that describes the allocated memory. To access the data, your driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

The driver can call **WdfFdoInitAllocAndQueryPropertyEx** only before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

After calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), a driver can obtain device property information by calling [WdfDeviceAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandquerypropertyex).

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

## See also

[WdfFdoInitAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandqueryproperty)