# IDataCollectorSetCollection::GetDataCollectorSets

## Description

Populates the data collector set collection.

## Parameters

### `server` [in]

The computer whose data collector sets you want to enumerate. You can specify a computer name, a fully qualified domain name, or an IP address (IPv4 or IPv6 format). If **NULL**, PLA enumerates the sets on the local computer.

### `filter` [in]

If empty, PLA enumerates sets from all namespaces; otherwise, specify a specific namespace to enumerate. The form is <namespace>\*. For possible namespace values, see [IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit).

## Return value

Returns S_OK if successful. The following table shows possible error values.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(RPC_S_SERVER_UNAVAILABLE)** | The RPC server is not available. The method is unable to query the data collector set remotely. To query the data collector set from a remote computer running Windows Vista, enable Performance Logs and Alerts in **Windows Firewall Settings** on the remote computer. |
| **HRESULT_FROM_WIN32(ERROR_BAD_NETPATH)** | Unable to find the remote computer. |

## Remarks

The method enumerates only those sets that have been previously saved using [IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit).

 The retrieved data collector sets overwrite the contents of this instance. The instance must be empty (newly created) or be from the same namespace.

## See also

[IDataCollectorSetCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorsetcollection)