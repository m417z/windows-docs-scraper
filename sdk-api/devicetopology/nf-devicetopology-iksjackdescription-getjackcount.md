# IKsJackDescription::GetJackCount

## Description

The **GetJackCount** method gets the number of jacks required to connect to an audio endpoint device.

## Parameters

### `pcJacks` [out]

Pointer to a **UINT** variable into which the method writes the number of jacks associated with the connector.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pcJacks* is **NULL**. |

## Remarks

An audio endpoint device that plays or records a stream that contains multiple channels might require a connection with more than one jack (physical connector).

For example, a set of surround speakers that plays a 6-channel audio stream might require three stereo jacks. In this example, the first jack transmits the channels for the front-left and front-right speakers, the second jack transmits the channels for the front-center and low-frequency-effects (subwoofer) speakers, and the third jack transmits the channels for the side-left and side-right speakers.

After calling this method to retrieve the jack count, call the [IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription) method once for each jack to obtain a description of the jack.

## See also

[IKsJackDescription Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription)

[IKsJackDescription::GetJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iksjackdescription-getjackdescription)