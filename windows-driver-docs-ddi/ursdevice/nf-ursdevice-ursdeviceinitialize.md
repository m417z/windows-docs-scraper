# UrsDeviceInitialize function

## Description

Initializes a framework device object to support operations related to a USB dual-role controller and registers the relevant event callback functions with the USB dual-role controller class extension.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

 A pointer to a [URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config) structure that the client driver initialized by calling [URS_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urs_config_init).

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The client driver for the USB dual-role controller must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call.

The client driver calls this method in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) implementation.

During this call, the client driver-supplied event callback implementations are also registered by setting appropriate members of [URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config).

The method creates resource lists for host and function roles and the queues required to handle IOCTL requests that are sent to the controller. With each role switch operation, the current role's child device stack is torn down and the device stack for the new role is loaded. The **UrsDeviceInitialize** method retrieves identifying information that is used to build those device stacks. The method also retrieves information about the device from the underlying bus, such as ACPI.

#### Examples

```

EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtUrsFilterResourceRequirements;
EVT_URS_SET_ROLE EvtUrsSetRole;

EvtDriverDeviceAdd (
    _In_ WDFDRIVER Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
{
...

    WDFDEVICE device;
    NTSTATUS status;
    WDF_OBJECT_ATTRIBUTES attributes;
    URS_CONFIG ursConfig;
...

    status = UrsDeviceInitInitialize(DeviceInit);
    if (!NT_SUCCESS(status)) {
        //UrsDeviceInitInitialize failed.
        return status;
    }

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, DRIVER_CONTEXT);
    status = WdfDeviceCreate(&DeviceInit, &attributes, &device);
    if (!NT_SUCCESS(status)) {
        // WdfDeviceCreate failed.
        return status;
    }
    URS_CONFIG_INIT(&ursConfig, UrsHostInterfaceTypeXhci, EvtUrsFilterResourceRequirements);

    ursConfig.EvtUrsSetRole = EvtUrsSetRole;
    status = UrsDeviceInitialize(device, &ursConfig);

    if (!NT_SUCCESS(status)) {
        // UrsDeviceInitialize failed.
        return status;

    }

...

}

```

## See also

[URS_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/ns-ursdevice-_urs_config)

[URS_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urs_config_init)