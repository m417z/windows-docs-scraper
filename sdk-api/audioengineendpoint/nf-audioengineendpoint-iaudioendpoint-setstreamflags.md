# IAudioEndpoint::SetStreamFlags

## Description

The **SetStreamFlags** method sets the stream configuration flags on the audio endpoint.

## Parameters

### `streamFlags` [in]

A bitwise **OR** of one or more of the AUDCLNT_STREAMFLAGS_XXX constants.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpoint)