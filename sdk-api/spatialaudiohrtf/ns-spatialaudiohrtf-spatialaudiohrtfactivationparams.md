# SpatialAudioHrtfActivationParams structure

## Description

Specifies the activation parameters for an [ISpatialAudioRenderStreamForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectrenderstreamforhrtf).

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