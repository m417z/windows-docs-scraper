## Description

The **CWiauFormatConverter::ConvertToBmp** method converts an image to BMP format.

## Parameters

### `pSource`

Points to the memory location containing the first byte of the source image.

### `iSourceSize`

Specifies the size, in bytes, of the source image.

### `ppDest`

Pointer to a memory location that receives the address of the resulting image.

### `piDestSize`

Pointer to a memory location that receives the size, in bytes, of the resulting image.

### `pBmpImageInfo`

Pointer to a [BMP_IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/ns-wiautil-_bmp_image_info) structure that receives information about the resulting image.

### `iSkipAmt`

Optional

Specifies the amount of the BMP header to skip. The default value of this parameter denotes that none of the BMP header is skipped.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## Remarks

The caller of this method can pass a result buffer in *ppDest* and the size in *piDestSize*.

Alternatively, the caller can set *ppDest* to **NULL** and *piDestSize* to zero in the call to indicate that this method should allocate the memory.

The caller is responsible for freeing the memory using the **delete []** operator.

## See also

[BMP_IMAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/ns-wiautil-_bmp_image_info)

[CWiauFormatConverter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540363(v=vs.85))

[CWiauFormatConverter::IsFormatSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiauformatconverter-isformatsupported)

[SKIP_AMOUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/ne-wiautil-skip_amount)