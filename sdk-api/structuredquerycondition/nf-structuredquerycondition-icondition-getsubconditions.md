# ICondition::GetSubConditions

## Description

Retrieves a collection of the subconditions of the search condition node and the IID of the interface for enumerating the collection.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the enumerating interface: either IID_IEnumUnknown, IID_IEnumVARIANT or (for a negation condition) IID_ICondition.

### `ppv` [out, retval]

Type: **void****

Receives a collection of zero or more [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) objects. Each object is a subcondition of this condition node. If *riid* was IID_ICondition and this is a negation condition, this parameter receives the single subcondition.

## Return value

Type: **HRESULT**

Returns S_OK if successful, E_FAIL if this is a leaf node, or an error value otherwise.

## Remarks

The *riid* parameter must be the **GUID** of an [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) or [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface or in the case of a negation node, IID_ICondition.

If the subcondition is a negation node, *ppv* is set to an enumeration of one element.

If the node is a conjunction or disjunction node, *ppv* is set to an enumeration of the subconditions.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

**Reference**