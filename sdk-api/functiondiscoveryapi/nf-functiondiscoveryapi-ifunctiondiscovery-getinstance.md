# IFunctionDiscovery::GetInstance

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the specified function instance, based on identifier.

## Parameters

### `pszFunctionInstanceIdentity` [in]

The identifier of the function instance (see [GetID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getid)).

### `ppIFunctionInstance` [out]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer used to return the interface.

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *pszFunctionInstanceIdentity* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **HRESULT_FROM_WIN32(ERROR_OBJECT_NOT_FOUND)**<br><br>0x800710d8 | The function instance represented by the specified ID does not exist on this computer. |
| **E_PENDING** | The call was executed for a provider that returns results asynchronously. |

## Remarks

Some function discovery providers return their query results with the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface. **GetInstance** does not find function instances that are returned in this way and will fail with E_PENDING. It is recommended that clients use the [CreateInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancequery) method of the [IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery) interface to find function instances for such providers.

## See also

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)