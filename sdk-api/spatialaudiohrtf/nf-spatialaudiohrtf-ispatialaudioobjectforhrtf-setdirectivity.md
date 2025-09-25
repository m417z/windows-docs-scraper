# ISpatialAudioObjectForHrtf::SetDirectivity

## Description

Sets the spatial audio directivity model for the [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf).

## Parameters

### `directivity`

The spatial audio directivity model. This value can be one of the following structures:

* [SpatialAudioHrtfDirectivity](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfdirectivity)
* [SpatialAudioHrtfDirectivityCardioid](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfdirectivitycardioid)
* [SpatialAudioHrtfDirectivityCone](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfdirectivitycone)

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) was not called before the call to **SetDirectivity**. |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779275(v=vs.85)) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) and [ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779300(v=vs.85))). |

## Remarks

The [SpatialAudioHrtfDirectivity](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfdirectivity) structure represents an omnidirectional model that can be linearly interpolated with a cardioid or cone model.

If **SetDirectivity** is not called, the default type of [SpatialAudioHrtfDirectivity_OmniDirectional](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ne-spatialaudiohrtf-spatialaudiohrtfdirectivitytype) is used with no interpolation.

## See also

[ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf)