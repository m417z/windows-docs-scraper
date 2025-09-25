# IMFMediaType::IsCompressedFormat

## Description

Queries whether the media type is a temporally compressed format.Temporal compression uses information from previously decoded samples when decompressing the current sample.

## Parameters

### `pfCompressed` [out]

Receives a Boolean value. The value is **TRUE** if the format uses temporal compression, or **FALSE** if the format does not use temporal compression.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns **FALSE** in *pfCompressed* if the media type's [MF_MT_ALL_SAMPLES_INDEPENDENT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-all-samples-independent-attribute) attribute is **TRUE**. If the **MF_MT_ALL_SAMPLES_INDEPENDENT** attribute is **FALSE** or not set, the method returns **TRUE**.

If the method returns **TRUE** in *pfCompressed*, it is a hint that the format has temporal compression applied to it. If the method returns **FALSE**, the format does not use temporal compression, although it might use intra-frame compression.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)