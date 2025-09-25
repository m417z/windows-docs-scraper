# HistogramFormat enumeration

## Description

The **HistogramFormat** enumeration specifies the number and type of histograms that represent the color channels of a bitmap. This enumeration is used with the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method.

## Constants

### `HistogramFormatARGB`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns four histograms: one each for the alpha, red, green, and blue channels. The alpha-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The red-channel histogram is written to the buffer pointed to by the *channel1* parameter. The green-channel histogram is written to the buffer pointed to by the *channel2* parameter. The blue-channel histogram is written to the buffer pointed to by the *channel3* parameter.

### `HistogramFormatPARGB`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns four histograms: one each for the alpha, red, green, and blue channels. The red, green, and blue channels are each multiplied by the alpha channel before the histograms are created. The bitmap is not permanently altered when the color channels are multiplied by the alpha channel; that multiplication is only for the purpose of creating the histograms. The alpha-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The red-channel histogram is written to the buffer pointed to by the *channel1* parameter. The green-channel histogram is written to the buffer pointed to by the *channel2* parameter. The blue-channel histogram is written to the buffer pointed to by the *channel3* parameter.

### `HistogramFormatRGB`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns three histograms: one each for the red, green, and blue channels. The red-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The green-channel histogram is written to the buffer pointed to by the *channel1* parameter. The blue-channel histogram is written to the buffer pointed to by the *channel2* parameter. The *channel3* parameter must be set to **NULL**.

### `HistogramFormatGray`

Specifies that each pixel is converted to a grayscale value in the range 0 through 255, and then one histogram, based on those grayscale value, is returned. The bitmap is not permanently altered by the conversion to grayscale values; those values are calculated only for the purpose of creating the histogram. The grayscale histogram is written to the buffer pointed to by the *channel0* parameter of the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method. The *channel1*, *channel2*, and *channel3* parameters must be set to **NULL**.

### `HistogramFormatB`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns a histogram for the blue channel. The blue-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The *channel1*, *channel2*, and *channel3* parameters must be set to **NULL**.

### `HistogramFormatG`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns a histogram for the green channel. The green-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The *channel1*, *channel2*, and *channel3* parameters must be set to **NULL**.

### `HistogramFormatR`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns a histogram for the red channel. The red-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The *channel1*, *channel2*, and *channel3* parameters must be set to **NULL**.

### `HistogramFormatA`

Specifies that the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method returns a histogram for the alpha channel. The alpha-channel histogram is written to the buffer pointed to by the *channel0* parameter of the **Bitmap::GetHistogram** method. The *channel1*, *channel2*, and *channel3* parameters must be set to **NULL**.