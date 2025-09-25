# IServiceGroup::RemoveMember

## Description

The `RemoveMember` method removes the specified member from the service group.

## Parameters

### `pServiceSink` [in]

Pointer to the [IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink) interface of the member that is to be removed

## Remarks

The `RemoveMember` method removes a service sink that was previously added to the service group by an **AddMember** call. The **AddMember** method called **AddRef** on the service sink object, and the `RemoveMember` method calls **Release** on the service sink object. This behavior is in accordance with the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)

[IServiceSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicesink)