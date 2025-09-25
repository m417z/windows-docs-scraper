# IConditionGenerator::DefaultPhrase

## Description

This method attempts to produce a phrase that, when recognized by this instance of [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator), represents the type and value pair for an entity, relationship, or named entity.

## Parameters

### `pszValueType` [in]

Type: **LPCWSTR**

The semantic type of the value in *ppropvar*.

### `ppropvar` [in]

Type: **[PROPVARIANT const](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

The value to be processed.

### `fUseEnglish` [in]

Type: **BOOL**

 The parameter fUseEnglish is reserved: it should be ignored by implementors, and callers should pass **FALSE**.

### `ppszPhrase` [out, retval, optional]

Type: **LPWSTR***

Receives a pointer to the phrase representing the value. If no phrase can be produced, this parameter is set to **NULL** and the method returns S_FALSE.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if the input arguments are valid but no phrase can be produced, and an error value otherwise.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator)

**Reference**