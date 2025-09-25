# UrsSetPoHandle function

## Description

Registers and deletes the client driver's registration with the power management framework (PoFx).

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `PoHandle` [in]

A handle that represents the registration of the device with PoFx. The client driver receives this handle from WDF in [EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device) and [EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device) callback functions.

## Remarks

The client driver for the dual-role controller must be the power policy owner. The driver can receive notifications from the power management framework (PoFx). To do so, after calling [UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize), the driver must register PoFx callback functions. The client driver registers the device with the power framework directly or obtains a POHANDLE from WDF in [EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device). After registration is successful, the driver provides that handle to the USB dual-role class extension.

In the client driver's implementation of the [EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device) callback function, the driver is expected to call **UrsSetPoHandle** by passing the received handle. On some platforms, the class extension might use the POHANDLE to power-manage the controller. Conversely, before the class extension deletes the registration with the power framework, it invokes the client driver's [EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device) implementation. The driver is expected to call **UrsSetPoHandle** by passing NULL as the PoHandle value.

#### Examples

```

EVT_WDFDEVICE_WDM_POST_PO_FX_REGISTER_DEVICE EvtDevicePostPoFxRegister;

EVT_WDFDEVICE_WDM_PRE_PO_FX_UNREGISTER_DEVICE EvtDevicePrePoFxUnregister;

EvtDriverDeviceAdd (
    _In_ WDFDRIVER Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
{
...

    WDFDEVICE device;
    NTSTATUS status;
...

    WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS idleSettings;
    WDF_POWER_FRAMEWORK_SETTINGS poFxSettings;
...

    TRY {

        WDF_POWER_FRAMEWORK_SETTINGS_INIT(&poFxSettings);
        poFxSettings.EvtDeviceWdmPostPoFxRegisterDevice = EvtDevicePostPoFxRegister;
        poFxSettings.EvtDeviceWdmPrePoFxUnregisterDevice = EvtDevicePrePoFxUnregister;

        status = WdfDeviceWdmAssignPowerFrameworkSettings(device, &poFxSettings);
        if (!NT_SUCCESS(status)) {
            // WdfDeviceWdmAssignPowerFrameworkSettings failed.

        }

        WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(&idleSettings, IdleCannotWakeFromS0);
        idleSettings.IdleTimeoutType = SystemManagedIdleTimeout;

        status = WdfDeviceAssignS0IdleSettings(device, &idleSettings);
        if (!NT_SUCCESS(status)) {
            // WdfDeviceAssignS0IdleSettings failed.

        }

    } FINALLY {
    }

..

}

NTSTATUS
EvtDevicePostPoFxRegister (
    _In_ WDFDEVICE Device,
    _In_ POHANDLE PoHandle
    )
{
    UrsSetPoHandle(Device, PoHandle);

    return STATUS_SUCCESS;
}

VOID
EvtDevicePrePoFxUnregister (
    _In_ WDFDEVICE Device,
    _In_ POHANDLE PoHandle
    )
{
    UNREFERENCED_PARAMETER(PoHandle);

    UrsSetPoHandle(Device, NULL);
}

```

## See also

[EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device)

*EvtDeviceWdmPrePoFxUnregisterDevice*