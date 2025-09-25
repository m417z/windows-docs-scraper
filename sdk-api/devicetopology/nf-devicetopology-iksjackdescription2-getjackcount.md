# IKsJackDescription2::GetJackCount

## Description

The **GetJackCount** method gets the number of jacks on the connector, which are required to connect to an endpoint device.

## Parameters

### `pcJacks` [out]

Receives the number of audio jacks associated with the connector.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pcJacks* is **NULL**. |

## See also

[IKsJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription2)