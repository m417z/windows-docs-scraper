# ISpatialAudioObjectForHrtf::SetDistanceDecay

## Description

Sets the decay model that is applied over distance from the position of an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) to the position of the listener.

## Parameters

### `distanceDecay` [in]

The decay model.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) was not called before the call to **SetDistanceDecay**. |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779275(v=vs.85)) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) and [ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779300(v=vs.85))). |

## Remarks

If **SetEnvironment** is not called, the default values are used.

## See also

[ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf)