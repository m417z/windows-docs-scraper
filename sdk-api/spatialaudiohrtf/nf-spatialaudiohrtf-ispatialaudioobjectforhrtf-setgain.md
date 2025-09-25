# ISpatialAudioObjectForHrtf::SetGain

## Description

Sets the gain for the [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) in dB.

## Parameters

### `gain` [in]

The gain for the [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) in dB.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) was not called before the call to **SetGain**. |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779275(v=vs.85)) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779299(v=vs.85)) and [ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt779300(v=vs.85))). |

## Remarks

This is valid only for spatial audio objects configured to use the [SpatialAudioHrtfDistanceDecay_CustomDecay](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ne-spatialaudiohrtf-spatialaudiohrtfdistancedecaytype) decay type. Set the decay type of an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) object by calling [SetDistanceDecay](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nf-spatialaudiohrtf-ispatialaudioobjectforhrtf-setdistancedecay). Set the default decay type for an all objects in an HRTF render stream by setting the **DistanceDecay** field of the [SpatialAudioHrtfActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfactivationparams) passed into [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream).

If **SetGain** is never called, the default value of 0.0 is used. After **SetGain** is called, the gain that is set will be used for the audio object until the gain is changed with another call to **SetGain**.

## See also

[ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf)