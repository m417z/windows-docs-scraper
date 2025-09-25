# IWCNDevice::Connect

## Description

The **IWCNDevice::Connect** method initiates the session.

## Parameters

### `pNotify` [in]

A pointer to the implemented [IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify) callback interface which specifies if a connection has been successfully established.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation has succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support the connection options queued via IWCNDevice::Set. |
| **WCN_E_PEER_NOT_FOUND** | The device could not be located on the network. |

## Remarks

After calling this method you may not call any other [IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice) 'Set' methods. There is no way to cancel or roll back device settings once a connection has been established.

**NULL** can be passed via pNotify, in place of the [IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify) callback interface to prevent notification from being sent when the connect operation is complete.

## See also

[IWCNConnectNotify](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcnconnectnotify)

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)