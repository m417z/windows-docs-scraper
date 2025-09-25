# IEventControl::SetDefaultQuery

## Description

Sets the default query to determine subscribers.

## Parameters

### `methodName` [in]

The name of the method to which the default query is assigned.

### `criteria` [in]

The query criteria. This parameter cannot be **NULL**. For details on forming a valid expression for this parameter, see the Remarks section below.

### `errorIndex` [out, retval]

The location, expressed as an offset, of an error in the *criteria* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The query criteria specified by the *criteria* parameter can be "ALL", to specify a request for all subscription objects, or a Boolean expression denoting one or more conditions a subscription object must meet to be included in the query result. Valid expressions are of the following form:

[NOT] *propertyname**relationalOperator**value*. Valid relational operators are as follows:

==, =, !=, <>, ~=. Valid values are "*string*", '*string*', {*GUID*}, **TRUE**, **FALSE**, **NULL**.

Individual Boolean expressions can be joined with AND or OR. Expressions can be nested in parentheses to enforce a specific order of evaluation.

Following are some examples of valid query criteria:

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF}"

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF} AND MethodName = 'StockPriceChange'"

## See also

[IEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ieventcontrol)