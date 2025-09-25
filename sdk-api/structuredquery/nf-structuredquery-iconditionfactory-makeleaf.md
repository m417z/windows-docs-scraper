# IConditionFactory::MakeLeaf

## Description

Creates a leaf condition node that represents a comparison of property value and constant value.

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

The name of a property to be compared, or **NULL** for an unspecified property. The locale name of the leaf node is LOCALE_NAME_USER_DEFAULT.

### `cop` [in]

Type: **[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)**

A [CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) enumeration.

### `pszValueType` [in]

Type: **LPCWSTR**

The name of a semantic type of the value, or **NULL** for a plain string.

### `ppropvar` [in]

Type: **PROPVARIANT const***

The constant value against which the property value should be compared.

### `pPropertyNameTerm` [in]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the property. It can be **NULL**.

### `pOperationTerm` [in]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the operation. It can be **NULL**.

### `pValueTerm` [in]

Type: **[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)***

A pointer to an [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) that identifies the range of the input string that represents the value. It can be **NULL**.

### `fExpand` [in]

Type: **BOOL**

If **TRUE** and *pszPropertyName* identifies a virtual property, the resulting node is not a leaf node; instead, it is a disjunction of leaf condition nodes, each of which corresponds to one expansion of the virtual property.

### `ppcResult` [out, retval]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)****

Receives a pointer to the new [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) leaf node.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about leaf node terms (property, value, and operation), see
[ICondition::GetInputTerms](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-getinputterms).

A virtual property has one or more metadata items in which the key is "MapsToRelation" and the value is a property name (which is one expansion of the property). For more information about metadata, see [MetaData](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-irelationship-metadata).

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**