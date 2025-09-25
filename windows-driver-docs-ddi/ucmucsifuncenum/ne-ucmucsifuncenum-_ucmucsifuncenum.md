# _UCMUCSIFUNCENUM enumeration

## Description

Defines values for all export functions called by a client driver of a UcmUcsiCx class extension.

## Constants

### `UcmUcsiDeviceInitInitializeTableIndex`

UcmUcsiDeviceInitInitialize - initializes the **WDFDEVICE_INIT** provided by the framework.

### `UcmUcsiDeviceInitializeTableIndex`

UcmUcsiDeviceInitialize - initializes the UcmUcsiCx class extension.

### `UcmUcsiConnectorCollectionCreateTableIndex`

UcmUcsiConnectorCollectionCreate - creates a connector collection object with UcmUcsiCx.

### `UcmUcsiConnectorCollectionAddConnectorTableIndex`

UcmUcsiConnectorCollectionAddConnector - adds a connector to the connector collection object.

### `UcmUcsiPpmCreateTableIndex`

UcmUcsiPpmCreate - creates a Platform Policy Manager (PPM) object.

### `UcmUcsiPpmSetUcsiCommandRequestQueueTableIndex`

UcmUcsiPpmSetUcsiCommandRequestQueue - provides a framework queue object that is used to dispatch UCSI commands to the client driver.

### `UcmUcsiPpmStartTableIndex`

UcmUcsiPpmStart - instructs the class extension to start sending requests to the client driver.

### `UcmUcsiPpmStopTableIndex`

UcmUcsiPpmStop - instructs the class extension to stop sending requests to the client driver.

### `UcmUcsiPpmNotificationTableIndex`

UcmUcsiPpmNotification - informs the UcmUcsiCx class extension about a UCSI notification.

### `UcmucsiFunctionTableNumEntries`

End of this enumeration.

## Remarks

## See also

[Ucmucsicx.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsicx/)