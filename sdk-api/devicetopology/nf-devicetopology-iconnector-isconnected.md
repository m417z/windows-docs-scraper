# IConnector::IsConnected

## Description

The **IsConnected** method indicates whether this connector is connected to another connector.

## Parameters

### `pbConnected` [out]

Pointer to a **BOOL** variable into which the method writes the connection state. If the state is **TRUE**, this connector is connected to another connector. If **FALSE**, this connector is unconnected.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pbConnected* is **NULL**. |

## Remarks

For a code example that calls the **IsConnected** method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)