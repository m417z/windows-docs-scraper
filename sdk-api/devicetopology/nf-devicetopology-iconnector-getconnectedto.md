# IConnector::GetConnectedTo

## Description

The **GetConnectedTo** method gets the connector to which this connector is connected.

## Parameters

### `ppConTo` [out]

Pointer to a pointer variable into which the method writes the address of the [IConnector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector) interface of the other connector object. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **GetConnectedTo** call fails, **ppConTo* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppConTo* is **NULL**. |
| **E_NOTFOUND** | This connector is not connected, or the other side of the connection is not another device topology (for example, a Software_IO connection). |
| **HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)** | The device topology on the other side of the connection is not active (that is, the device state is not DEVICE_STATE_ACTIVE). |

## Remarks

For code examples that call this method, see the implementations of the GetHardwareDeviceTopology and SelectCaptureDevice functions in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

For information about Software_IO connections, see [ConnectorType Enumeration](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-connectortype). For information about the HRESULT_FROM_WIN32 macro, see the Windows SDK documentation. For information about the DEVICE_STATE_NOTPRESENT device state, see [DEVICE_STATE_XXX Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/device-state-xxx-constants).

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)