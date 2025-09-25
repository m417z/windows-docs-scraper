# CONDITION_CREATION_OPTIONS enumeration

## Description

Provides a set of flags to be used with the following interfaces to indicate the type of condition tree node: [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition),
[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2), [IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory), [IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2), and [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator).

## Constants

### `CONDITION_CREATION_DEFAULT:0`

Indicates that the condition is set to the default value.

### `CONDITION_CREATION_NONE:0`

Indicates that the condition is set to **NULL**.

### `CONDITION_CREATION_SIMPLIFY:0x1`

Indicates that you should simplify the returned condition as much as possible. In some cases this flag indicates that the returned condition is not newly created but refers to an existing object.

### `CONDITION_CREATION_VECTOR_AND:0x2`

Indicates that you should create an AND condition of leaves with vector elements as values, instead of attempting to create a leaf condition with VT_VECTOR set in the PROPVARIANT.

### `CONDITION_CREATION_VECTOR_OR:0x4`

Indicates that you should create an OR condition of leaves with vector elements as values, instead of attempting to create a leaf condition with VT_VECTOR set in the PROPVARIANT.

### `CONDITION_CREATION_VECTOR_LEAF:0x8`

Indicates that you should allow the creation of a leaf condition with VT_VECTOR set in the PROPVARIANT.

### `CONDITION_CREATION_USE_CONTENT_LOCALE:0x10`

Indicates that you should ignore any specified locale and use the currently selected content locale [IConditionFactory2::CreateStringLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createstringleaf) and [IConditionFactory2::CreateLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createleaf).

## Remarks

>Only one of following flags should be set simultaneously:

* CONDITION_CREATION_VECTOR_AND
* CONDITION_CREATION_VECTOR_OR
* CONDITION_CREATION_VECTOR_LEAF

However, if none of these flags is set, then attempting to create a leaf condition with VT_VECTOR set in the PROPVARIANT results in failure.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

**Reference**