## Description

Represents activation parameters for a spatial audio render stream, extending \<xref:NS:spatialaudiohrtf.SpatialAudioHrtfActivationParams> with the ability to specify stream options.

## Members

### `ObjectFormat`

Format descriptor for spatial audio objects associated with the stream. All objects must have the same format and must be of type [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) or [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd390971(v=vs.85)).

### `StaticObjectTypeMask`

 A bitwise combination of **AudioObjectType** values indicating the set of static spatial audio channels that will be allowed by the activated stream.

### `MinDynamicObjectCount`

 The minimum number of concurrent dynamic objects. If this number of dynamic audio objects can't be activated simultaneously, no dynamic audio objects will be activated.

### `MaxDynamicObjectCount`

 The maximum number of concurrent dynamic objects that can be activated with [ISpatialAudioRenderStreamForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectrenderstreamforhrtf).

### `Category`

 The category of the audio stream and its spatial audio objects.

### `EventHandle`

The event that will signal the client to provide more audio data. This handle will be duplicated internally before it is used.

### `NotifyObject`

 The object that provides notifications for spatial audio clients to respond to changes in the state of an [ISpatialAudioRenderStreamForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectrenderstreamforhrtf). This object is used to notify clients that the number of dynamic spatial audio objects that can be activated concurrently is about to change.

### `DistanceDecay`

Optional default value for the decay model used for [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) objects associated with the stream. **nullptr** if unused.

### `Directivity`

Optional default value for the spatial audio directivity model used for [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) objects associated with the stream. **nullptr** if unused.

### `Environment`

Optional default value for the type of environment that is simulated when audio is processed for [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) objects associated with the stream. **nullptr** if unused.

### `Orientation`

Optional default value for the orientation of [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) objects associated with the stream. **nullptr** if unused.

### `Options`

A member of the \<xref:NE:spatialaudioclient.SPATIAL_AUDIO_STREAM_OPTIONS> emumeration, specifying options for the activated audio stream.

## Remarks

The following example demostrates activating a spatial audio render stream for HRTF with stream options.

```cpp
void CreateSpatialAudioObjectRenderStreamForHrtf(
    _In_ ISpatialAudioClient2* spatialAudioClient,
    _In_ WAVEFORMATEX const* objectFormat,
    AudioObjectType staticObjectTypeMask,
    UINT32 minDynamicObjectCount,
    UINT32 maxDynamicObjectCount,
    AUDIO_STREAM_CATEGORY streamCategory,
    _In_ HANDLE eventHandle,
    _In_opt_ ISpatialAudioObjectRenderStreamNotify* notifyObject,
    _In_opt_ SpatialAudioHrtfDistanceDecay* distanceDecay,
    _In_opt_ SpatialAudioHrtfDirectivityUnion* directivity,
    _In_opt_ SpatialAudioHrtfEnvironmentType* environment,
    _In_opt_ SpatialAudioHrtfOrientation* orientation,
    bool enableOffload,
    _COM_Outptr_ ISpatialAudioObjectRenderStreamForHrtf** stream)
{
    SpatialAudioHrtfActivationParams2 streamActivationParams =
    {
        objectFormat,
        staticObjectTypeMask,
        minDynamicObjectCount,
        maxDynamicObjectCount,
        streamCategory,
        eventHandle,
        notifyObject,
        distanceDecay,
        directivity,
        environment,
        orientation,
        enableOffload ? SPATIAL_AUDIO_STREAM_OPTIONS_OFFLOAD : SPATIAL_AUDIO_STREAM_OPTIONS_NONE
    };

    PROPVARIANT activateParamsPropVariant = {};
    activateParamsPropVariant.vt = VT_BLOB;
    activateParamsPropVariant.blob.cbSize = sizeof(streamActivationParams);
    activateParamsPropVariant.blob.pBlobData = reinterpret_cast<BYTE*>(&streamActivationParams);

    *stream = nullptr;
    THROW_IF_FAILED(spatialAudioClient->ActivateSpatialAudioStream(&activateParamsPropVariant, IID_PPV_ARGS(stream)));
}

```

## See also