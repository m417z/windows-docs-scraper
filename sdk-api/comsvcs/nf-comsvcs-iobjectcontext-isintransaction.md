# IObjectContext::IsInTransaction

## Description

Indicates whether the object is executing within a transaction.

## Return value

If the current object is executing within a transaction, the return value is **TRUE**. Otherwise, it is **FALSE**.

## Remarks

You can use this method to ensure that an object that requires a transaction never runs without one. For example, if a component that requires a transaction is improperly configured in the Component Services administration tool, you can use this method to determine that the object does not have a transaction. Then you can return an error to alert the user to the problem, or take whatever action is appropriate.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)