# IDot11AdHocInterface::GetStatus

## Description

Gets the connection status of the active network associated with this NIC. You can determine the active network by calling [IDot11AdHocInterface::GetActiveNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocinterface-getactivenetwork).

## Parameters

### `pState` [in, out]

A pointer to a [DOT11_ADHOC_NETWORK_CONNECTION_STATUS](https://learn.microsoft.com/windows/win32/api/adhoc/ne-adhoc-dot11_adhoc_network_connection_status) value that specifies the connection state.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## See also

[IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface)

[IDot11AdHocInterface::GetActiveNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocinterface-getactivenetwork)