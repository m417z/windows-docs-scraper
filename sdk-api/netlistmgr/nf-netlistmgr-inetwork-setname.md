# INetwork::SetName

## Description

The **SetName** method sets or renames a network.

## Parameters

### `szNetworkNewName` [in]

Zero-terminated string that contains the new name of the network.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *szNetworkNewName* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)** | The name provided is too long. |

## Remarks

The maximum length of a network name can be 128 characters and cannot contain spaces only, tab or "\ /: * ? " < > |".

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)