# _MFP_CREATION_OPTIONS enumeration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies options for the [MFPCreateMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfpcreatemediaplayer) function.

## Constants

### `MFP_OPTION_NONE:0`

Use the default creation options.

### `MFP_OPTION_FREE_THREADED_CALLBACK:0x1`

If set, the MFPlay player object invokes the application's [IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback) callback on another thread, and not the thread that called the [MFPCreateMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfpcreatemediaplayer) function. Therefore, the callback must be thread safe.

If this flag is not set, the player object invokes the callback on the same thread that calls [MFPCreateMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfpcreatemediaplayer). This thread must have a message loop. Internally, the player object creates a hidden window to dispatch the callback, similar to the mechanism used for single-threaded apartments (STAs) in COM.

### `MFP_OPTION_NO_MMCSS:0x2`

Do not register the playback topology with the Multimedia Class Scheduler Service (MMCSS). By default, the MFPlay object registers the playback topology with MMCSS, which typically results in a better playback experience. For more information, see [IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices).

### `MFP_OPTION_NO_REMOTE_DESKTOP_OPTIMIZATION:0x4`

Disables optimizations that are otherwise performed when the application runs in a Remote Desktop Services (RDS, formerly Terminal Services) environment.

## Remarks

The following **typedef** is defined for combining flags from this enumeration.

``` syntax
typedef UINT32 MFP_CREATION_OPTIONS;
```

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)