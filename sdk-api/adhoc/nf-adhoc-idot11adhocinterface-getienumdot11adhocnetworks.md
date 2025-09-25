# IDot11AdHocInterface::GetIEnumDot11AdHocNetworks

## Description

Gets the collection of networks associated with this NIC.

## Parameters

### `pFilterGuid` [in]

An optional parameter that specifies the GUID of the application that created the network. An application can use this identifier to limit the networks enumerated to networks created by the application. For this filtering to work correctly, all instances of the application on all machines must use the same GUID.

### `ppEnum` [out]

A pointer to a [IEnumDot11AdHocNetworks](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocnetworks) interface that contains the enumerated networks.

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