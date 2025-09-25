# OleLoadPictureFileEx function

## Description

Loads a picture from a file.

## Parameters

### `varFileName` [in]

The path and name of the picture file to load.

### `xSizeDesired` [in]

The desired length for the picture to be displayed.

### `ySizeDesired` [in]

The desired height for the picture to be displayed.

### `dwFlags` [in]

The desired color depth for the icon or cursor. Together with the desired size it is used to select the best matching image.

| Value | Meaning |
| --- | --- |
| **LP_MONOCHROME** | Creates a monochrome picture to display on a monitor. |
| **LP_VGACOLOR** | Creates a 16-color picture to display on a monitor. |
| **LP_COLOR** | Creates a 256-color picture to display on a monitor. |
| **LP_DEFAULT** | Selects the best color depth to use for the current display. |

### `lplpdispPicture` [out]

The location that receives a pointer to the picture.

## Return value

This method returns standard COM error codes in addition to the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **DISP_E_PARAMNOTFOUND** | *varFileName* is not valid. |

## Remarks

Recognized graphic formats include bitmap (.bmp), JPEG (.jpg), GIF (.gif), and PGN (.png) files.