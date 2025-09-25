# IAudioMeterInformation::GetChannelsPeakValues

## Description

The **GetChannelsPeakValues** method gets the peak sample values for all the channels in the audio stream.

## Parameters

### `u32ChannelCount` [in]

The channel count. This parameter also specifies the number of elements in the *afPeakValues* array. If the specified count does not match the number of channels in the stream, the method returns error code E_INVALIDARG.

### `afPeakValues` [out]

Pointer to an array of peak sample values. The method writes the peak values for the channels into the array. The array contains one element for each channel in the stream. The peak values are numbers in the normalized range from 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *u32ChannelCount* does not equal the number of channels in the audio stream. |
| **E_POINTER** | Parameter *afPeakValues* is **NULL**. |

## Remarks

This method retrieves the peak sample values for the channels in the stream. The peak value for each channel is recorded over one device period and made available during the subsequent device period. Thus, this method always retrieves the peak values recorded during the previous device period. To obtain the device period, call the [IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod) method.

Parameter *afPeakValues* points to a caller-allocated **float** array. If the stream contains *n* channels, the channels are numbered 0 to *n*– 1. The method stores the peak value for each channel in the array element whose array index matches the channel number. To get the number of channels in the audio stream that are monitored by peak meters, call the [IAudioMeterInformation::GetMeteringChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudiometerinformation-getmeteringchannelcount) method.

## See also

[IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod)

[IAudioMeterInformation Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation)

[IAudioMeterInformation::GetMeteringChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudiometerinformation-getmeteringchannelcount)