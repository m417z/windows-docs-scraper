# IConnector::ConnectTo

## Description

The **ConnectTo** method connects this connector to a connector in another device-topology object.

## Parameters

### `pConnectTo` [in]

The other connector. This parameter points to the [IConnector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector) interface of the connector object that represents the connector in the other device topology. The caller is responsible for releasing its counted reference to the **IConnector** interface when it is no longer needed. The **ConnectTo** method obtains its own reference to this interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pConnectTo* is **NULL**. |
| **E_INVALIDARG** | The current connector and remote connector pointed to by *pConnectTo*, have the same direction of data flow. A connector with data-flow direction "In" must be connected to another connector with data-flow direction "Out" to create a valid connection in the topology. To determine the data flow of a connector, call [IConnector::GetDataFlow](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-getdataflow). |
| **E_NOINTERFACE** | The object pointed to by *pConnectTo* is not a valid connector object. |
| **HRESULT_FROM_WIN32(ERROR_DEVICE_ALREADY_ATTACHED)** | One of the two connectors is already attached to another connector. For information about this macro, see the Windows SDK documentation. |

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)