# PICTUREATTRIBUTES enumeration

## Description

Specifies attributes of a picture object as returned through the [IPicture::get_Attributes](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-get_attributes) method.

## Constants

### `PICTURE_SCALABLE:0x1`

The picture object is scalable, such that it can be redrawn with a different size than was used to create the picture originally. Metafile-based pictures are considered scalable; icon and bitmap pictures, while they can be scaled, do not express this attribute because both involve bitmap stretching instead of true scaling.

### `PICTURE_TRANSPARENT:0x2`

The picture object contains an image that has transparent areas, such that drawing the picture will not necessarily fill in all the spaces in the rectangle it occupies. Metafile and icon pictures have this attribute; bitmap pictures do not.

## See also

[IPicture::get_Attributes](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-get_attributes)