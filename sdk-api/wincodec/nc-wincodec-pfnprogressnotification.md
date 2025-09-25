# PFNProgressNotification callback function

## Description

Application defined callback function called when codec component progress is made.

## Parameters

### `pvData`

Type: **LPVOID**

Component data passed to the callback function.

### `uFrameNum`

Type: **ULONG**

The current frame number.

### `operation`

Type: **[WICProgressOperation](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressoperation)**

The current operation the component is in.

### `dblProgress`

Type: **double**

The progress value. The range is 0.0 to 1.0.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An operation can be canceled by returning `WINCODEC_ERR_ABORTED`.

To register your callback function, query the encoder or decoder for the [IWICBitmapCodecProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapcodecprogressnotification) interface and call [RegisterProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapcodecprogressnotification-registerprogressnotification).

## See also

**Reference**

[WICProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressnotification)

[WICProgressOperation](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressoperation)