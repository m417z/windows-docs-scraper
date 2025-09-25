# IActivateAudioInterfaceCompletionHandler::ActivateCompleted

## Description

Indicates that activation of a [WASAPI](https://learn.microsoft.com/windows/desktop/CoreAudio/wasapi) interface is complete and results are available.

## Parameters

### `activateOperation` [in]

An interface representing the asynchronous operation of activating the requested **WASAPI** interface

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

An application implements this method if it calls the [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync) function. When Windows calls this method, the results of the activation are available. The application can then retrieve the results by calling the [GetActivateResult](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-iactivateaudiointerfaceasyncoperation-getactivateresult) method of the [IActivateAudioInterfaceAsyncOperation](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfaceasyncoperation) interface, passed through the *activateOperation* parameter.

## See also

[ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync)

[IActivateAudioInterfaceCompletionHandler](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-iactivateaudiointerfacecompletionhandler)