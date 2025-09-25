# Image::SaveAdd(EncoderParameters*)

## Description

The **Image::SaveAdd** method adds a frame to a file or stream specified in a previous call to the **Save** method.
Use this method to save selected frames from a multiple-frame image to another multiple-frame image.

## Parameters

### `encoderParams`

Pointer to an [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object that holds parameters required by the image encoder used by the save-add operation.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a TIFF file that has four frames.
The code calls the *Image::SelectActiveFrame* method to navigate to the second frame in the page dimension of that Image object.
(The page dimension is the only dimension in this case.)
Then the code calls the **Save** method to save the second frame to a new file named `TwoFrames.tif`.
The code calls the **Image::SelectActiveFrame** method again to navigate to the fourth frame of the Image object.
Then the code calls the **Image::SaveAdd** method to add the fourth frame to `TwoFrames.tif`.
The code calls the **Image::SaveAdd** method a second time to close `TwoFrames.tif`, and then draws the two frames that were saved in that file.

```cpp
VOID Example_SaveAdd(HDC hdc)
{
   Graphics graphics(hdc);
   EncoderParameters encoderParameters;
   ULONG parameterValue;
   GUID dimension = FrameDimensionPage;

   // An EncoderParameters object has an array of
   // EncoderParameter objects. In this case, there is only
   // one EncoderParameter object in the array.
   encoderParameters.Count = 1;

   // Initialize the one EncoderParameter object.
   encoderParameters.Parameter[0].Guid = EncoderSaveFlag;
   encoderParameters.Parameter[0].Type = EncoderParameterValueTypeLong;
   encoderParameters.Parameter[0].NumberOfValues = 1;
   encoderParameters.Parameter[0].Value = &parameterValue;

   // Get the CLSID of the TIFF encoder.
   CLSID encoderClsid;
   GetEncoderClsid(L"image/tiff", &encoderClsid);

   // Create an image object based on a TIFF file that has four frames.
   Image fourFrames(L"FourFrames.tif");

   // Save the second page (frame).
   parameterValue = EncoderValueMultiFrame;
   fourFrames.SelectActiveFrame(&dimension, 1);
   fourFrames.Save(L"TwoFrames.tif", &encoderClsid, &encoderParameters);

   // Save the fourth page (frame).
   parameterValue = EncoderValueFrameDimensionPage;
   fourFrames.SelectActiveFrame(&dimension, 3);
   fourFrames.SaveAdd(&encoderParameters);

   // Close the multiframe file.
   parameterValue = EncoderValueFlush;
   fourFrames.SaveAdd(&encoderParameters);

   // Draw the two frames of TwoFrames.tif.
   Image twoFrames(L"TwoFrames.tif");
   twoFrames.SelectActiveFrame(&dimension, 0);
   graphics.DrawImage(&twoFrames, 10, 10);
   twoFrames.SelectActiveFrame(&dimension, 1);
   graphics.DrawImage(&twoFrames, 150, 10);
}
```

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[Image::Save Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-save(inistream_inconstclsid_inconstencoderparameters))

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)