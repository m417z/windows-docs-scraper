# RECO_GUIDE structure

## Description

Defines the boundaries of the ink to the recognizer.

## Members

### `xOrigin`

Left edge of the first box in ink space coordinates.

### `yOrigin`

Top edge of first box in ink-space coordinates.

### `cxBox`

Width of each box in ink space units.

### `cyBox`

Height of each box in ink-space units.

### `cxBase`

Margin to the guideline. This is one-half the distance in ink-space units between adjacent boxes.

### `cyBase`

Vertical distance in ink-space units from the baseline to the top of the box.

### `cHorzBox`

Count of columns of boxes.

### `cVertBox`

Count of rows of boxes.

### `cyMid`

Distance in ink-space units from the baseline to the midline, or 0 if the midline is not present.

## Remarks

If the application has drawn guidelines on the screen on which the user is expected to write, the application should set the values in the **RECO_GUIDE** structure to inform the recognizer. The **RECO_GUIDE** structure is for the recognizer's use only. Setting the **RECO_GUIDE** structure does not, by itself, draw visual clues on the display. The application or the control draws the visual clues.

The xOrigin and yOrigin members are ink-space coordinates of the upper-left corner of the area to write in. The cyBox and cxBox members are the height and width of the individual boxes to write in. If the guide is lined, they cyBox and cxBox width/height of every line. The cHorzBox and cVertBox members specify the number of columns and rows. The cyBase member specifies a baseline within the box. Setting the cyBase member to 0 indicates that there is no baseline. The cxBase member gives a horizontal displacement of the edge of the guideline from the edge of the box where writing is expected to start.

Use the values of cHorzBox and cVertBox to control the kind of recognition input that you use. When cHorzBox and cVertBox are both greater than zero, boxed input is used. The following table lists potential input modes and which values to set cHorzBox and cVertBox for each mode.

| For this type of input | Set cHorzBox equal to | And set cVertBox equal to |
| --- | --- | --- |
| Free input | 0 | 0 |
| Lined input with 1 horizontal line | 0 | 1 |
| Lined input with 1 vertical line | 1 | 0 |
| Lined input with n horizontal lines | 0 | n |
| Lined input with n vertical lines | n | 0 |
| Boxed input with 1 box | 1 | 1 |
| Boxed input in a horizontal line with n boxes | n | 1 |
| Boxed input in a grid of boxes x rows by z columns | z | x |

The following illustration represents the recognition guide structure for five columns and three rows of boxes.

![Illustration of recognition guide structure](https://learn.microsoft.com/windows/win32/api/rectypes/images/3551c7eb-7398-4724-9de7-191818f35443.gif)
The following illustration represents a single box from the previous illustration.

![Illustration of single recognition guide box](https://learn.microsoft.com/windows/win32/api/rectypes/images/a7106d81-4314-44ec-905d-1bb3ba7711b7.gif)

## See also

[GetGuide Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getguide)

[SetGuide Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setguide)