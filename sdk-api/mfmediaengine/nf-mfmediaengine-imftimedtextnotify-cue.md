# IMFTimedTextNotify::Cue

## Description

Called when a cue event occurs in a text track.

## Parameters

### `cueEvent` [in]

Type: **[MF_TIMED_TEXT_CUE_EVENT](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_cue_event)**

A value specifying the type of event that has occurred.

### `currentTime` [in]

Type: **double**

The current time when the cue event occurred.

### `cue` [in]

Type: **[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)***

The [IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue) object representing the cue.

## See also

[IMFTimedTextNotify](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextnotify)