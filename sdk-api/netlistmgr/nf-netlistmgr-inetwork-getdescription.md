# INetwork::GetDescription

## Description

The **GetDescription** method returns a description string for the network.

## Parameters

### `pszDescription` [out]

Pointer to a string that specifies the text description of the network. This value must be freed using the SysFreeString API.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The pointer passed is **NULL**. |

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)