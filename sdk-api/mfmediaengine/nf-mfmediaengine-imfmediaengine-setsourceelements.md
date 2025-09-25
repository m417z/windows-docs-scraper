# IMFMediaEngine::SetSourceElements

## Description

Sets a list of media sources.

## Parameters

### `pSrcElements` [in]

A pointer to the [IMFMediaEngineSrcElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelements) interface. The caller must implement this interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to adding a list of **source** elements to a media element in HTML5.

The Media Engine tries to load each item in the *pSrcElements* list, until it finds one that loads successfully. After this method is called, the application can use the [IMFMediaEngineSrcElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelements) interface to update the list at any time. To reload the list, call [IMFMediaEngine::Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

This method completes asynchronously. When the operation starts, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_LOADSTART** event. If no errors occur during the [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) operation, several other events are generated, including the following.

* **MF_MEDIA_ENGINE_EVENT_LOADEDMETADATA**
* **MF_MEDIA_ENGINE_EVENT_LOADEDDATA**
* **MF_MEDIA_ENGINE_EVENT_CANPLAY**
* **MF_MEDIA_ENGINE_EVENT_CANPLAYTHROUGH**

If the Media Engine is unable to load a URL, it sends an **MF_MEDIA_ENGINE_EVENT_ERROR** event.

For more information about event handling in the Media Engine, see [IMFMediaEngineNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginenotify).

If the application also calls [IMFMediaEngine::SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource), the URL passed to **SetSource** takes precedence over the list given to **SetSourceElements**.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)