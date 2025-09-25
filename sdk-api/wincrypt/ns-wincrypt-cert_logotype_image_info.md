# CERT_LOGOTYPE_IMAGE_INFO structure

## Description

The **CERT_LOGOTYPE_IMAGE_INFO** structure contains more detailed information about an image logotype.

## Members

### `dwLogotypeImageInfoChoice`

Specifies the type of image. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE** | The image is a grayscale image. |
| **CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE** | The image is a color image. |

### `dwFileSize`

The size, in octets, of the image.

### `dwXSize`

The horizontal size, in pixels, of the image.

### `dwYSize`

The vertical size, in pixels, of the image.

### `dwLogotypeImageResolutionChoice`

Specifies the format of the image resolution. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE** | No image resolution information is provided. |
| **CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE** | The image resolution is provided in bits per pixel. The **dwNumBits** member contains the image resolution. |
| **CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE** | The image resolution is provided in number of gray tones. The **dwTableSize** member contains the image resolution. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.dwNumBits`

The resolution of the image, in bits per pixel. The member is only used if the **dwLogotypeImageResolutionChoice** contains **CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE**.

### `DUMMYUNIONNAME.dwTableSize`

The resolution of the image, in number of gray tones. The member is only used if the **dwLogotypeImageResolutionChoice** contains **CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE**.

### `pwszLanguage`

The address of a null-terminated IA5 string that contains the RFC 3066 language identifier that specifies the language of the image. This member is optional and may be **NULL**.

## See also

[CERT_LOGOTYPE_IMAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_image)