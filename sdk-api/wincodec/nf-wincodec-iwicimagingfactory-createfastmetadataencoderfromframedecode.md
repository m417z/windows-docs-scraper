# IWICImagingFactory::CreateFastMetadataEncoderFromFrameDecode

## Description

Creates a new instance of the fast metadata encoder based on the given image frame.

## Parameters

### `pIFrameDecoder` [in]

Type: **[IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode)***

The [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode) to create the [IWICFastMetadataEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicfastmetadataencoder) from.

### `ppIFastEncoder` [out]

Type: **[IWICFastMetadataEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicfastmetadataencoder)****

When this method returns, contains a pointer to a new fast metadata encoder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a list of support metadata formats for fast metadata encoding, see [WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata).

#### Examples

The following code demonstrates how to use the **CreateFastMetadataEncoderFromFrameDecode** method for fast metadata encoding.

```
IWICFastMetadataEncoder *pFME = NULL;
IWICMetadataQueryWriter *pFMEQW = NULL;

hr = pFactory->CreateFastMetadataEncoderFromFrameDecode(pFrameDecode, &pFME);

if (SUCCEEDED(hr))
{
  hr = pFME->GetMetadataQueryWriter(&pFMEQW);
}

if (SUCCEEDED(hr))
{
  // Add additional metadata
  PROPVARIANT value;

  PropVariantInit(&value);

  value.vt = VT_UI2;
  value.uiVal = 99;
  hr = pFMEQW->SetMetadataByName(L"/app1/ifd/{ushort=18249}", &value);

  PropVariantClear(&value);
}

if (SUCCEEDED(hr))
{
  hr = pFME->Commit();
}
```

## See also

**Conceptual**

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[Metadata Query Language Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-metadataquerylanguage)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)

[Writing Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)