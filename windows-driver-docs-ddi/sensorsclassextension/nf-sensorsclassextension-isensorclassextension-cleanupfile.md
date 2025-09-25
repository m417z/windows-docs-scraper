# ISensorClassExtension::CleanupFile

## Description

The [ISensorClassExtension::CleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-cleanupfile) method notifies the class extension about a file handle that closes and cancels all pending I/O requests, for the specified application.

## Parameters

### `pWdfFile`

Pointer to an IWDFFile interface that represents the file object for the application being closed.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

|Return code|Description|
|--- |--- |
|S_OK|The method succeeded.|
|E_POINTER|A required pointer argument was NULL.|
|HRESULT_FROM_WIN32(ERROR_CAN_NOT_COMPLETE)|The class extension is not initialized.|

## Remarks

Your driver must call this method to forward [IFileCallbackCleanup::OnCleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackcleanup-oncleanupfile) method calls from UMDF. You receive this call any time that a file handle closes. Typically, you receive this call after an application stops responding.

When finished, the sensor class extension calls the driver in [ISensorDriver::OnClientDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientdisconnect), and [ISensorDriver::OnClientUnsubscribeFromEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientunsubscribefromevents), if applicable.

## See also

[ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)