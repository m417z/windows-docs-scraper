# IWICProgressCallback::Notify

## Description

**Notify** method is documented only for compliance; its use is not recommended and may be altered or unavailable in the future. Instead, and use [RegisterProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapcodecprogressnotification-registerprogressnotification).

## Parameters

### `uFrameNum` [in]

Type: **ULONG**

The current frame number.

### `operation` [in]

Type: **[WICProgressOperation](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressoperation)**

The operation on which progress is being reported.

### `dblProgress` [in]

Type: **double**

The progress value ranging from is 0.0 to 1.0. 0.0 indicates the beginning of the operation. 1.0 indicates the end of the operation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWICProgressCallback](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicprogresscallback)