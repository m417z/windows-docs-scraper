# WdfWmiInstanceCreate function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceCreate** method creates a WMI instance object that represents an instance of a WMI data provider.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the device that the instance is being created for. The device object cannot be a [control device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

### `InstanceConfig` [in]

A pointer to a caller-initialized [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure, which contains configuration information for an instance of a WMI data provider.

### `InstanceAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied object attributes for the new WMI instance object. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Instance` [out, optional]

A pointer to a location that receives a handle to the new WMI instance object. This parameter is optional and can be **NULL**.

## Return value

**WdfWmiInstanceCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure that the *InstanceConfig* parameter points to was incorrect. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_INTEGER_OVERFLOW** | The driver set the **UseContextForQuery** member of the [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure to **TRUE** but specified a context space size that is larger than ULONG_MAX in the *InstanceAttributes* parameter's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. |

For a list of other return values that the **WdfWmiInstanceCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver is creating multiple instances of a provider, the driver must call [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) to create a provider object before calling **WdfWmiInstanceCreate**. The driver passes the provider object's handle to **WdfWmiInstanceCreate** by placing the handle in a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure. (If the driver supplies a provider object handle, the *Device* parameter is not used and can be **NULL**.)

If the driver is creating a single instance of a provider, it does not have to call **WdfWmiInstanceCreate** before calling **WdfWmiInstanceCreate**. In this case, **WdfWmiInstanceCreate** also creates a WMI provider object. Therefore, the driver's WDF_WMI_INSTANCE_CONFIG structure must include a pointer to a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure that describes the WMI data provider.

The framework instructs WMI to create a dynamic instance name, which applications can use, from the device instance ID of the driver's physical device object (PDO). (The framework does not support static instance names that Windows Driver Model (WDM) drivers set in an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) structure.)

The WMI instance object's parent is the WMI provider object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

After the driver calls **WdfWmiInstanceCreate**, it can call [WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider) to obtain a handle to the parent provider object and [WdfWmiInstanceGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetdevice) to obtain a handle to the provider's device.

For more information about the **WdfWmiInstanceCreate** method, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

If the **Register** member of the [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure that *InstanceConfig* points to is **TRUE**, **WdfWmiInstanceCreate** registers the provider instance synchronously (that is, before returning) if this method is called at IRQL = PASSIVE_LEVEL and asynchronously if it is called at IRQL > PASSIVE_LEVEL.

#### Examples

The following code example is from the [PCIDRV](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example registers a MOF resource name for a device, initializes a WDF_WMI_PROVIDER_CONFIG structure and a WDF_WMI_INSTANCE_CONFIG structure, and calls **WdfWmiInstanceCreate**.

```cpp
NTSTATUS
PciDrvWmiRegistration(
    WDFDEVICE  Device
    )
{
    WDF_WMI_PROVIDER_CONFIG  providerConfig;
    WDF_WMI_INSTANCE_CONFIG  instanceConfig;
    NTSTATUS  status;
    DECLARE_CONST_UNICODE_STRING(mofRsrcName, MOFRESOURCENAME);

    status = WdfDeviceAssignMofResourceName(
                                            Device,
                                            &mofRsrcName
                                            );
    if (!NT_SUCCESS(status)) {
        return status;
    }
    WDF_WMI_PROVIDER_CONFIG_INIT(
                                 &providerConfig,
                                 &PCIDRV_WMI_STD_DATA_GUID
                                 );
    providerConfig.MinInstanceBufferSize = sizeof(PCIDRV_WMI_STD_DATA);

    WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG(
                                                 &instanceConfig,
                                                 &providerConfig
                                                 );
    instanceConfig.Register = TRUE;
    instanceConfig.EvtWmiInstanceQueryInstance = EvtWmiDeviceInfoQueryInstance;
    instanceConfig.EvtWmiInstanceSetInstance = EvtWmiDeviceInfoSetInstance;

    status = WdfWmiInstanceCreate(
                                  Device,
                                  &instanceConfig,
                                  WDF_NO_OBJECT_ATTRIBUTES,
                                  WDF_NO_HANDLE
                                  );
    if (!NT_SUCCESS(status)) {
        return status;
    }
    return status;
}
```

## See also

[IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider_config)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WDF_WMI_PROVIDER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_provider_config_init)

[WdfDeviceAssignMofResourceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignmofresourcename)

[WdfWmiInstanceGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetdevice)

[WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)