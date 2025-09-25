# IDeviceTopology::GetConnector

## Description

The **GetConnector** method gets the connector that is specified by a connector number.

## Parameters

### `nIndex` [in]

The connector number. If a device topology contains n connectors, the connectors are numbered 0 to n – 1. To get the number of connectors in the device topology, call the [IDeviceTopology::GetConnectorCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getconnectorcount) method.

### `ppConnector` [out]

Pointer to a pointer variable into which the method writes the address of the [IConnector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector) interface of the connector object. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetConnector** call fails, **ppConnector* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nIndex* is out of range. |
| **E_POINTER** | Pointer *ppConnector* is **NULL**. |

## Remarks

For code examples that call the **GetConnector** method, see the implementations of the GetHardwareDeviceTopology and SelectCaptureDevice functions in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)

[IDeviceTopology Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicetopology)

[IDeviceTopology::GetConnectorCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-idevicetopology-getconnectorcount)