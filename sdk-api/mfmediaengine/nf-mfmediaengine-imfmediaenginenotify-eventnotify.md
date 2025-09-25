# IMFMediaEngineNotify::EventNotify

## Description

Notifies the application when a playback event occurs.

## Parameters

### `event` [in]

A member of the [MF_MEDIA_ENGINE_EVENT](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_event) enumeration that specifies the event.

### `param1` [in]

The first event parameter. The meaning of this parameter depends on the event code.

### `param2` [in]

The second event parameter. The meaning of this parameter depends on the event code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginenotify)