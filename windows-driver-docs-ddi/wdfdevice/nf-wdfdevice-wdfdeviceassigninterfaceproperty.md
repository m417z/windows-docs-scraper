## Description

> [!IMPORTANT]
> Applies to UMDF only

The **WdfDeviceAssignInterfaceProperty** method modifies the current value of a [device interface property](https://learn.microsoft.com/windows-hardware/drivers/install/accessing-device-interface-properties).

> [!NOTE]
> To retrieve or modify a device interface property, a KMDF driver must call [**IoGetDeviceInterfacePropertyData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfacepropertydata) or [**IoSetDeviceInterfacePropertyData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacepropertydata) directly.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PropertyData` [in]

A pointer to [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure.

### `Type` [in]

A **DEVPROPTYPE**-typed value that specifies the type of the data that is provided in *PropertyBuffer*.

### `BufferLength` [in]

Specifies the length, in bytes, of the buffer that *PropertyBuffer* points to.

### `PropertyBuffer` [in, optional]

A pointer to the device interface property data. Set this parameter to **NULL** to delete the specified property.

## Return value

If the **WdfDeviceAssignInterfaceProperty** method encounters no errors, it returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
|--|--|
| **STATUS_INVALID_PARAMETER** | One of the parameters is incorrect. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For information about related methods, see [Accessing the Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-the-unified-device-property-model).

### Examples

The following code example initializes a [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure and then calls **WdfDeviceAssignInterfaceProperty**.

```cpp
DEFINE_DEVPROPKEY(DEVPKEY_ToasterCrispLevelDword, 0x5d0ba64a, 0x2396, 0x4bc9, 0xbf, 0x49, 0x52, 0x1d, 0xa6, 0x2b, 0x1b, 0xed, 3);  // DEVPROP_TYPE_UINT32

ULONG crispLevel = 0;
WDF_DEVICE_INTERFACE_PROPERTY_DATA propertyData;

WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT(
                          &propertyData,
                          &GUID_DEVINTERFACE_TOASTER_DRIVER
                          &DEVPKEY_ToasterCrispLevelDword
                          );

status = WdfDeviceAssignInterfaceProperty(device,
                                          &propertData,
                                          DEVPROP_TYPE_UINT32,
                                          sizeof(crispLevel),
                                          &crispLevel);
if (!NT_SUCCESS(status)) {
    return status;
}

```

## See also

[WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data)

[WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_interface_property_data_init)

[WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)

[WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)