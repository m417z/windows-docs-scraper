# MFVideoNormalizedRect structure

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Defines a normalized rectangle, which is used to specify sub-rectangles in a video rectangle. When a rectangle N is *normalized* relative to some other rectangle R, it means the following:

* The coordinate (0.0, 0.0) on N is mapped to the upper-left corner of R.
* The coordinate (1.0, 1.0) on N is mapped to the lower-right corner of R.

Any coordinates of N that fall outside the range [0...1] are mapped to positions outside the rectangle R. A normalized rectangle can be used to specify a region within a video rectangle without knowing the resolution or even the aspect ratio of the video. For example, the upper-left quadrant is defined as {0.0, 0.0, 0.5, 0.5}.

## Members

### `left`

X-coordinate of the upper-left corner of the rectangle.

### `top`

Y-coordinate of the upper-left corner of the rectangle.

### `right`

X-coordinate of the lower-right corner of the rectangle.

### `bottom`

Y-coordinate of the lower-right corner of the rectangle.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)