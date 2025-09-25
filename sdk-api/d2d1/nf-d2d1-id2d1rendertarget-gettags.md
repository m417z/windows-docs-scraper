# ID2D1RenderTarget::GetTags

## Description

Gets the label for subsequent drawing operations.

## Parameters

### `tag1` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-tag)***

When this method returns, contains the first label for subsequent drawing operations. This parameter is passed uninitialized. If **NULL** is specified, no value is retrieved for this parameter.

### `tag2` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-tag)***

When this method returns, contains the second label for subsequent drawing operations. This parameter is passed uninitialized. If **NULL** is specified, no value is retrieved for this parameter.

## Remarks

If the same address is passed for both parameters, both parameters receive the value of the second tag.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)