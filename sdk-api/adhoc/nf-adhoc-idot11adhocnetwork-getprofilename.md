# IDot11AdHocNetwork::GetProfileName

## Description

Gets the profile name associated with the network.

## Parameters

### `ppszwProfileName` [out]

The name of the profile associated with the network. If the network has no profile, this parameter is **NULL**.

You must free this string using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

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

[IDot11AdHocNetwork::DeleteProfile](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-deleteprofile)

[IDot11AdHocNetwork::HasProfile](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-hasprofile)