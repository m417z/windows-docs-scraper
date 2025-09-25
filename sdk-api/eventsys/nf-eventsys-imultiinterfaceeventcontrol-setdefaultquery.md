# IMultiInterfaceEventControl::SetDefaultQuery

## Description

Establishes a default query to be used when a publisher filter is not associated with an event method.

## Parameters

### `eventIID` [in]

The interface identifier of the firing interface.

### `bstrMethodName` [in]

The name of the method to which the default query is assigned.

### `bstrCriteria` [in]

A string specifying the query criteria. This parameter cannot be **NULL**. For details on forming a valid expression for this parameter, see the Remarks section below.

### `errorIndex` [out, retval]

The location, expressed as an offset, of an error in the *bstrCriteria* parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **EVENT_E_QUERYSYNTAX** | A syntax error occurred while trying to evaluate a query string. |
| **EVENT_E_QUERYFIELD** | An invalid field name was used in a query string. |
| **EVENT_E_INTERNALEXCEPTION** | An unexpected exception was raised. |
| **EVENT_E_INTERNALERROR** | An unexpected internal error was detected. |

## Remarks

This method is a more specialized form of the [IEventSystem::Query](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-ieventsystem-query) method. In addition to obtaining only subscription objects, a collection obtained by calling [GetSubscriptions](https://learn.microsoft.com/windows/desktop/api/eventsys/nf-eventsys-imultiinterfaceeventcontrol-getsubscriptions) is automatically updated whenever the subscription collection changes.

The query criteria specified by the *bstrCriteria* parameter can be "ALL", to specify a request for all subscription objects, or a Boolean expression denoting one or more conditions a subscription object must meet to be included in the query result. Valid expressions are of the following form:

[NOT] *propertyname**relationalOperator**value*. Valid relational operators are as follows:

==, =, !=, <>, ~=. Valid values are "*string*", '*string*', {*GUID*}, **TRUE**, **FALSE**, **NULL**.

Individual Boolean expressions can be joined with AND or OR. Expressions can be nested in parentheses to enforce a specific order of evaluation.

Following are some examples of valid query criteria:

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF}"

"EventClassID == {F89859D1-6565-11D1-88C8-0080C7D771BF} AND MethodName = 'StockPriceChange'"

## See also

[IMultiInterfaceEventControl](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-imultiinterfaceeventcontrol)