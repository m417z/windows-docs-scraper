# HistogramHeader structure

## Description

The **HistogramHeader** structure describes the blob format for **MF_CAPTURE_METADATA_HISTOGRAM**.

## Members

### `Size`

Size of this header + ([HistogramDataHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramdataheader) + histogram data following) * number of channels available.

### `Bins`

Number of bins in the histogram.

### `FourCC`

Color space that the histogram is collected from

### `ChannelMasks`

Masks of the color channels that the histogram is collected for.

### `Grid`

Grid that the histogram is collected from.

## Remarks

The **MF_CAPTURE_METADATA_HISTOGRAM** attribute contains a histogram when a preview frame is captured.

For the **ChannelMasks** field, the following bitmasks indicate the available channels in the histogram:

```
#define MF_HISTOGRAM_CHANNEL_Y  0x00000001
#define MF_HISTOGRAM_CHANNEL_R  0x00000002
#define MF_HISTOGRAM_CHANNEL_G  0x00000004
#define MF_HISTOGRAM_CHANNEL_B  0x00000008
#define MF_HISTOGRAM_CHANNEL_Cb 0x00000010
#define MF_HISTOGRAM_CHANNEL_Cr 0x00000020
```

Each blob can contain multiple histograms collected from different regions or different color spaces of the same frame. Each histogram in the blob is identified by its own **HistogramHeader**. Each histogram has its own region and sensor output size associated. For full frame histogram, the region will match the sensor output size specified in [HistogramGrid](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramgrid).

Histogram data for all available channels are grouped under one histogram. Histogram data for each channel is identified by a [HistogramDataHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramdataheader) immediate above the data. **ChannelMasks** indicate how many and what channels are having the histogram data, which is the bitwise OR of the supported **MF_HISTOGRAM_CHANNEL_*** bitmasks as defined above. **ChannelMask** indicates what channel the data is for, which is identified by any one of the **MF_HISTOGRAM_CHANNEL_*** bitmasks.

Histogram data is an array of **ULONG** with each entry representing the number of pixels falling under a set of tonal values as categorized by the bin. The data in the array should start from bin 0 to bin N-1, where N is the number of bins in the histogram, for example, **HistogramBlobHeader.Bins**.

For Windows 10, if [KSPROPERTY_CAMERACONTROL_EXTENDED_HISTOGRAM](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-histogram) is supported, at minimum a full frame histogram with Y channel must be provided which should be the first histogram in the histogram blob.
Note that [HistogramBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramblobheader), **HistogramHeader**, [HistogramDataHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramdataheader) and Histogram data only describe the blob format for the **MF_CAPTURE_METADATA_HISTOGRAM** attribute. The metadata item structure for the histogram ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + all histogram metadata payload) is up to driver and must be 8-byte aligned.

## See also

[HistogramBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramblobheader)

[HistogramDataHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramdataheader)

[HistogramGrid](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramgrid)