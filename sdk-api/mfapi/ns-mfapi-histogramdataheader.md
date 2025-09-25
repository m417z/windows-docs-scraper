# HistogramDataHeader structure

## Description

The **HistogramDataHeader** structure describes the blob format for the **MF_CAPTURE_METADATA_HISTOGRAM** attribute.

## Members

### `Size`

Size in bytes of this header + all following histogram data.

### `ChannelMask`

Mask of the color channel for the histogram data.

### `Linear`

1 if linear, 0 if nonlinear.

## See also

[HistogramBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramblobheader)

[HistogramGrid](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramgrid)

[HistogramHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramheader)