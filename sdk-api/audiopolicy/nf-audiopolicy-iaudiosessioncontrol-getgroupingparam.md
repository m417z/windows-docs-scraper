# IAudioSessionControl::GetGroupingParam

## Description

The **GetGroupingParam** method retrieves the grouping parameter of the audio session.

## Parameters

### `pRetVal` [out]

Output pointer for the grouping-parameter GUID. This parameter must be a valid, non-**NULL** pointer to a caller-allocated GUID variable. The method writes the grouping parameter into this variable.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pRetVal* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

All of the audio sessions that have the same grouping parameter value are under the control of the same volume-level slider in the system volume-control program, Sndvol. For more information, see [Grouping Parameters](https://learn.microsoft.com/windows/desktop/CoreAudio/grouping-parameters).

A client can call the [IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam) method to change the grouping parameter of a session.

If a client has never called [SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam) to assign a grouping parameter to an audio session, the session's grouping parameter value is GUID_NULL by default and a call to **GetGroupingParam** retrieves this value. A grouping parameter value of GUID_NULL indicates that the session does not belong to any grouping. In that case, the session has its own volume-level slider in the Sndvol program.

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam)