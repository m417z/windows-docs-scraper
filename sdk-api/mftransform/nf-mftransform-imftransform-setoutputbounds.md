# IMFTransform::SetOutputBounds

## Description

Sets the range of time stamps the client needs for output.

## Parameters

### `hnsLowerBound`

Specifies the earliest time stamp. The Media Foundation transform (MFT) will accept input until it can produce an output sample that begins at this time; or until it can produce a sample that ends at this time or later. If there is no lower bound, use the value **MFT_OUTPUT_BOUND_LOWER_UNBOUNDED**.

### `hnsUpperBound`

Specifies the latest time stamp. The MFT will not produce an output sample with time stamps later than this time. If there is no upper bound, use the value **MFT_OUTPUT_BOUND_UPPER_UNBOUNDED**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |

## Remarks

This method can be used to optimize preroll, especially in formats that have gaps between time stamps, or formats where the data must start on a sync point, such as MPEG-2. Calling this method is optional, and implementation of this method by an MFT is optional. If the MFT does not implement the method, the return value is **E_NOTIMPL**.

If an MFT implements this method, it must limit its output data to the range of times specified by *hnsLowerBound* and *hnsUpperBound*. The MFT discards any input data that is not needed to produce output within this range. If the sample boundaries do not exactly match the range, the MFT should split the output samples, if possible. Otherwise, the output samples can overlap the range.

For example, suppose the output range is 100 to 150 milliseconds (ms), and the output format is video with each frame lasting 33 ms. A sample with a time stamp of 67 ms overlaps the range (67 + 33 = 100) and is produced as output. A sample with a time stamp of 66 ms is discarded (66 + 33 = 99). Similarly, a sample with a time stamp of 150 ms is produced as output, but a sample with a time stamp of 151 is discarded.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTSetOutputBounds**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)