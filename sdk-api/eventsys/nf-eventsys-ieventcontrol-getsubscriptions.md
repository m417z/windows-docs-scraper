# IEventControl::GetSubscriptions

## Description

Retrieves the collection of subscriptions associated with an event method.

## Parameters

### `methodName` [in]

The event method associated with the subscription collection.

### `optionalCriteria` [in]

The query criteria. If this parameter is **NULL**, the default query specified by the [SetDefaultQuery](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventcontrol-setdefaultquery) method is used. For details on forming a valid expression for this parameter, see the Remarks section below.

### `optionalErrorIndex` [in]

The location, expressed as an offset, of an error in the *OptionalCriteria* parameter. This parameter cannot be **NULL**.

### `ppCollection` [out, retval]

Address of a pointer to [IEventObjectCollection](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventobjectcollection) interface on a collection object that enumerates the subscriptions associated with the event object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is a more specialized form of the [IEventSystem::Query](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsystem-query) method. In addition to obtaining only subscription objects, a collection obtained by calling **GetSubscriptions** is automatically updated whenever the subscription collection changes.

The query criteria specified by the *optionalCriteria* parameter can be "ALL", to specify a request for all subscription objects, or a Boolean expression denoting one or more conditions a subscription object must meet to be included in the query result. Valid expressions are of the following form:

[NOT] *propertyname**relationalOperator**value*. Valid relational operators are as follows:

==, =, !=, <>, ~=. Valid values are "*string*", '*string*', {*GUID*}, **TRUE**, **FALSE**, **NULL**.

Individual Boolean expressions can be joined with AND or OR. Expressions can be nested in parentheses to enforce a specific order of evaluation.

Following are some examples of valid query criteria:

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF}"

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF} AND MethodName = 'StockPriceChange'"

## See also

[IEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventcontrol)