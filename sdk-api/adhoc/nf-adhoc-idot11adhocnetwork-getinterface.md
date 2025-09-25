# IDot11AdHocNetwork::GetInterface

## Description

Gets the interface associated with a network.

## Parameters

### `pAdHocInterface` [out]

A pointer to an [IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface).

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

[IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork)