# IWICProgressiveLevelControl::SetCurrentLevel

## Description

Specifies the level to retrieve on the next call to [CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels).

## Parameters

### `nLevel` [in]

Type: **UINT**

Specifies which level to return next. If greater than the total number of levels supported, an error will be returned.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A call does not have to request every level supported.
If a caller requests level 1, without having previously requested level 0, the bits returned by the next call to [CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) will include both levels.

If the requested level is invalid, the error returned is [WINCODEC_ERR_INVALIDPROGRESSIVELEVEL](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-error-codes).

#### Examples

Users should use this method to iterate through the progressive levels of a progressive JPEG image rather than the [GetCurrentLevel](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicprogressivelevelcontrol-getcurrentlevel) method. JPEG progressive levels are determined by the image and do not have a fixed level count.
Using **GetCurrentLevel** method will force the application to wait for all progressive levels to be downloaded before it can return.
Instead, applications should use the following code to iterate through the progressive levels of a progressive JPEG image.

```
IWICProgressiveLevelControl *pProgressive = NULL;

HRESULT hr = (pBitmapFrame->QueryInterface(
   IID_IWICProgressiveLevelControl,
   (void**) &pProgressive));

if (SUCCEEDED(hr))
{
   for (UINT uCurrentLevel = 0; SUCCEEDED(hr); uCurrentLevel++)
   {
      hr = pProgressive->SetCurrentLevel(uCurrentLevel);
      if (WINCODEC_ERR_INVALIDPROGRESSIVELEVEL == hr)
      {
         // No more levels
         break;
      }

      if (SUCCEEDED(hr))
      {
         // Output the current level
         hr = pBitmapFrame->CopyPixels(...);
      }
   }
}

if (pProgressive)
{
   pProgressive->Release();
}	

```

## See also

[IWICProgressiveLevelControl](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicprogressivelevelcontrol)

[Progressive Decoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-progressive-decoding)