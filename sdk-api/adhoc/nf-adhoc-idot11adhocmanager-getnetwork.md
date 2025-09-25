# IDot11AdHocManager::GetNetwork

## Description

Returns the network associated with a signature.

## Parameters

### `NetworkSignature` [in]

A signature that uniquely identifies an ad hoc network. This signature is generated from certain network attributes.

### `pNetwork` [out]

A pointer to an [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) interface that represents the network associated with the signature.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |

## See also

[IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager)