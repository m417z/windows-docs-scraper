# Bitmap::GetHistogram

## Description

The **Bitmap::GetHistogram** method returns one or more histograms for specified color channels of this [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## Parameters

### `format` [in]

Type: **[HistogramFormat](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-histogramformat)**

Element of the [HistogramFormat](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-histogramformat) enumeration that specifies the channels for which histograms will be created.

### `NumberOfEntries` [in]

Type: **UINT**

Integer that specifies the number of elements (of type **UINT**) in each of the arrays pointed to by *channel0*, *channel1*, *channel2*, and *channel3*. You must allocate memory for those arrays before you call **Bitmap::GetHistogram**. To determine the required number of elements, call [Bitmap::GetHistogramSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogramsize).

### `channel0` [out]

Type: **UINT***

Pointer to an array of **UINT**s that receives the first histogram.

### `channel1` [out]

Type: **UINT***

Pointer to an array of **UINT**s that receives the second histogram if there is a second histogram. Pass **NULL** if there is no second histogram.

### `channel2` [out]

Type: **UINT***

Pointer to an array of **UINT**s that receives the third histogram if there is a third histogram. Pass **NULL** if there is no third histogram.

### `channel3` [out]

Type: **UINT***

Pointer to an array of **UINT**s that receives the fourth histogram if there is a fourth histogram. Pass **NULL** if there is no fourth histogram.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The number of histograms returned depends on the [HistogramFormat](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-histogramformat) enumeration element passed to the *format* parameter. For example, if *format* is equal to **HistogramFormatRGB**, then three histograms are returned: one each for the red, green, and blue channels. In that case, *channel0* points to the array that receives the red-channel histogram, *channel1* points to the array that receives the green-channel histogram, and *channel2* points to the array that receives the blue-channel histogram. For **HistogramFormatRGB**, *channel3* must be set to **NULL** because there is no fourth histogram. For more details, see the **HistogramFormat** enumeration.

#### Examples

The following example constructs a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object from a BMP file. The code retrieves three histograms from the bitmap: one each for the red, green, and blue channels. Note the order of RGB in the name of the enumeration element **HistogramFormatRGB**. R is first, so it corresponds with **ch0**. Green is second, so it corresponds with **ch1**. Blue is third, so it corresponds with **ch2**. The final parameter passed to **Bitmap::GetHistogram** is **NULL** because there is no fourth histogram.

```cpp
Bitmap myBitmap(L"Picture.bmp");

UINT numEntries;
myBitmap.GetHistogramSize(HistogramFormatRGB, &numEntries);

UINT* ch0 = new UINT[numEntries];
UINT* ch1 = new UINT[numEntries];
UINT* ch2 = new UINT[numEntries];

myBitmap.GetHistogram(HistogramFormatRGB, numEntries, ch0, ch1, ch2, NULL);

// Print the histogram values for the three channels: red, green, blue.
for(UINT j = 0; j < numEntries; ++j)
{
   printf("%u\t%u\t%u\t%u\n", j, ch0[j], ch1[j], ch2[j]);
}

delete ch0;
delete ch1;
delete ch2;
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)