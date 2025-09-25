# IAMExtTransport::SetEditProperty

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetEditProperty` method defines parameters and values associated with an edit event.

This method is not implemented.

## Parameters

### `EditID` [in]

Specifies the edit property set. Use the identifier returned by the [IAMExtTransport::SetEditPropertySet](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditpropertyset) method.

### `Param` [in]

Specifies the edit event parameter. See Remarks for more information.

### `Value` [in]

Specifies the value of the parameter. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

An edit event consists of one or more edit event parameters. Use the **SetEditPropertySet** method to create an edit event, and then use this method to specify the edit event parameters for that edit event.

The *Param* parameter is a flag that specifies the edit event parameter. The *Value* parameter specifies the value of that parameter. The meaning of *Value* depends on the flag used in *Param*:

* ED_EDIT_HEVENT: Handle to an event. The device will signal the event when the edit event has completed.
* ED_EDIT_IMMEDIATE: If the value is OATRUE, the application can switch the device into edit mode by calling [IAMExtTransport::put_Mode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-put_mode) with the value ED_MODE_EDIT_CUE.
* ED_EDIT_MODE: Specifies the editing mode. Use one of the following constants.

  | Constant | Description |
  | --- | --- |
  | ED_EDIT_MODE_ASSEMBLE | Assemble edit mode. |
  | ED_EDIT_MODE_INSERT | Insert edit mode. |
  | ED_EDIT_MODE_CRASH_RECORD | Crash record mode. |
* ED_EDIT_TRACK: Specifies which track to edit. Use one or more of the following constants. You can combine constants with a bitwise OR.

  | Constant | Description |
  | --- | --- |
  | ED_VIDEO | Video track |
  | ED_AUDIO_1 through ED_AUDIO_24 | Audio tracks 1 through 24 |
  | ED_AUDIO_ALL | All audio track |
* ED_EDIT_SRC_INPOINT: Specifies the inpoint on the source, in units of the current time format.
* ED_EDIT_SRC_OUTPOINT: Specifies the outpoint on the source, in units of the current time format.
* ED_EDIT_REC_INPOINT: Specifies the inpoint on the record device, in units of the current time format.
* ED_EDIT_REC_OUTPOINT: Specifies the outpoint on the record device, in units of the current time format.
* ED_EDIT_REHEARSE_MODE: Specifies the preview mode. Use one of the following constants.

  | Constant | Description |
  | --- | --- |
  | ED_EDIT_BVB | Black-video-black (BVB). Display black, then inserted video, then black. |
  | ED_EDIT_VBV | Video-black-video (VBV). Display recorded video, then black, then recorded video. |
  | ED_EDIT_VVV | Video-video-video (VVV). Display recorded video, then inserted video, then recorded video. |
  | ED_EDIT_PERFORM | Do not preview. |
* ED_EDIT_ABORT: With the value OATRUE, the method halts the edit if it is currently in progress.
* ED_EDIT_TIMEOUT: Specifies how long the device will wait for the edit to complete, before timing out.
* ED_EDIT_SEEK: With the value OATRUE, the method seeks to a specified point. First call this method with the ED_EDIT_SEEK_MODE flag, to specify the seek point.
* ED_EDIT_SEEK_MODE: Specifies a seek point. Use one of the following constants.

  | Constant | Description |
  | --- | --- |
  | ED_EDIT_SEEK_EDIT_IN | Seek to the inpoint. |
  | ED_EDIT_SEEK_EDIT_OUT | Seek to the outpoint. |
  | ED_EDIT_SEEK_PREROLL | Seek to the inpoint preroll. |
  | ED_EDIT_SEEK_PREROLL_CT | Seek to the inpoint using timecode, then seek back to the preroll point using the control track. |
  | ED_EDIT_SEEK_BOOKMARK | Seek to the next bookmark. |

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetEditProperty](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-geteditproperty)