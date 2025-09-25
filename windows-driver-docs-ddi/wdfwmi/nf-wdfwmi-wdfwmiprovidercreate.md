# WdfWmiProviderCreate function

## Description

[Applies to KMDF only]

The **WdfWmiProviderCreate** method creates a WMI provider object that represents a WMI data block.

## Parameters

### `Device` [in]

A handle to a framework device object that will be the new provider object's parent object. The device object cannot be a [control device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

### `WmiProviderConfig` [in]

A pointer to a caller-initialized [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure that contains configuration information about the WMI data block.

### `ProviderAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied object attributes for the new WMI provider object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `WmiProvider` [out]

A pointer to a location that receives a handle to the new WMI provider object.

## Return value

**WdfWmiProviderCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure that the *WmiProviderConfig* parameter pointed to was incorrect. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory to complete the operation. |
| **STATUS_OBJECT_NAME_EXISTS** | The driver has already called [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) for the specified device and WMI data block. |

For a list of other return values that the **WdfWmiProviderCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver must call **WdfWmiProviderCreate** to create a WMI provider object if the driver will create multiple instances of the provider. If the driver will create only one instance of the provider, it can call [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate) without first calling **WdfWmiProviderCreate**.

A driver can call **WdfWmiProviderCreate** at any time, but drivers typically call **WdfWmiProviderCreate** from within their [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback functions.

The parent of each WMI provider object is the device's framework device object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

After a driver calls **WdfWmiProviderCreate**, the driver can call [WdfWmiProviderGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidergetdevice) to retrieve a handle to the provider object's parent device object.

After a driver creates a WMI provider object, the driver cannot delete the object. The framework deletes a device's WMI provider objects when it deletes the framework device object that represents the device. WMI provider objects use minimal system resources.

For more information about the **WdfWmiProviderCreate** method, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

#### Examples

The following code example initializes a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure and calls **WdfWmiProviderCreate**.

```cpp
WDF_WMI_PROVIDER_CONFIG config;
WDFWMIPROVIDER provider;
GUID providerGuid = MY_WMI_DATA_BLOCK_GUID;
NTSTATUS status;

WDF_WMI_PROVIDER_CONFIG_INIT(
                             &config,
                             providerGuid
                             );
config.Flags = WdfWmiProviderTracing;
config.EvtWmiProviderFunctionControl = MyProviderFunctionControl;

status = WdfWmiProviderCreate(
                              Device,
                              &config,
                              WDF_NO_OBJECT_ATTRIBUTES,
                              &provider
                              );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiProviderGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidergetdevice)