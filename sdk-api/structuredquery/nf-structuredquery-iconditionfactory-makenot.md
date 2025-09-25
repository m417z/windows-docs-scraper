# IConditionFactory::MakeNot

## Description

Creates a condition node that is a logical negation (NOT) of another condition (a subnode of this node).

## Parameters

### `pcSub` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

Pointer to the [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) subnode to be negated.

### `fSimplify` [in]

Type: **BOOL**

**TRUE** to logically simplify the result if possible; **FALSE** otherwise. In a query builder scenario, *fSimplify* should typically be set to VARIANT_FALSE.

### `ppcResult` [out, retval]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)****

Receives a pointer to the new [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) node.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Logically simplifying a condition node usually results in a smaller, more easily traversed and processed condition tree. For example, if *pcSub* is itself a negation condition with a subcondition C, then the double negation is logically resolved, and *ppcResult* is set to C. Without simplification, the resulting tree would look like NOT — NOT — C.

Applications that need to execute queries based on the condition tree would typically benefit from setting this parameter to **TRUE**.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**