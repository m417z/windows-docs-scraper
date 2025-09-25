# IDataCollectorSet::Delete

## Description

Deletes the persisted copy of the data collector set if the set is not running.

## Return value

Returns S_OK if successful. The following table shows a possible error value.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(RPC_S_SERVER_UNAVAILABLE)** | The RPC server is not available. The method is unable to delete the data collector set remotely. To delete the data collector set on a remote computer running Windows Vista, enable Performance Logs and Alerts in **Windows Firewall Settings** on the remote computer. |

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_status)