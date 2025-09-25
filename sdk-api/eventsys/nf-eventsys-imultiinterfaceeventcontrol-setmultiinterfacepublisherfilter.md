# IMultiInterfaceEventControl::SetMultiInterfacePublisherFilter

## Description

Assigns a publisher filter to an event method at run time.

This method sets the specified publisher filter for all methods of all event interfaces for the event object.

## Parameters

### `classFilter` [in]

A pointer to the [IMultiInterfacePublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfacepublisherfilter) interface on the publisher filter associated with the specified method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **EVENT_E_INTERNALEXCEPTION** | An unexpected exception was raised. |
| **EVENT_E_INTERNALERROR** | An unexpected internal error was detected. |

## Remarks

An event publisher can install a publisher filter at run time to fire an event only to subscribers that meet the criteria specified in the filter.

## See also

[IMultiInterfaceEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfaceeventcontrol)