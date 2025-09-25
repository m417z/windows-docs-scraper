# IWICProgressiveLevelControl::GetLevelCount

## Description

Gets the number of levels of progressive decoding supported by the CODEC.

## Parameters

### `pcLevels` [out, retval]

Type: **UINT***

Indicates the number of levels supported by the CODEC.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Users should not use this function to iterate through the progressive levels of a progressive JPEG image. JPEG progressive levels are determined by the image and do not have a fixed level count. Using this method will force the application to wait for all progressive levels to be downloaded before it can return. Instead, applications should use the following code to iterate through the progressive levels of a progressive JPEG image.

#### Examples

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