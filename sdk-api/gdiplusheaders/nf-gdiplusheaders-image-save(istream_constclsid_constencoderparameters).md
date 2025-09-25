# Image::Save(IN IStream,IN const CLSID,IN const EncoderParameters)

## Description

The **Image::Save** method saves this image to a stream.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an
**IStream** COM interface. The implementation of
**IStream** must include the
**Seek**,
**Read**,
**Write**, and
**Stat** methods.

### `clsidEncoder` [in]

Type: **const CLSID***

Pointer to a
**CLSID** that specifies the encoder to use to save the image.

### `encoderParams` [in]

Type: **const [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))***

Optional. Pointer to an [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object that holds parameters used by the encoder. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Do not save an image to the same stream that was used to construct the image. Doing so might damage the stream.

``` syntax
Image image(myStream);
...
image.Save(myStream, ...); // Do not do this.
```

#### Examples

The following example creates two
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) objects: one constructed from a JPEG file and one constructed from a PNG file. The code creates a compound file with two streams and saves the two images to those streams.

```cpp
Status MakeCompoundFile()
{
   IStorage* pIStorage = NULL;
   IStream* pIStream1 = NULL;
   IStream* pIStream2 = NULL;
   HRESULT hr;
   Status stat = Ok;

   // Create two Image objects from existing files.
   Image image1(L"Crayons.jpg");
   Image image2(L"Mosaic.png");

   hr = CoInitialize(NULL);
   if(FAILED(hr))
      goto Exit;

   // Create a compound file object, and get
   // a pointer to its IStorage interface.
   hr = StgCreateDocfile(
      L"CompoundFile.cmp",
      STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE,
      0,
      &pIStorage);

   if(FAILED(hr))
      goto Exit;

   // Create a stream in the compound file.
   hr = pIStorage->CreateStream(
      L"StreamImage1",
      STGM_READWRITE|STGM_SHARE_EXCLUSIVE,
      0,
      0,
      &pIStream1);

   if(FAILED(hr))
      goto Exit;

   // Create a second stream in the compound file.
   hr = pIStorage->CreateStream(
      L"StreamImage2",
      STGM_READWRITE|STGM_SHARE_EXCLUSIVE,
      0,
      0,
      &pIStream2);

   if(FAILED(hr))
      goto Exit;

   // Get the class identifier for the JPEG encoder.
   CLSID jpgClsid;
   GetEncoderClsid(L"image/jpeg", &jpgClsid);

   // Get the class identifier for the PNG encoder.
   CLSID pngClsid;
   GetEncoderClsid(L"image/png", &pngClsid);

   // Save image1 as a stream in the compound file.
   stat = image1.Save(pIStream1, &jpgClsid);
   if(stat != Ok)
      goto Exit;

   // Save image2 as a stream in the compound file.
   stat = image2.Save(pIStream2, &pngClsid);

Exit:
   if(pIStream1)
      pIStream1->Release();
   if(pIStream2)
      pIStream2->Release();
   if(pIStorage)
      pIStorage->Release();

   if(stat != Ok || FAILED(hr))
      return GenericError;

   return Ok;
}
```

## See also

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[GetImageEncodersSize](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoderssize)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::Save Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-save(inistream_inconstclsid_inconstencoderparameters))

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)