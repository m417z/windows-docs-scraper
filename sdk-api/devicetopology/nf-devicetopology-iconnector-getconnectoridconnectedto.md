# IConnector::GetConnectorIdConnectedTo

## Description

The **GetConnectorIdConnectedTo** method gets the global ID of the connector, if any, that this connector is connected to.

## Parameters

### `ppwstrConnectorId` [out]

Pointer to a string pointer into which the method writes the address of a null-terminated, wide-character string that contains the other connector's global ID. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetConnectorIdConnectedTo** call fails, **ppwstrConnectorId* is **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_NOTFOUND** | This connector is not connected, or the other side of the connection is not another device topology (for example, a Software_IO connection). |
| **E_POINTER** | Parameter *ppwstrConnectorId* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

A global ID is a string that uniquely identifies a part among all parts in all device topologies in the system. Clients should treat this string as opaque. That is, clients should not attempt to parse the contents of the string to obtain information about the part. The reason is that the string format is undefined and might change from one implementation of the DeviceTopology API to the next.

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)