# WdfFdoInitSetDefaultChildListConfig function

## Description

[Applies to KMDF only]

The **WdfFdoInitSetDefaultChildListConfig** method configures a bus driver's default child list.

## Parameters

### `DeviceInit` [in, out]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `Config` [in]

A pointer to a driver-allocated [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure.

### `DefaultChildListAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the child-list object that represents the driver's default child list. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

## Remarks

A bus driver must call **WdfFdoInitSetDefaultChildListConfig** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) for the functional device object (FDO). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about the **WdfFdoInitSetDefaultChildListConfig** method, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

#### Examples

The following code example initializes a [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure and then calls **WdfFdoInitSetDefaultChildListConfig**.

```cpp
WDF_CHILD_LIST_CONFIG  config;

WDF_CHILD_LIST_CONFIG_INIT(
                           &config,
 sizeof(MY_IDENTIFICATION_DESCRIPTION),
                           My_EvtDeviceListCreatePdo
                           );
config.EvtChildListIdentificationDescriptionDuplicate = My_EvtChildListIdentificationDescriptionDuplicate;
config.EvtChildListIdentificationDescriptionCompare = My_EvtChildListIdentificationDescriptionCompare;
config.EvtChildListIdentificationDescriptionCleanup = My_EvtChildListIdentificationDescriptionCleanup;

WdfFdoInitSetDefaultChildListConfig(
                                    DeviceInit,
                                    &config,
                                    WDF_NO_OBJECT_ATTRIBUTES
                                    );
```

## See also

[WDF_CHILD_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_config_init)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)