# ISensorClassExtension::Uninitialize

## Description

The [ISensorClassExtension::Uninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-uninitialize) method uninitializes the sensor class extension object.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

|Return code|Description|
|--- |--- |
|S_OK|The method succeeded.|
|HRESULT_FROM_WIN32(ERROR_CAN_NOT_COMPLETE)|The class extension is not initialized.|

## Remarks

Typically, you will uninitialize the sensor class extension when the driver is unloading. We recommend that you perform uninitialization steps when called by UMDF in [IPnpCallbackHardware::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onreleasehardware).

If you must, for some reason, otherwise release and uninitialize the sensor class extension, you must call [IWDFIoQueue::DrainSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drainsynchronously) before calling [ISensorClassExtension::Uninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-uninitialize). You can retrieve the queue interface by calling [IWDFDevice::GetDefaultIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-getdefaultioqueue) on the WDF device object. Then, call **IWDFIoQueue::DrainSynchronously** to process all the queued requests. Calling **IWDFIoQueue::DrainSynchronously** blocks the queuing of new requests, so you must call [IWDFIoQueue::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-start) after you reinitialize the class extension.

## See also

[ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)