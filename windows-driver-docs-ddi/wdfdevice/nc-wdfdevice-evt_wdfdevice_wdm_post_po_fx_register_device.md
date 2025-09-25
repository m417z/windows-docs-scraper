# EVT_WDFDEVICE_WDM_POST_PO_FX_REGISTER_DEVICE callback function

## Description

[Applies to KMDF only]

 The
*EvtDeviceWdmPostPoFxRegisterDevice* callback function performs device-specific operations after the framework has registered with the power framework.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PoHandle` [in]

A handle that represents the device’s registration with the power framework.

## Return value

An NTSTATUS value indicating success or failure of the operations performed in this callback. If failure is returned, the framework in turn will fail [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device).

## Remarks

If you are writing a KMDF driver for a single-component device that defines multiple functional power states, you can register an *EvtDeviceWdmPostPoFxRegisterDevice* callback function to receive notification after the framework registers with the power management framework (PoFx).

To register *EvtDeviceWdmPostPoFxRegisterDevice*, a driver must call [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

The POHANDLE received in *EvtDeviceWdmPostPoFxRegisterDevice* remains valid until the driver returns from [EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device).

Your driver can use the POHANDLE to call [PoFxSetComponentLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetcomponentlatency), [PoFxSetComponentResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetcomponentresidency), and [PoFxSetComponentWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetcomponentwake) to specify latency, residency, and wake hints to the power framework.

Your driver can also use the POHANDLE to call [PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol) to send a power control request to PoFx.

A KMDF driver for a multiple component device does not provide *EvtDeviceWdmPostPoFxRegisterDevice*. Instead, such a driver receives the POHANDLE when it calls *PoFxRegisterDevice*. For more information, see [Supporting Multiple Functional Power States for Multiple-Component Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-multiple-functional-power-states-for-multiple-component-devices).

## See also

[EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device)

[WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings)