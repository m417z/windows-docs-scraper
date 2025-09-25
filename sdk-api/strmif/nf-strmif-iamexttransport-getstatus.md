# IAMExtTransport::GetStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetStatus` method returns information about the transport's status.

## Parameters

### `StatusItem` [in]

Specifies the status information to retrieve. See Remarks for more information.

### `pValue` [in, out]

Pointer to variable that either specifies or receives a **long** integer, whose meaning depends on the value of *StatusItem*. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The *StatusItem* parameter is a flag that specifies which status information to retrieve. The method returns in the information in the *pValue* parameter. Not every device supports every status flag. The following flags are defined:

* ED_MODE: Returns the current transport mode, such as pause or play. See [IAMExtTransport::put_Mode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-put_mode) for a list of constants that define the transport modes. As an alternative, you can set *StatusItem* equal to one of these constants, and *pValue* will receive the value OATRUE if the transport is currently in that mode, or OAFALSE otherwise.
* ED_MEDIA_TYPE: Indicates the format of the media for this transport. Returns one of the following constants.

  | Constant | Description |
  | --- | --- |
  | ED_MEDIA_VHS | VHS |
  | ED_MEDIA_SVHS | S-VHS |
  | ED_MEDIA_HI8 | Hi-8 |
  | ED_MEDIA_UMATIC | Umatic |
  | ED_MEDIA_DVC | DV tape (DVC) |
  | ED_MEDIA_1_INCH | 1-inch tape |
  | ED_MEDIA_D1 | D1 format |
  | ED_MEDIA_D2 | D2 format |
  | ED_MEDIA_D3 | D3 format |
  | ED_MEDIA_D5 | D5 format |
  | ED_MEDIA_DBETA | Digital Betacam |
  | ED_MEDIA_BETA | Betacam |
  | ED_MEDIA_8MM | 8-millimeter |
  | ED_MEDIA_DDR | Digital disk recorder |
  | ED_MEDIA_SX | Betacam SX |
  | ED_MEDIA_OTHER | Other |
  | ED_MEDIA_CLV | CLV (Constant Linear Velocity, or "standard play") laserdisc |
  | ED_MEDIA_CAV | CAV (Constant Angular Velocity, or "extended play") laserdisc |
* ED_LINK_MODE: Returns OATRUE if the transport's controls are linked to the filter graph's **Run**, **Stop**, and **Pause** methods, and OAFALSE otherwise. See [IAMExtTransport::put_Mode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-put_mode) for more information.
* ED_MEDIA_PRESENT: Returns OATRUE if the transport's media is present, or OAFALSE otherwise.
* ED_MEDIA_LENGTH: Returns the length of the media, in units of the current time format (see [IAMExtTransport::SetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportbasicparameters)).
* ED_MEDIA_TRACK_COUNT: Returns the track count.
* ED_MEDIA_TRACK_LENGTH: Returns the track length, in units of the current time format.
* ED_MEDIA_SIDE: Indicates which side of the media is active.

In Windows XP Service Pack 2 and later, the following additional play modes are defined for ED_MODE.

| Constant | Description |
| --- | --- |
| ED_MODE_PLAY_SLOW_FWD_X | Play unspecified slow forward. (Slow-forward play at vendor-specific speed.) |
| ED_MODE_PLAY_FAST_FWD_X | Play unspecified fast forward. (Fast-forward play at vendor-specific speed.) |
| ED_MODE_PLAY_SLOW_REV_X | Play unspecified slow reverse. (Slow-reverse play at vendor-specific speed.) |
| ED_MODE_PLAY_FAST_REV_X | Play unspecified fast reverse. (Fast-reverse play at vendor-specific speed.) |
| ED_MODE_STOP_START | Transport is stopped at the beginning of the tape (or other transport medium). |
| ED_MODE_STOP_END | Transport is stopped at the end of the tape (or other transport medium). |
| ED_MODE_STOP_EMERGENCY | Transport has stopped due to unexpected conditions or to avoid possible damage to the transport. |

To use these constants, include the header file Xprtdefs.h from the Windows SDK.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) supports the following status flags:

* ED_MODE: See previous remarks.
* ED_MEDIA_TYPE: Returns one of the following values.

  | Constant | Description |
  | --- | --- |
  | ED_MEDIA_VHS | VHS tape. |
  | ED_MEDIA_DVC | DV tape. |
  | ED_MEDIA_UNKNOWN | Unknown type. |
  | ED_MEDIA_NOT_PRESENT | The transport is empty. |
* ED_DEV_REMOVED_HEVENT_GET. Returns a handle to an event. The driver signals the event if the device is physically removed from the system.
* ED_DEV_REMOVED_HEVENT_RELEASE. Releases the event handle obtained through the ED_DEV_REMOVED_HEVENT_GET flag. Specify the address of the handle in the pValue parameter.
* ED_MODE_CHANGE_NOTIFY. Returns the device state in pValue. If the method returns E_PENDING, a state change is pending. You can use the ED_NOTIFY_HEVENT_GET flag to get notification when the state change is complete.
* ED_NOTIFY_HEVENT_GET. Returns a handle to an event. The driver signals the event when the device completes a mode change.
* ED_NOTIFY_HEVENT_RELEASE. Releases the event handle obtained through the ED_NOTIFY_HEVENT_GET flag. Specify the address of the handle in the pValue parameter.

### MPEG Camcorder Implementation

[MSTape](https://learn.microsoft.com/windows/desktop/DirectShow/mstape-driver) supports an additional media format for the ED_MEDIA_TYPE flag.

| Constant | Description |
| --- | --- |
| ED_MEDIA_NEO | Mini digital tape for MPEG-2 transport stream (D-VHS). |

Some of these flags are defined in the header file Xptrdefs.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)