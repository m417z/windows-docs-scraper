# IConditionFactory::MakeAndOr

## Description

Creates a condition node that is a logical conjunction (AND) or disjunction (OR) of a collection of subconditions.

## Parameters

### `ct` [in]

Type: **[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)**

The [CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type) of the condition node. The **CONDITION_TYPE** must be either **CT_AND_CONDITION** or **CT_OR_CONDITION**.

### `peuSubs` [in]

Type: **[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)***

A pointer to an enumeration of [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) objects, or **NULL** for an empty enumeration.

### `fSimplify` [in]

Type: **BOOL**

**TRUE** to logically simplify the result, if possible; then the result will not necessarily to be of the specified kind. **FALSE** if the result should have exactly the prescribed structure.

An application that plans to execute a query based on the condition tree would typically benefit from setting this parameter to **TRUE**.

### `ppcResult` [out, retval]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)****

Receives the address of a pointer to the new [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) node.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There are no special condition trees for **TRUE** and **FALSE**. However, a condition tree consisting of an AND node with no subconditions is always **TRUE**, and a condition tree consisting of an OR node with no subconditions is always **FALSE**.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**