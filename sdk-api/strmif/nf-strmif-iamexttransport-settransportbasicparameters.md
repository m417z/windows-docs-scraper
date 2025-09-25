# IAMExtTransport::SetTransportBasicParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTransportBasicParameters` method sets general properties of the transport.

## Parameters

### `Param` [in]

Specifies which property to set. See Remarks for more information.

### `Value` [in]

Specifies the value of the property as a **long** integer. See Remarks for more information.

### `pszData` [in]

Specifies the value of the property as an **LPOLESTR**. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code. Possible error codes include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Device does not support setting this property. |
| **ERROR_DEVICE_REMOVED** | Device was removed. |

## Remarks

The *Param* parameter is a flag that specifies which property to set. For some flags, the property is numeric; use the *Value* parameter to specify the value. For other flags, the property is a string; use the *pszData* parameter to specify the value. In either case, the method ignores the other parameter.

For the following flags, the *Value* parameter takes a defined constant.

* ED_TRANSBASIC_TIME_FORMAT: Specifies the time format.

  | Constant | Description |
  | --- | --- |
  | ED_FORMAT_MILLISECONDS | Milliseconds. |
  | ED_FORMAT_FRAMES | Frames. |
  | ED_FORMAT_REFERENCE_TIME | Reference time. |
  | ED_FORMAT_HMSF | Binary coded decimal, representing hours, minutes, seconds, and frames. |
  | ED_FORMAT_TMSF | Binary coded decimal, representing tracks, minutes, seconds, and frames. |
* ED_TRANSBASIC_TIME_REFERENCE: Specifies the reference time in use by the device.

  | Constant | Description |
  | --- | --- |
  | ED_TIMEREF_TIMECODE | Time code. |
  | ED_TIMEREF_CONTROL_TRACK | Control track. |
  | ED_TIMEREF_INDEX | Index. |
  | ED_TIMEREF_ATN | Absolute track number. This constant is defined in the header file Xprtdefs.h. |
* ED_TRANSBASIC_END_STOP_ACTION: Specifies the action the device takes when it reaches the end of the transport medium.

  | Constant | Description |
  | --- | --- |
  | ED_MODE_STOP | Stop. |
  | ED_MODE_REWIND | Rewind. |
  | ED_MODE_FREEZE | Freeze/pause. |
* ED_TRANSBASIC_RECORD_FORMAT: Specifies the recording speed.

  | Constant | Description |
  | --- | --- |
  | ED_RECORD_FORMAT_SP | Standard play. |
  | ED_RECORD_FORMAT_LP | Long play. |
  | ED_RECORD_FORMAT_EP | Extended play. |
* ED_TRANSBASIC_SUPERIMPOSE: Specifies whether the on-screen display is enabled or disabled.

  | Constant | Description |
  | --- | --- |
  | OATRUE | On-screen display is enabled. |
  | OAFALSE | On-screen display is disabled. |
* ED_TRANSBASIC_STEP_UNIT: Specifies the step unit.

  | Constant | Description |
  | --- | --- |
  | ED_STEP_FIELD | Fields. |
  | ED_STEP_FRAME | Frames. |
  | ED_STEP_3_2 | 3/2 Pulldown. |
* ED_TRANSBASIC_SET_COUNTER_FORMAT: Sets the time format for the counter. See the ED_TRANSBASIC_TIME_FORMAT flag for possible values.

For the following flags, use a numeric value in the *Value* parameter.

| Flag | Description |
| --- | --- |
| ED_TRANSBASIC_STEP_COUNT | Specifies the step count, in units defined by the ED_TRANSBASIC_STEP_UNIT flag. |
| ED_TRANSBASIC_SET_FREEZE_TIMEOUT | Specifies the timeout for freeze mode, in units of the current time format. |
| ED_TRANSBASIC_SETCLOCK | Sets the clock time. |
| ED_TRANSBASIC_SET_COUNTER_VALUE | Sets the value of the counter. |

For the following flags, use a string in the *pszData* parameter.

| Flag | Description |
| --- | --- |
| ED_TRANSBASIC_VOLUME_NAME | Specifies the volume name. |

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-gettransportbasicparameters)