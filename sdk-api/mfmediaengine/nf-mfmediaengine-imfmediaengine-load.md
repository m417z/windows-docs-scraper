# IMFMediaEngine::Load

## Description

Loads the current media source.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The main purpose of this method is to reload a list of source elements after updating the list. For more information, see [SetSourceElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsourceelements). Otherwise, calling this method is generally not required. To load a new media source, call [IMFMediaEngine::SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource) or **IMFMediaEngine::SetSourceElements**.

The **Load** method explicitly invokes the Media Engine's media resource loading algorithm. Before calling this method, you must set the media resource by calling [IMFMediaEngine::SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource) or [IMFMediaEngine::SetSourceElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsourceelements).

This method completes asynchronously. When the **Load** operation starts, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_LOADSTART** event. If no errors occur during the **Load** operation, several other events are generated, including the following.

* **MF_MEDIA_ENGINE_EVENT_LOADEDMETADATA**
* **MF_MEDIA_ENGINE_EVENT_LOADEDDATA**
* **MF_MEDIA_ENGINE_EVENT_CANPLAY**
* **MF_MEDIA_ENGINE_EVENT_CANPLAYTHROUGH**

If the Media Engine is unable to load the file, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_ERROR** event.

For more information about event handling in the Media Engine, see [IMFMediaEngineNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginenotify).

This method corresponds to the **load** method of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)