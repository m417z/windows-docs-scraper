# HistogramBlobHeader structure

## Description

The **HistogramBlobHeader** structure describes the blob size and the number of histograms in the blob for the **MF_CAPTURE_METADATA_HISTOGRAM** attribute.

## Members

### `Size`

Size of the entire histogram blob in bytes.

### `Histograms`

Number of histograms in the blob. Each histogram is identified by a [HistogramHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramheader).

## See also

[HistogramDataHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramdataheader)

[HistogramGrid](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-histogramgrid)