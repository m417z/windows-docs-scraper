# ISensorClassExtension::ProcessIoControl

## Description

The [ISensorClassExtension::ProcessControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-processiocontrol) method sends Windows Portable Devices (WPD) I/O control requests to the sensor class extension for processing.

## Parameters

### `pRequest`

Pointer to the IWDFIoRequest interface that represents the UMDF request object.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

|Return code|Description|
|--- |--- |
|S_OK|The method succeeded.|
|E_ACCESS_DENIED|No permission. For example, the I/O request sought data for which no permission exists.|
|E_POINTER|A required pointer argument was NULL.|
|HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)|The request did not contain a WPD IOCTL.|

## Remarks

UMDF sends I/O control requests to sensor drivers through [IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol). We recommend that you call ProcessIoControl to forward all WPD requests to the sensor class extension for processing. You can use the WPD macro IS_WPD_IOCTL to determine whether a given control code is specific to WPD. Clients of the Sensor API and Location API send only WPD IOCTLs, which can always be process by the sensor class extension.

After processing an I/O control request, the sensor class extension uses the driver's callback interface, [ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver), to provide notifications, as appropriate. WPD requests that the sensor class extension does not handle by default are sent to the driver through [ISensorDriver::OnProcessWpdMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onprocesswpdmessage).

The driver must not complete I/O control requests that it forwards to the sensor class extension.

## See also

[ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)