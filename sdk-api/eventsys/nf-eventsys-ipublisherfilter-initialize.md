# IPublisherFilter::Initialize

## Description

Associates an event method with a collection of subscription objects.

This method is supported only for backward compatibility. Otherwise, you should use the methods of the [IMultiInterfacePublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfacepublisherfilter) interface.

## Parameters

### `methodName` [in]

The name of the event method associated with the publisher filter.

### `dispUserDefined` [in]

A pointer to the [IEventSystem](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsystem) interface on an event system object or to the [IEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventcontrol) interface on an event class object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The publisher filter was successfully initialized. |
| **EVENT_S_SOME_SUBSCRIBERS_FAILED** | An event was able to invoke some, but not all, of the subscribers. |
| **EVENT_E_ALL_SUBSCRIBERS_FAILED** | An event was unable to invoke any of the subscribers. |
| **EVENT_S_NOSUBSCRIBERS** | An event was published but there were no subscribers. |
| **EVENT_E_QUERYSYNTAX** | A syntax error occurred while trying to evaluate a query string. |
| **EVENT_E_QUERYFIELD** | An invalid field name was used in a query string. |
| **EVENT_E_INTERNALEXCEPTION** | An unexpected exception was raised. |
| **EVENT_E_INTERNALERROR** | An unexpected internal error was detected. |
| **EVENT_E_INVALID_PER_USER_SID** | The owner SID on a per-user subscription does not exist. |
| **EVENT_E_USER_EXCEPTION** | A user-supplied component or subscriber raised an exception. |
| **EVENT_E_TOO_MANY_METHODS** | An interface has too many methods from which to fire events. |
| **EVENT_E_MISSING_EVENTCLASS** | A subscription cannot be stored unless the event class for the subscription already exists. |
| **EVENT_E_NOT_ALL_REMOVED** | Not all of the requested objects could be removed. |
| **EVENT_E_COMPLUS_NOT_INSTALLED** | COM+ is required for this operation, but it is not installed. |

## Remarks

The publisher filter uses the pointer passed in dispUserDefined to obtain a list of subscribers, either by calling [IEventSystem::Query](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsystem-query) or [IEventControl::GetSubscriptions](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventcontrol-getsubscriptions).

## See also

[IMultiInterfacePublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfacepublisherfilter)

[IPublisherFilter](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ipublisherfilter)