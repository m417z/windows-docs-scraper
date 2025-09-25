# MFVideoNormalizedRect structure

## Description

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