# OleLoadPictureFile function

## Description

Creates an **IPictureDisp** object from a picture file on disk.

## Parameters

### `varFileName` [in]

The path and name of the picture file to load.

### `lplpdispPicture` [out]

The location that receives a pointer to the **IPictureDisp** object.

## Return value

This method returns standard COM error codes in addition to the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CTL_E_INVALIDPICTURE** | Invalid picture file. |

## Remarks

Recognized graphic formats include bitmap (.bmp), JPEG (.jpg), GIF (.gif), and PGN (.png) files.