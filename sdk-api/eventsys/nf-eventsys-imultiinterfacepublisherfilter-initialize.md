# IMultiInterfacePublisherFilter::Initialize

## Description

Associates an event class with a publisher filter.

## Parameters

### `pEIC` [in]

A pointer to the [IMultiInterfaceEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfaceeventcontrol) interface on an event class object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The publisher filter uses the pointer passed in *pIEC* to obtain a list of subscribers, by calling [IMultiInterfaceEventControl::GetSubscriptions](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-imultiinterfaceeventcontrol-getsubscriptions).

## See also

[IMultiInterfacePublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfacepublisherfilter)