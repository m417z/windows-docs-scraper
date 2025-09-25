## Description

The **IWiaMiniDrv::drvNotifyPnpEvent** method responds to the event received from the WIA service.

## Parameters

### `pEventGUID` [in]

Points to a GUID identifying the event.

### `bstrDeviceID` [in]

Specifies a string containing the device's unique identifier.

### `ulReserved` [in]

Reserved.

## Return value

On success, the method should return **S_OK**. If the method fails, it should return a standard COM error code.

## Remarks

The WIA service notifies a WIA minidriver of a supported device event by calling the **IWiaMiniDrv::drvNotifyPnpEvent** method. In this method the minidriver implements the device-specific functionality needed to respond to the event.

If this method is called with **pEventGuid* set to [WIA_EVENT_CANCEL_IO](https://learn.microsoft.com/windows/win32/wia/-wia-wia-event-identifiers) device event, it should cancel all current I/O operations as soon as possible.

## See also

[IWiaMiniDrv](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrv)

[IWiaMiniDrv::drvGetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetcapabilities)