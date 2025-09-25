# IDot11AdHocNetwork::GetContextGuid

## Description

Gets the context identifier associated with the network. This GUID identifies the application that created the network.

## Parameters

### `pContextGuid` [in, out]

The context identifier associated with the network. If no ContextGuid was specified when the [CreateNetwork](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocmanager-createnetwork) call was made, the GUID returned consists of all zeros.

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