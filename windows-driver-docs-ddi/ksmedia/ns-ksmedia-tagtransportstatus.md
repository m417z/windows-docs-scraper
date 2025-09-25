# tagTRANSPORTSTATUS structure

## Description

The TRANSPORTSTATUS structure describes the current transport status.

## Members

### `Mode`

Specifies the ED_MODE_Xxx.

### `LastError`

Specifies the last error.

### `RecordInhibit`

Specifies if recording is inhibited. **TRUE** if recording is prevented, **FALSE** otherwise.

### `ServoLock`

Indicates the servo lock.

### `MediaPresent`

Specifies if media is present.

### `MediaLength`

Specifies the length of the media.

### `MediaSize`

Specifies the size of the media.

### `MediaTrackCount`

Indicates the media track count.

### `MediaTrackLength`

Specifies the media track length.

### `MediaTrackSide`

Indicates the media track size.

### `MediaType`

Indicates the type of media.

### `LinkMode`

Indicates linked mode. **TRUE** if linked, **FALSE** otherwise.

### `NotifyOn`

Specifies event notification. **TRUE** enables event notification, **FALSE** disables event notification.

## Remarks

Any ED_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.