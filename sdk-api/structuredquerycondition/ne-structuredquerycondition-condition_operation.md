# CONDITION_OPERATION enumeration

## Description

Provides a set of flags to be used with following methods to indicate the operation in
[ICondition::GetComparisonInfo](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getcomparisoninfo),
[ICondition2::GetLeafConditionInfo](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition2-getleafconditioninfo),
[IConditionFactory::MakeLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-makeleaf),
[IConditionFactory2::CreateBooleanLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createbooleanleaf),
[IConditionFactory2::CreateIntegerLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createintegerleaf),
[IConditionFactory2::MakeLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createleaf),
[IConditionFactory2::CreateStringLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createstringleaf), and
[IConditionGenerator::GenerateForLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditiongenerator-generateforleaf).

## Constants

### `COP_IMPLICIT:0`

An implicit comparison between the value of the property and the value of the constant. For an unresolved condition, [COP_IMPLICIT](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) means that a user did not type an operation. In contrast, a resolved condition will always have a condition other than the **COP_IMPLICIT** operation.

### `COP_EQUAL`

The value of the property and the value of the constant must be equal.

### `COP_NOTEQUAL`

The value of the property and the value of the constant must not be equal.

### `COP_LESSTHAN`

The value of the property must be less than the value of the constant.

### `COP_GREATERTHAN`

The value of the property must be greater than the value of the constant.

### `COP_LESSTHANOREQUAL`

The value of the property must be less than or equal to the value of the constant.

### `COP_GREATERTHANOREQUAL`

The value of the property must be greater than or equal to the value of the constant.

### `COP_VALUE_STARTSWITH`

The value of the property must begin with the value of the constant.

### `COP_VALUE_ENDSWITH`

The value of the property must end with the value of the constant.

### `COP_VALUE_CONTAINS`

The value of the property must contain the value of the constant.

### `COP_VALUE_NOTCONTAINS`

The value of the property must not contain the value of the constant.

### `COP_DOSWILDCARDS`

The value of the property must match the value of the constant, where '?' matches any single character and '*' matches any sequence of characters.

### `COP_WORD_EQUAL`

The value of the property must contain a word that is the value of the constant.

### `COP_WORD_STARTSWITH`

The value of the property must contain a word that begins with the value of the constant.

### `COP_APPLICATION_SPECIFIC`

The application is free to interpret this in any suitable way.

## Remarks

Because a resolved condition never has a **COP_IMPLICIT** operation, applications that evaluate condition trees should not encounter it. However, **COP_IMPLICIT** could be used in comparing the output of either [ICondition::GetComparisonInfo](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getcomparisoninfo) or [ICondition2::GetLeafConditionInfo](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition2-getleafconditioninfo) for a parsed unresolved condition to the output for a resolved condition.

In Windows 7, this enumeration is defined in structuredquerycondition.idl and structuredquerycondition.h. Prior to Windows 7 this enumeration was declared in structuredquery.h and structuredquery.idl.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

[IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator)

**Reference**