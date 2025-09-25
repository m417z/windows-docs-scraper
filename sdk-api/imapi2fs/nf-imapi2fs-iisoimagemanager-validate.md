# IIsoImageManager::Validate

## Description

Determines if the provided .iso image is valid.

## Return value

This method can return one of these values.

| Return code | Description |
|-------------|-------------|
| **IMAPI_E_IMAGEMANAGER_IMAGE_NOT_ALIGNED** | The image is not aligned on a 2kb sector boundary. |
| **IMAPI_E_IMAGEMANAGER_NO_VALID_VD_FOUND** | The image does not contain a valid volume descriptor. |
| **IMAPI_E_IMAGEMANAGER_NO_IMAGE** | The image has not been set using the [SetPath](https://learn.microsoft.com/windows/win32/api/imapi2fs/nf-imapi2fs-iisoimagemanager-setpath) or [SetStream](https://learn.microsoft.com/windows/win32/api/imapi2fs/nf-imapi2fs-iisoimagemanager-setstream) method prior to calling this method. |
| **IMAPI_E_IMAGEMANAGER_IMAGE_TOO_BIG** | The provided image is too large to be validated as the size exceeds MAXLONG. |

## Remarks

For this method to succeed, the disc image, which may be a file or a stream, must meet the following criteria:

- The disc image size must be a multiple of the sector user data size, 2048 bytes.
- The disc image must contain user data only and no sector header or file header.
- The disc image must contain a valid Volume Recognition Sequence with at least one Volume Descriptor such as described in ECMA [119](https://www.ecma-international.org/wp-content/uploads/ECMA-119_2nd_edition_december_1987.pdf), [167](https://www.ecma-international.org/publications-and-standards/standards/ecma-167/), [168](https://www.ecma-international.org/publications-and-standards/standards/ecma-168/) standards.

If the disc image does not fit these criteria, this method will return the relevant failure code. More importantly, a failure to validate will affect the probability of operation success when the image is mounted by Windows after recording.

## See also

- [IIsoImageManager](https://learn.microsoft.com/windows/win32/api/imapi2fs/nn-imapi2fs-iisoimagemanager)
- [SetPath](https://learn.microsoft.com/windows/win32/api/imapi2fs/nf-imapi2fs-iisoimagemanager-setpath)
- [SetStream](https://learn.microsoft.com/windows/win32/api/imapi2fs/nf-imapi2fs-iisoimagemanager-setstream)