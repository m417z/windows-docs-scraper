# IMultiInterfacePublisherFilter::PrepareToFire

## Description

Prepares the publisher filter to begin firing a filtered list of subscriptions using a provided firing control. The firing control is contained in the event class object.

## Parameters

### `iid` [in]

The interface ID of the interface being fired.

### `methodName` [in]

The name of the event method to be fired.

### `firingControl` [in]

A pointer to the [IFiringControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ifiringcontrol) interface on the firing control object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Prior to invoking the application event interface method, the event object invokes this method one time on the publisher filter for each published event.

## See also

[IMultiInterfacePublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfacepublisherfilter)