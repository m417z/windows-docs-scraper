# IAMExtTransport::GetCapability

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCapability` method retrieves the general capabilities of the transport.

## Parameters

### `Capability` [in]

Specifies the capability to check. See Remarks for more information.

### `pValue` [out]

Pointer to a variable that receives a **long** integer. See Remarks for more information.

### `pdblValue` [out]

Pointer to a variable that receives a **double**. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The *Capability* parameter is a flag that specifies which capability to check. The method returns the result either in the *pValue* parameter or in the *pdblValue* parameter, depending on the capability flag.

For the following flags, the method returns the value OATRUE or OAFALSE in the *pValue* parameter. The value OATRUE indicates that the capability is present, while the value OAFALSE indicates it is absent.

| Capability Flag | Description |
| --- | --- |
| ED_TRANSCAP_CAN_ASSEMBLE | Transport can use assemble record mode (record new tracks that link seamlessly to the control track from the previously recorded segment). |
| ED_TRANSCAP_CAN_BUMP_PLAY | Transport can synchronize by varying speed. |
| ED_TRANSCAP_CAN_DELAY_AUDIO_IN | Transport can perform delayed-in audio edits. |
| ED_TRANSCAP_CAN_DELAY_AUDIO_OUT | Transport can perform delayed-out audio edits. |
| ED_TRANSCAP_CAN_DELAY_VIDEO_IN | Transport can perform delayed-in video edits. |
| ED_TRANSCAP_CAN_DELAY_VIDEO_OUT | Transport can perform delayed-out video edits. |
| ED_TRANSCAP_CAN_DETECT_LENGTH | Transport can detect the length of the media. |
| ED_TRANSCAP_CAN_EJECT | Transport can eject the media. |
| ED_TRANSCAP_CAN_FREEZE | Transport can freeze/pause. |
| ED_TRANSCAP_CAN_INSERT | Transport can use insert record mode (record individual tracks while locked to a prerecorded control track). |
| ED_TRANSCAP_CAN_PLAY_BACKWARDS | Transport can play backward. |
| ED_TRANSCAP_CAN_SET_EE | Transport can show the device's input on its output. |
| ED_TRANSCAP_CAN_SET_PB | Transport can show media playback on its output. |
| ED_TRANSCAP_FIELD_STEP | Transport responds to a frame advance command by advancing one field. |
| ED_TRANSCAP_HAS_CLOCK | Device has a clock. |
| ED_TRANSCAP_HAS_DT | Device has dynamic tracking. |
| ED_TRANSCAP_HAS_TIMER | Device has a timer. |
| ED_TRANSCAP_HAS_TUNER | Device has a tuner. |
| ED_TRANSCAP_IS_MASTER | Device is the master clock for synchronizing. |
| ED_TRANSCAP_MULTIPLE_EDITS | Device supports multiple edit events. |
| ED_TRANSCAP_NEEDS_CUEING | Device must be cued before it performs an edit. |
| ED_TRANSCAP_NEEDS_TBC | Device needs to be calibrated. |

For the following flags, the method returns a numeric value in the *pValue* parameter.

|  |  |
| --- | --- |
| Capability Flag | Returned Value |
| ED_TRANSCAP_LTC_TRACK | Returns the track number of the LTC timecode track, or ED_ALL if there is no dedicated timecode track. |
| ED_TRANSCAP_NUM_AUDIO_TRACKS | Returns the number of audio tracks. |

For the following flags, the method returns a value in the *pdblValue* parameter.

|  |  |
| --- | --- |
| Capability Flag | Returned Value |
| ED_TRANSCAP_FWD_SHUTTLE_MAX | Maximum forward speed in shuttle mode, as a multiple of play speed. |
| ED_TRANSCAP_FWD_SHUTTLE_MIN | Minimum forward speed in shuttle mode, as a multiple of play speed. |
| ED_TRANSCAP_FWD_VARIABLE_MAX | Maximum forward speed, as a multiple of play speed. |
| ED_TRANSCAP_FWD_VARIABLE_MIN | Minimum forward speed, as a multiple of play speed. |
| ED_TRANSCAP_REV_SHUTTLE_MAX | Maximum reverse speed in shuttle mode, as a multiple of play speed. |
| ED_TRANSCAP_REV_SHUTTLE_MIN | Minimum reverse speed in shuttle mode, as a multiple of play speed. |
| ED_TRANSCAP_REV_VARIABLE_MAX | Maximum reverse speed, as a multiple of play speed. |
| ED_TRANSCAP_REV_VARIABLE_MIN | Minimum reverse speed, as a multiple of play speed. |

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)