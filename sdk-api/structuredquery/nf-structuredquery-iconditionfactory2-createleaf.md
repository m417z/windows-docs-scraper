# IConditionFactory2::CreateLeaf

## Description

Creates a leaf condition node for any value. The returned object supports [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) and [ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2).

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

The name of the property of the leaf condition as a REFPROPERTYKEY. If the leaf has no particular property, use PKEY_Null.

### `cop` [in]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)**

A [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) enumeration. If the leaf has no particular operation, then use *COP_IMPLICIT*.

### `propvar` [in]

Type: **REFPROPERTYKEY**

The property value of the leaf condition as a REFPROPERTYKEY.

### `pszSemanticType` [in, optional]

Type: **LPCWSTR**

The name of a semantic type of the value, or **NULL** for a plain string. If the newly created leaf is an unresolved named entity, *pszSemanticType* should be the name of a semantic type, otherwise **NULL**.

### `pszLocaleName` [in, optional]

Type: **LPCWSTR**

The name of the locale to be compared, or **NULL** for an unspecified locale. If *propvar* does not contain a string value, then *pszLocaleName* should be LOCALE_NAME_USER_DEFAULT; otherwise, *pszLocaleName* should reflect the language the string. Alternatively, *pszLocaleName* could be LOCALE_NAME_INVARIANT.

### `pPropertyNameTerm` [in, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the property. It can be **NULL**.

### `pOperationTerm` [in, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the operation. It can be **NULL**.

### `pValueTerm` [in, optional]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the value. It can be **NULL**.

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

This method does not return a value.

## Remarks

For default options, use the *CONDITION_CREATION_DEFAULT* flag.

 If the leaf condition was obtained by parsing a string, one or more of the parameters *pPropertyNameTerm*, *pOperationTerm*  and *pValueTerm* may be represented by an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) interface (obtained through the [ICondition::GetInputTerms](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getinputterms) method). Otherwise all three parameters can be **NULL**.

For more information about leaf node terms (property, value, and operation), see
[ICondition::GetInputTerms](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getinputterms).

A virtual property has one or more metadata items in which the key is "MapsToRelation" and the value is a property name (which is one expansion of the property). For more information about metadata, see [MetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-irelationship-metadata).

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**