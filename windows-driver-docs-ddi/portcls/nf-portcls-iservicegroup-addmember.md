# IServiceGroup::AddMember

## Description

The `AddMember` method adds a member to the service group.

## Parameters

### `pServiceSink` [in]

Pointer to the [IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink) interface of the new member of the service group

## Return value

`AddMember` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `AddMember` method calls **AddRef** on the *pServiceSink* object. When the object is later removed, the **RemoveMember** method calls **Release** on the *pServiceSink* object. This behavior is in accordance with the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink)