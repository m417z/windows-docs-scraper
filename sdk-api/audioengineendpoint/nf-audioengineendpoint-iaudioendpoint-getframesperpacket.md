# IAudioEndpoint::GetFramesPerPacket

## Description

The **GetFramesPerPacket** method gets the maximum number of frames per packet that the audio endpoint can support, based on the endpoint's period and the sample rate.

## Parameters

### `pFramesPerPacket` [out]

Receives the maximum number of frames per packet that the endpoint can support.

## Return value

If the method succeeds, it returns **S_OK**.

## See also

[IAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpoint)