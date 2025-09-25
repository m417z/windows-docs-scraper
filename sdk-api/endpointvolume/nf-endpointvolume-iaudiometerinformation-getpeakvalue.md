# IAudioMeterInformation::GetPeakValue

## Description

The **GetPeakValue** method gets the peak sample value for the channels in the audio stream.

## Parameters

### `pfPeak` [out]

Pointer to a **float** variable into which the method writes the peak sample value for the audio stream. The peak value is a number in the normalized range from 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfPeak* is **NULL**. |

## Remarks

This method retrieves the peak sample value recorded across all of the channels in the stream. The peak value for each channel is recorded over one device period and made available during the subsequent device period. Thus, this method always retrieves the peak value recorded during the previous device period. To obtain the device period, call the [IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod) method.

For a code example that uses the **GetPeakValue** method, see [Peak Meters](https://learn.microsoft.com/windows/desktop/CoreAudio/peak-meters).

## See also

[IAudioClient::GetDevicePeriod](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getdeviceperiod)

[IAudioMeterInformation Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation)