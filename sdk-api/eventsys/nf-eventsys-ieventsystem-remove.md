# IEventSystem::Remove

## Description

Removes one or more subscription or event objects from the event data store.

## Parameters

### `progID` [in]

The ProgID of the object class to be removed. This must be a valid event object class identifier. This parameter can be one of the following values:

* PROGID_EventClass
* PROGID_EventClassCollection
* PROGID_EventSubscription
* PROGID_EventSubscriptionCollection

### `queryCriteria` [in]

The query criteria. For details on forming a valid expression for this parameter, see the Remarks section below.

### `errorIndex` [out]

The location, expressed as an offset, of an error in the *queryCriteria* parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **EVENT_E_QUERYSYNTAX** | A syntax error occurred while trying to evaluate a query string. |
| **EVENT_E_QUERYFIELD** | An invalid field name was used in a query string. |
| **EVENT_E_NOT_ALL_REMOVED** | Not all of the requested objects could be removed. |

## Remarks

The query criteria specified by the *queryCriteria* parameter can be "ALL", to specify a request for all subscription objects, or a Boolean expression denoting one or more conditions a subscription object must meet to be included in the query result. Valid expressions are of the following form:

[NOT] *propertyname**relationalOperator**value*. Valid relational operators are as follows:

==, =, !=, <>, ~=. Valid values are "*string*", '*string*', {*GUID*}, **TRUE**, **FALSE**, **NULL**.

Individual Boolean expressions can be joined with AND or OR. Expressions can be nested in parentheses to enforce a specific order of evaluation.

Following are some examples of valid query criteria:

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF}"

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF} AND MethodName = 'StockPriceChange'"

## See also

[IEventSystem](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventsystem)