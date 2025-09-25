# IDot11AdHocNetwork::HasProfile

## Description

Returns a boolean value that specifies whether there is a saved profile associated with the network.

## Parameters

### `pf11d` [in, out]

Specifies whether the network has a profile. This value is set to **TRUE** if the network has a profile and **FALSE** otherwise.

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

[IDot11AdHocNetwork::GetProfileName](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocnetwork-getprofilename)