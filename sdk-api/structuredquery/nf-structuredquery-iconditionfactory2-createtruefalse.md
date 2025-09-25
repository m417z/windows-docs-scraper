# IConditionFactory2::CreateTrueFalse

## Description

Creates a search condition that is either **TRUE** or **FALSE**. The returned object supports [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) and [ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

## Parameters

### `fVal` [in]

Type: **BOOL**

The value of the search condition to use. *fValue* should typically be set to VARIANT_FALSE.

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

For default options, use the *CONDITION_CREATION_DEFAULT* flag.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**