## Description

Translates an application-supplied RGBQuad into the device [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space).

## Parameters

### `hcmTransform`

Specifies the transform to be used.

### `ColorRef`

The RGBQuad to translate.

### `lpColorRef`

Points to a buffer in which to place the translation.

### `dwFlags`

Specifies how the transform should be used to make the translation. This parameter can take one of the following meanings.

| Value | Meaning |
| --- | --- |
| **CMS_FORWARD** | Use forward transform |
| **CMS_BACKWARD** | Use reverse transform |

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. The CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

Every CMM is required to export this function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)