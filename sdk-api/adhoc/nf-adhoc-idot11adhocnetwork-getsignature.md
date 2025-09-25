# IDot11AdHocNetwork::GetSignature

## Description

Gets the unique signature associated with the ad hoc network. The signature uniquely identifies an [IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork) object with a particular set of attributes.

## Parameters

### `pSignature` [in, out]

A signature that uniquely identifies an ad hoc network. This signature is generated from certain network attributes.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## Remarks

Do not cache the returned signature locally. Whenever a network object changes, its signature changes. Actions that are not associated with notifications, such as saving the network's profile, can cause the signature to change.

## See also

[IDot11AdHocNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocnetwork)