# ID2D1RenderTarget::Flush

## Description

Executes all pending drawing commands.

## Parameters

### `tag1` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-tag)***

When this method returns, contains the tag for drawing operations that caused errors or 0 if there were no errors. This parameter is passed uninitialized.

### `tag2` [out, optional]

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-tag)***

When this method returns, contains the tag for drawing operations that caused errors or 0 if there were no errors. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code and sets *tag1* and *tag2* to the tags that were active when the error occurred. If no error occurred, this method sets the error tag state to be (0,0).

## Remarks

This command does not flush the Direct3D device context that is associated with the render target.

Calling this method resets the error state of the render target.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)