# IEventControl::SetPublisherFilter

## Description

Assigns a publisher filter to an event method.

## Parameters

### `methodName` [in]

The name of the event method associated with the publisher filter to be assigned.

### `pPublisherFilter` [in]

A pointer to the [IPublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ipublisherfilter) interface on the publisher filter associated with the specified method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An event publisher can install a publisher filter at run time to fire an event only to subscribers that meet the criteria specified in the filter.

## See also

[IEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventcontrol)