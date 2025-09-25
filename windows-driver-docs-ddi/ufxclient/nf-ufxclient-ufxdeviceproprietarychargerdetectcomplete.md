# UfxDeviceProprietaryChargerDetectComplete function

## Description

Notifies UFX about a detected proprietary port/charger type.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `DetectedCharger` [in]

A pointer to a [UFX_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/ns-ufxproprietarycharger-_ufx_proprietary_charger) structure.

## Remarks

The client driver calls **UfxDeviceProprietaryChargerDetectComplete** after attempting to detect a proprietary charger on the upstream port, typically from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

 Do not call **UfxDeviceProprietaryChargerDetectComplete** before UFX calls the client driver's [EVT_UFX_DEVICE_DETECT_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_detect) callback function.

The following snippet shows how a client driver calls **UfxDeviceProprietaryChargerDetectComplete**:

```
    UfxDeviceProprietaryChargerDetectComplete(
        ChargerContext->UfxDevice,
        &pControllerData->DetectedCharger);

```