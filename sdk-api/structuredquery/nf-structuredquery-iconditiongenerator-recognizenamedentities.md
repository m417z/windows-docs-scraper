# IConditionGenerator::RecognizeNamedEntities

## Description

Identifies named entities in an input string, and creates a collection containing them. The value of each named entity is expressed as a string, which is then used by [IConditionGenerator::GenerateForLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditiongenerator-generateforleaf). The string can contain any data and be in any format, because it is not examined by any other components.

## Parameters

### `pszInputString` [in]

Type: **LPCWSTR**

The input string to be parsed.

### `lcidUserLocale` [in]

Type: **LCID**

The LCID against which named entities should be recognized.

### `pTokenCollection` [in]

Type: **[ITokenCollection](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-itokencollection)***

A pointer to an [ITokenCollection](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-itokencollection) object that indicates how the input string was tokenized.

### `pNamedEntities` [in, out]

Type: **[INamedEntityCollector](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentitycollector)***

On input, contains an [INamedEntityCollector](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentitycollector) or **NULL**. On return, contains an **INamedEntityCollector** collection of the named entities.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Given an input string, a user locale (typically the user's default locale) and a tokenization of the input string, the **IConditionGenerator::RecognizeNamedEntities** method should be able to identify any named entities in that input string, and then add each entity to the named entity collection.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator)

**Reference**