# INetwork::SetDescription

## Description

The **SetDescription** method sets or replaces the description for a network.

## Parameters

### `szDescription` [in]

Zero-terminated string that contains the description of the network.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *szDescription* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)** | The given name is too long. |

## Remarks

The maximum length for a network description is 1024 characters.

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)