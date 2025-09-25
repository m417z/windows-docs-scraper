# EVT_UFX_DEVICE_PROPRIETARY_CHARGER_DETECT callback function

## Description

The client driver's implementation to initiate proprietary charger detection.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

## Remarks

*EVT_UFX_DEVICE_DETECT_PROPRIETARY_CHARGER* is an optional event callback. The client driver is required to implement this event callback only if it supports proprietary charger detection. The driver indicates support in the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) call by setting **PdcpSupported** to TRUE in [UFX_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxbase/ns-ufxbase-_ufx_device_capabilities). If the client driver does not support the functionality, the **EvtDeviceProprietaryChargerDetect**, **EvtDeviceProprietaryChargerSetProperty**, and **EvtDeviceProprietaryChargerReset**
members of the [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) structure must be set to NULL in **UfxDeviceCreate**.

The client driver indicates completion of this event by calling the [UfxDeviceProprietaryChargerDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceproprietarychargerdetectcomplete) method.

The client driver sends a request to the lower filter driver to determine if a proprietary charger is present. In response, the filter driver provides a GUID for each charger type it supports, and a list of that charger's properties. If a specific charger is configurable, the filter driver also provides a list of supported PropertyIDs and their possible values to configure the charger.

## See also

- [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)
- [UfxDeviceProprietaryChargerDetectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceproprietarychargerdetectcomplete)