# IConnector::Disconnect

## Description

The **Disconnect** method disconnects this connector from another connector.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_NOTFOUND** | This connector is already disconnected. |
| **HRESULT_FROM_WIN32(ERROR_FILE_READ_ONLY)** | A permanent connection cannot be disconnected. For information about this macro, see the Windows SDK documentation. |

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)