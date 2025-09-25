# PeerGraphUpdateRecord function

## Description

The **PeerGraphUpdateRecord** function updates a record in the peer graph and then floods the record to each node in the peer graph.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `pRecord` [in]

Pointer to a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure that contains the new data for the record.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_GRAPH_NOT_READY** | The peer graph has never been synchronized. Records cannot be updated until the graph has been synchronized. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |
| **PEER_E_RECORD_NOT_FOUND** | The specified record was not found. |

## Remarks

The following members of the [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure can be modified:

* **pwzAttributes**
* **ftExpiration** - the expiration can only be increased
* **data**
* **pwzLastModified** - filled in by default if no value is supplied

#### Examples

This code snippet shows how to update a record.

```cpp
// dwFlags is updated to automatically refresh the record if it is about to expire.
    record.dwFlags = PEER_RECORD_FLAG_AUTOREFRESH;
    // The record data is updated with the string contained in pwzUserData.
    record.data.cbData = (ULONG) wcslen(pwzUserData) * sizeof(WCHAR);
    record.data.pbData = (PBYTE) pwzUserData;

    HRESULT hr = PeerGraphUpdateRecord(hGraph, &record;);

    if (FAILED(hr))
    {
        // Insert your code to handle the error here.
    }
    else
    {
        // Insert your application specific code here.
    }

```

## See also

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)