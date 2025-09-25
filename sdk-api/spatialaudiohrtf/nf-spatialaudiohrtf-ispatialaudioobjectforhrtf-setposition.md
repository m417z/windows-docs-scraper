# ISpatialAudioObjectForHrtf::SetPosition

## Description

Sets the position in 3D space, relative to the listener, from which the [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) audio data will be rendered.

## Parameters

### `x` [in]

The x position of the audio object, in meters, relative to the listener. Positive values are to the right of the listener and negative values are to the left.

### `y` [in]

The y position of the audio object, in meters, relative to the listener. Positive values are above the listener and negative values are below.

### `z` [in]

The z position of the audio object, in meters, relative to the listener. Positive values are behind the listener and negative values are in front.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) was not called before the call to **SetPosition**. |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779275(v=vs.85)) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) and [ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779300(v=vs.85))). |
| **SPTLAUDCLNT_E_PROPERTY_NOT_SUPPORTED** | The [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) is not of type **AudioObjectType_Dynamic**. Set the type of the audio object with the *type* parameter to the [ISpatialAudioObjectRenderStreamBase::ActivateSpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nf-spatialaudiohrtf-ispatialaudioobjectrenderstreamforhrtf-activatespatialaudioobjectforhrtf) method. |

## Remarks

This method can only be called on a [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) that is of type **AudioObjectType_Dynamic**. Set the type of the audio object with the *type* parameter to the [ISpatialAudioObjectRenderStreamForHrtf::ActivateSpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nf-spatialaudiohrtf-ispatialaudioobjectrenderstreamforhrtf-activatespatialaudioobjectforhrtf) method.

 Position values use a right-handed Cartesian coordinate system, where each unit represents 1 meter. The coordinate system is relative to the listener where the origin (x=0.0, y=0.0, z=0.0) represents the center point between the listener's ears.

If **SetPosition** is never called, the origin (x=0.0, y=0.0, z=0.0) is used as the default position. After **SetPosition** is called, the position that is set will be used for the audio object until the position is changed with another call to **SetPosition**.

## See also

[ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf)