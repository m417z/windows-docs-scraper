# DisplaySizeList enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **DisplaySizeList** enumeration defines the possible sizes at which the video rectangle may be rendered.

## Constants

### `dslDefaultSize:0`

Display the video rectangle at the native size.

### `dslSourceSize:0`

Same as **dslDefaultSize**.

### `dslHalfSourceSize`

Display the video rectangle by shrinking the width and height by half.

### `dslDoubleSourceSize`

Display the video rectangle by stretching the width and height to twice their native size.

### `dslFullScreen`

Display the video rectangle by stretching the width and height to fill the entire screen as much as possible while maintaining the original aspect ratio.

### `dslHalfScreen`

Display the video rectangle by stretching the width and height as much as possible to fill half (50%) of the screen while maintaining the original aspect ratio.

### `dslQuarterScreen`

Display the video rectangle by stretching the width and height as much as possible to fill one quarter (25%) of the screen while maintaining the original aspect ratio.

### `dslSixteenthScreen`

Display the video rectangle by stretching the width and height as much as possible to fill one sixteenth (6.25%) of the screen while maintaining the original aspect ratio.

## See also

[IMSVidCtl::get_DisplaySize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_displaysize)

[IMSVidCtl::put_DisplaySize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_displaysize)