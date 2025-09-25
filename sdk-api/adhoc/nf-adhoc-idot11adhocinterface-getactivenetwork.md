# IDot11AdHocInterface::GetActiveNetwork

## Description

Gets the network that is currently active on the interface.

## Parameters

### `ppNetwork` [out]

A pointer to an IDot11AdHocNetwork object that represents the active network.

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

[IDot11AdHocInterface::GetStatus](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocinterface-getstatus)