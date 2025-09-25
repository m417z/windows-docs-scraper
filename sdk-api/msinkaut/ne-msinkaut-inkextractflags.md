# InkExtractFlags enumeration

## Description

Determines how a stroke is removed from an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Constants

### `IEF_CopyFromOriginal:0`

The ink is copied from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

### `IEF_RemoveFromOriginal:0x1`

The ink is cut from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

### `IEF_Default`

The ink is cut from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Remarks

This enumeration is a flag.

## See also

[ExtractStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-extractstrokes)

[ExtractWithRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-extractwithrectangle)