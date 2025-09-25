# WmfPlaceableFileHeader structure

## Description

The **WmfPlaceableFileHeader** structure defines the fields of a placeable metafile header. Placeable metafiles were created as a way of specifying how a metafile is mapped and scaled on a display device.

## Members

### `Key`

Type: **UINT32**

Identification value that indicates the presence of a placeable metafile header. This value is always 0x9AC6CDD7.

### `Hmf`

Type: **INT16**

Handle to the metafile in memory. When written to disk, this field is not used and will always contains the value 0.

### `BoundingBox`

Type: **[PWMFRect16](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-pwmfrect16)**

Destination rectangle, measured in twips, for displaying the metafile.

### `Inch`

Type: **INT16**

Number of twips per inch used to represent the image.

Normally, there are 1440 twips per inch; however, this number can be changed to scale the image.

* A value of 720 specifies that the image is twice its normal size.
* A value of 360 specifies that the image is four times its normal size.
* A value of 2880 specifies that the image is half its normal size.

### `Reserved`

Type: **UINT32**

Not used and is always set to 0.

### `Checksum`

Type: **INT16**

Checksum for the previous 10 **WORD****s** in the header. This value can be used to determine whether the metafile has become corrupted.

## Remarks

Although placeable metafiles are quite common, they are not directly supported by the Windows API. To display a placeable metafile using the Windows API, you must first strip the placeable metafile header from the file. This is typically performed by copying the metafile to a temporary file starting at file offset 22 (0x16). This is because each placeable metafile begins with a 22-byte header that is followed by a standard metafile.

## See also

[PWMFRect16](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-pwmfrect16)