# IEventSystem::QueryS

## Description

Retrieves a collection of subscription or event objects from the event data store.

## Parameters

### `progID` [in]

The ProgID of the object class to be queried. This must be a valid event object class identifier. This parameter can be one of the following values:

* PROGID_EventClass
* PROGID_EventClassCollection
* PROGID_EventSubscription
* PROGID_EventSubscriptionCollection

### `queryCriteria` [in]

The query criteria. For details on forming a valid expression for this parameter, see the Remarks section below.

### `ppInterface` [out, retval]

Address of a pointer to the object obtained as a result of the query. This parameter cannot be **NULL**. Depending on the object specified by the *progID* parameter, this is a pointer to one of the following interfaces:

* [IEventClass](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventclass)
* [IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection)
* [IEventSubscription](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsubscription)

## Return value

This method can return the standard return values E_INVALIDARG, E_POINTER, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **EVENT_E_QUERYSYNTAX** | A syntax error occurred while trying to evaluate a query string. |
| **EVENT_E_QUERYFIELD** | An invalid field name was used in a query string. |

## Remarks

The caller is responsible for freeing memory allocated through the *ppInterface* parameter.

The query criteria specified by the *queryCriteria* parameter can be "ALL", to specify a request for all subscription objects, or a Boolean expression denoting one or more conditions a subscription object must meet to be included in the query result. Valid expressions are of the following form:

[NOT] *propertyname**relationalOperator**value*. Valid relational operators are as follows:

==, =, !=, <>, ~=. Valid values are "*string*", '*string*', {*GUID*}, **TRUE**, **FALSE**, **NULL**.

Individual Boolean expressions can be joined with AND or OR. Expressions can be nested in parentheses to enforce a specific order of evaluation.

Following are some examples of valid query criteria:

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF}"

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF} AND MethodName = 'StockPriceChange'"

## See also

[IEventSystem](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsystem)