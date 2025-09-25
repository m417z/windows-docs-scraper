# EVT_WDFDEVICE_WDM_PRE_PO_FX_UNREGISTER_DEVICE callback function

## Description

[Applies to KMDF only]

 The
*EvtDeviceWdmPrePoFxUnregisterDevice* callback function performs device-specific operations before the framework deletes a specified registration with the power framework.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PoHandle` [in]

A handle that represents the device’s registration with the power framework.

## Remarks

The *EvtDeviceWdmPrePoFxUnregisterDevice* callback function applies only to single-component devices.

To register an *EvtDeviceWdmPrePoFxUnregisterDevice* callback function, a driver must call [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

A driver can provide this callback function if it must perform any additional operations before the framework unregisters the specified POHANDLE.

 After the driver has returned from this callback, it is no longer safe to use this POHANDLE.

## See also

[EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device)

[WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings)