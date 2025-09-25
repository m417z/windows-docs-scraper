# WdfFdoInitAllocAndQueryProperty function

## Description

[Applies to KMDF and UMDF]

The **WdfFdoInitAllocAndQueryProperty** method allocates a buffer and retrieves a specified device property.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator value that identifies the device property to be retrieved.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed enumerator value that specifies the type of memory to be allocated.

### `PropertyMemoryAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes object attributes for the memory object that **WdfFdoInitAllocAndQueryProperty** will allocate. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PropertyMemory` [out]

A pointer to a WDFMEMORY-typed location that receives a handle to a framework memory object.

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER or STATUS_INVALID_PARAMETER_2** | The specified *DeviceProperty* value is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure was not obtained from driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The driver must call **WdfFdoInitAllocAndQueryProperty** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

After calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), a driver can obtain device property information by calling [WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty).

For more information about the **WdfFdoInitAllocAndQueryProperty** method, see [Creating Device Objects in a Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-function-driver).

Alternatively, you can use [WdfFdoInitAllocAndQueryPropertyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitallocandquerypropertyex) to access device properties that are exposed through the Unified Property Model.

#### Examples

The following code example calls **WdfFdoInitAllocAndQueryProperty** to obtain a handle to a framework memory object that contains the name of a device's setup class. Then, the example calls [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer) to obtain a pointer to the buffer that contains the setup class name's Unicode string.

```cpp
NTSTATUS  status = STATUS_SUCCESS;
PVOID  pMemoryBuffer = NULL;
WDFMEMORY  memory = NULL;

status = WdfFdoInitAllocAndQueryProperty(
                                         DeviceInit,
                                         DevicePropertyClassName,
                                         NonPagedPool,
                                         WDF_NO_OBJECT_ATTRIBUTES,
                                         &memory
                                         );
if(NT_SUCCESS(status)){
 pMemoryBuffer = WdfMemoryGetBuffer(
                                    memory,
                                    NULL
                                    );
}
```

## See also

[WdfDeviceAllocAndQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryproperty)

[WdfFdoInitQueryProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitqueryproperty)