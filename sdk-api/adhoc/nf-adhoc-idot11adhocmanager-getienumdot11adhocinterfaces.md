# IDot11AdHocManager::GetIEnumDot11AdHocInterfaces

## Description

Returns the set of wireless network interface cards (NICs) available on the machine.

## Parameters

### `ppEnum` [out]

A pointer to an [IEnumDot11AdHocInterfaces](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocinterfaces) interface that contains the list of NICs.

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