# IConditionFactory2::CreateStringLeaf

## Description

Creates a leaf condition node for a string value that represents a comparison of property value and constant value. The returned object supports [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) and [ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2).

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

The name of the property of the leaf condition as a REFPROPERTYKEY. If the leaf has no particular property, use PKEY_Null.

### `cop` [in]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)**

A [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) enumeration. If the leaf has no particular operation, then use *COP_IMPLICIT*.

### `pszValue` [in]

Type: **LPCWSTR**

The value to be compared, or **NULL** for an unspecified property. The locale name of the leaf node is LOCALE_NAME_USER_DEFAULT.

### `pszLocaleName` [in]

Type: **LPCWSTR**

The name of the locale of the lead condition, or **NULL** for a plain string. The locale name of the leaf node is LOCALE_NAME_USER_DEFAULT.

### `cco` [in]

Type: **[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)**

The condition creation operation of the leaf condition as the [CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options) enumeration.

### `riid` [in]

Type: **REFIID**

The desired IID of the enumerating interface: either [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown), IID_IEnumVARIANT, or (for a negation condition) IID_ICondition.

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