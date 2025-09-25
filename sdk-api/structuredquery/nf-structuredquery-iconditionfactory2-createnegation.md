# IConditionFactory2::CreateNegation

## Description

Creates a condition node that is a logical negation (NOT) of another condition (a subnode of this node).

## Parameters

### `pcSub` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

A pointer to the [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) subnode to be negated. For default options, use the *CONDITION_CREATION_DEFAULT* flag.

### `cco` [in]

Type: **[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)**

The condition creation operation of the leaf condition as the [CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options) enumeration.

### `riid` [in]

Type: **REFIID**

The desired IID of the enumerating interface: either [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown), [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant), or (for a negation condition) IID_ICondition.

### `ppv` [out]

Type: **void****

Receives a pointer to zero or more [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) and [ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2) objects.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Logically simplifying a condition node usually results in a smaller, more easily traversed and processed condition tree. For example, if *pcSub* is itself a negation condition with a subcondition C, then the double negation is logically resolved, and *ppcResult* is set to C. Without simplification, the resulting tree would look like NOT — NOT — C.

Applications that need to execute queries based on the condition tree would typically benefit from setting this parameter to **TRUE**.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**