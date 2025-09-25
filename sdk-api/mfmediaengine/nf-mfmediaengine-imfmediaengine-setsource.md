# IMFMediaEngine::SetSource

## Description

Sets the URL of a media resource.

## Parameters

### `pUrl` [in]

The URL of the media resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to setting the **src** attribute of the **HTMLMediaElement** interface in HTML5.

The URL specified by this method takes precedence over media resources specified in the [IMFMediaEngine::SetSourceElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsourceelements) method. To load the URL, call [IMFMediaEngine::Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

This method asynchronously loads the URL. When the operation starts, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_LOADSTART** event. If no errors occur during the [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) operation, several other events are generated, including the following.

* **MF_MEDIA_ENGINE_EVENT_LOADEDMETADATA**
* **MF_MEDIA_ENGINE_EVENT_LOADEDDATA**
* **MF_MEDIA_ENGINE_EVENT_CANPLAY**
* **MF_MEDIA_ENGINE_EVENT_CANPLAYTHROUGH**

If the Media Engine is unable to load the URL, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_ERROR** event.

For more information about event handling in the Media Engine, see [IMFMediaEngineNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginenotify).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)