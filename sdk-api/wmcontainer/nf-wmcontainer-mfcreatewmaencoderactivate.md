# MFCreateWMAEncoderActivate function

## Description

Creates an activation object that can be used to create a Windows Media Audio (WMA) encoder.

## Parameters

### `pMediaType`

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. This parameter specifies the encoded output format.

### `pEncodingConfigurationProperties`

A pointer to the **IPropertyStore** interface of a property store that contains encoding parameters. Encoding parameters for the WMV encoder are defined in the header file wmcodecdsp.h. If you have an ASF ContentInfo object that contains an ASF profile object with all the streams for the output file, you can get the property store by calling [IMFASFContentInfo::GetEncodingConfigurationPropertyStore](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-getencodingconfigurationpropertystore).

### `ppActivate`

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. Use this interface to create the encoder. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)