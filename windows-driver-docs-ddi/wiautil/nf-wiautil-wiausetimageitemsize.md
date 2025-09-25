# wiauSetImageItemSize function

## Description

The **wiauSetImageItemSize** function calculates the size and width, in bytes, for an image, based on the current WIA_IPA_FORMAT setting (described in the Microsoft Windows SDK documentation), and writes the new values to the appropriate properties.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `lWidth`

Specifies the width of the image, in pixels.

### `lHeight`

Specifies the height of the image, in pixels.

### `lDepth`

Specifies the depth of the image, in bits.

### `lSize`

Specifies the size of the image as stored on the device.

### `pwszExt` [in, optional]

*Optional*. Pointer to a memory location containing a three-character file name extension for the item's native format. If this parameter is **NULL**, the item's extension property, WIA_IPA_FILENAME_EXTENSION (described in the Windows SDK documentation), is not updated.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## Remarks

If the format is not BMP, this function assumes that the value passed in the *lSize* parameter is correct for the current format.