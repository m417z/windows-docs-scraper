# IAudioClient2::SetClientProperties

## Description

Sets the properties of the audio stream by populating an [AudioClientProperties](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audioclientproperties-r1) structure.

## Parameters

### `pProperties` [in]

Pointer to an [AudioClientProperties](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audioclientproperties-r1) structure.

## Return value

The **SetClientProperties** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## Remarks

Starting with Windows 10, hardware-offloaded audio streams must be event driven. This means that if you call **IAudioClient2::SetClientProperties** and set the *bIsOffload* parameter of the [AudioClientProperties](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audioclientproperties~r1) to TRUE, you must specify the **AUDCLNT_STREAMFLAGS_EVENTCALLBACK** flag in the *StreamFlags* parameter to [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize).

## See also

[AudioClientProperties](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audioclientproperties-r1)

[IAudioClient2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient2)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)