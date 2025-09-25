## Description

Represents activation parameters for a spatial audio render stream, extending  with the ability to specify stream options. Pass this structure to [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream) when activating a stream.

## Members

### `ObjectFormat`

 Format descriptor for a single spatial audio object. All objects used by the stream must have the same format and the format must be of type [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) or [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible).

### `StaticObjectTypeMask`

 A bitwise combination of **AudioObjectType** values indicating the set of static spatial audio channels that will be allowed by the activated stream.

### `MinDynamicObjectCount`

The minimum number of concurrent dynamic objects. If this number of dynamic audio objects can't be activated simultaneously, [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream) will fail with this error **SPTLAUDCLNT_E_NO_MORE_OBJECTS**.

### `MaxDynamicObjectCount`

The maximum number of concurrent dynamic objects that can be activated with [ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream).

### `Category`

The category of the audio stream and its spatial audio objects.

### `EventHandle`

 The event that will signal the client to provide more audio data. This handle will be duplicated internally before it is used.

### `NotifyObject`

 The object that provides notifications for spatial audio clients to respond to changes in the state of an [ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream). This object is used to notify clients that the number of dynamic spatial audio objects that can be activated concurrently is about to change.

### `Options`

A member of the [SPATIAL_AUDIO_STREAM_OPTIONS](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/ne-spatialaudioclient-spatial_audio_stream_options) emumeration, specifying options for the activated audio stream.

## Remarks

## See also