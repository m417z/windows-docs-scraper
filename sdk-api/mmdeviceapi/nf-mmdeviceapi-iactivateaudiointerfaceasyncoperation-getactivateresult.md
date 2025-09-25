# IActivateAudioInterfaceAsyncOperation::GetActivateResult

## Description

Gets the results of an asynchronous activation of a [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) interface initiated by an application calling the [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync) function.

## Parameters

### `activateResult` [out]

### `activatedInterface` [out]

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_ILLEGAL_METHOD_CALL** | The method was called before the asynchronous operation was complete. |

## Remarks

An application calls this method after Windows calls the [ActivateCompleted](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-iactivateaudiointerfacecompletionhandler-activatecompleted) method of the application’s [IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler) interface.

The result code returned through *activateResult* may depend on the requested interface. For additional information, see [IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate). A result code of **E_ACCESSDENIED** might indicate that the user has not given consent to access the device in a manner required by the requested [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) interface.

The returned *activatedInterface* may be **NULL** if *activateResult* is not a success code.

## See also

[ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync)

[IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation)