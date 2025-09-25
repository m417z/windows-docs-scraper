# CONDITION_TYPE enumeration

## Description

Provides a set of flags to be used with the following methods to indicate the type of condition tree node:
[ICondition::GetConditionType](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getconditiontype),
[IConditionFactory::MakeAndOr](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-makeandor),
[IConditionFactory2::CreateCompoundFromArray](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createcompoundfromarray), and
[IConditionFactory2::CreateCompoundFromObjectArray](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory2-createcompoundfromobjectarray).

## Constants

### `CT_AND_CONDITION:0`

Indicates that the values of the subterms are combined by "AND".

### `CT_OR_CONDITION`

Indicates that the values of the subterms are combined by "OR".

### `CT_NOT_CONDITION`

Indicates a "NOT" comparison of subterms.

### `CT_LEAF_CONDITION`

Indicates that the node is a comparison between a property and a constant value using a [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation).

## Remarks

In Windows 7, this enumeration is defined in structuredquerycondition.idl and structuredquerycondition.h. Prior to Windows 7 this enumeration was declared in structuredquery.h and structuredquery.idl.

The [StructuredQuerySample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winui/WindowsSearch/StructuredQuerySample) demonstrates how to read lines from the console, parse them using the system schema, and display the resulting condition trees.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

[IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator)

**Reference**