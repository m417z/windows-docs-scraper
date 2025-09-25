## Description

Describes a filter expression used to query filter results.

## Members

### `Operator`

A [DEVPROP_OPERATOR](https://learn.microsoft.com/windows/win32/api/devfiltertypes/ne-devfiltertypes-devprop_operator) value describing the operator for this filter expression element.

### `Property`

The [DEVPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty) structure that should be associated with the filter operation described by the *Operator* member

## Remarks

**DEVPROP_FILTER_EXPRESSION** structures can be combined in an array to create a complex filter expression for use in query creation, such as through the [DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery) function.

The following example demonstrates the initialization of a **DEVPROP_FILTER_EXPRESSION**.

```cpp
ULONG targetValue = 5;
DEVPROP_BOOLEAN devpropTrue = DEVPROP_TRUE;
const DEVPROP_FILTER_EXPRESSION filter[] = {
    {DEVPROP_OPERATOR_OR_OPEN, {0}},
        {DEVPROP_OPERATOR_EQUALS, {{DEVPKEY_Property1, DEVPROP_STORE_SYSTEM, NULL}, DEVPROP_TYPE_UINT32, (ULONG)(sizeof(targetValue)), (PVOID)&targetValue}},
        {DEVPROP_OPERATOR_EQUALS, {{DEVPKEY_Property2, DEVPROP_STORE_SYSTEM, NULL}, DEVPROP_TYPE_BOOLEAN, (ULONG)(sizeof(devpropTrue)), (PVOID)&devpropTrue}},
    {DEVPROP_OPERATOR_OR_CLOSE, {0}}
};

```

If the above filter expression was used in a query, the query’s result set would consist of all objects of the appropriate type that have a *DEVPKEY_Property1* property equal to 5 OR that have a *DEVPKEY_Property2* property equal to **DEVPROP_TRUE**.

If a filter expression does not contain any logical operators specifying how to combine different comparison clauses, then the filter expression assumes that a logical AND should be performed.

## See also