# IConnector::GetDataFlow

## Description

The **GetDataFlow** method gets the direction of data flow through this connector.

## Parameters

### `pFlow` [out]

Pointer to a variable into which the method writes the data-flow direction. The direction is one of the following [DataFlow](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-dataflow) enumeration values:

In

Out

If data flows into the device through the connector, the data-flow direction is In. Otherwise, the data-flow direction is Out.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pFlow* is **NULL**. |

## Remarks

For a code example that calls this method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)