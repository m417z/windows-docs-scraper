# IDot11AdHocManager::GetIEnumDot11AdHocNetworks

## Description

Returns a list of available ad hoc network destinations within connection range. This list may be filtered.

## Parameters

### `pContextGuid` [in]

An optional parameter that specifies the GUID of the application that created the network. An application can use this identifier to limit the networks enumerated to networks created by the application. For this filtering to work correctly, all instances of the application on all machines must use the same GUID.

### `ppEnum` [out]

A pointer to an [IEnumDot11AdHocNetworks](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocnetworks) interface that contains the enumerated networks.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## See also

[IDot11AdHocManager](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocmanager)