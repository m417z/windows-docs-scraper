# ISpatialAudioObjectForHrtf::SetOrientation

## Description

Sets the orientation in 3D space, relative to the listener's frame of reference, from which the [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) audio data will be rendered.

## Parameters

### `orientation` [in]

An array of floats defining row-major 3x3 rotation matrix.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) was not called before the call to **SetOrientation**. |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779275(v=vs.85)) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) and [ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779300(v=vs.85))). |

## Remarks

If **SetOrientation** is never called, the default value of an identity matrix is used. After **SetOrientation** is called, the orientation that is set will be used for the audio object until the orientation is changed with another call to **SetOrientation**.

## See also

[ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf)