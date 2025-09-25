# IConditionFactory2::ResolveCondition

## Description

Performs a variety of transformations on a condition tree, and thereby the resolved condition for evaluation. The returned object supports [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) and [ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2).

## Parameters

### `pc` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

Pointer to an [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) object to be resolved.

### `sqro` [in]

Type: **[STRUCTURED_QUERY_RESOLVE_OPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_resolve_option)**

Specifies zero or more of the [STRUCTURED_QUERY_RESOLVE_OPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_resolve_option) flags. The *SQRO_NULL_VALUE_TYPE_FOR_PLAIN_VALUES* flag is automatically added to *sqro*.

### `pstReferenceTime` [in, optional]

Type: **SYSTEMTIME const***

Pointer to a **SYSTEMTIME** value to use as the reference date and time. A null pointer can be passed if *sqro* is set to the *SQRO_DONT_RESOLVE_DATETIME* flag.

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

The [StructuredQuerySample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winui/WindowsSearch/StructuredQuerySample) demonstrates how to read lines from the console, parse them using the system schema, and display the resulting condition trees.

Refer to the [Resolve](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-resolve) method for additional detail.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**