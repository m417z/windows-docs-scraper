# IWICBitmapFrameEncode::Commit

## Description

Commits the frame to the image.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After the frame **Commit** has been called, you can't use or reinitialize the [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) object and any objects created from it.

To finalize the image, both the frame **Commit** and the encoder [Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-commit) must be called. However, only call the encoder **Commit** method after all frames have been committed.

## See also

[Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-commit)

[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)