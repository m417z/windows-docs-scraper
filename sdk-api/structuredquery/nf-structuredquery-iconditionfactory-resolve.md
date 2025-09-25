# IConditionFactory::Resolve

## Description

Performs a variety of transformations on a condition tree, including the following: resolves conditions with relative date/time expressions to conditions with absolute date/time (as a VT_FILETIME); turns other recognized named entities into condition trees with actual values; simplifies condition trees; replaces virtual or compound properties with OR trees of other properties; removes condition trees resulting from queries with property keywords that had no condition applied.

## Parameters

### `pc` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

A pointer to an [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) object to be resolved.

### `sqro` [in]

Type: **[STRUCTURED_QUERY_RESOLVE_OPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_resolve_option)**

Specifies zero or more of the [STRUCTURED_QUERY_RESOLVE_OPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_resolve_option) flags. For **Windows 7 and later**, the SQRO_ADD_VALUE_TYPE_FOR_PLAIN_VALUES flag is automatically added to *sqro*.

### `pstReferenceTime` [in]

Type: **SYSTEMTIME const***

A pointer to a **SYSTEMTIME** value to use as the reference date and time. A null pointer can be passed if *sqro* is set to SQRO_DONT_RESOLVE_DATETIME.

### `ppcResolved` [out, retval]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)****

Receives a pointer to the new [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) in which all time fields have been resolved to have values of type VT_FILETIME. This new condition tree is the resolved version of *pc*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In a condition tree produced by the [Parse](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-parse) method and returned by [GetQuery](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iquerysolution-getquery), the leaves pair up properties with restrictions on these properties, and result in a condition tree that is partially finished. The **IConditionFactory::Resolve** method finishes such a condition tree by a process known as resolution. The input condition tree is not modified in any way. The output condition tree may share parts of the input condition that contained no leaf nodes with unresolved date/time values.

**Note** Resolving a leaf node often produces a non-leaf node.

For example, Structured Query supports relative date/time expressions, which remain unresolved until they are applied to some reference time. In a leaf node with semantic type **System.StructuredQueryType.DateTime**, the value can be either a VT_FILETIME or a VT_LPWSTR. VT_FILETIME is an absolute date/time so it is already resolved. VT_LPWSTR is a string representation of a relative date/time expression. The specified reference time should be a local time, but the resolved times in the resulting query expression will be in Coordinated Universal Time (UTC).

The [StructuredQuerySample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winui/WindowsSearch/StructuredQuerySample) demonstrates how to read lines from the console, parse them using the system schema, and display the resulting condition trees.

## See also

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionFactory2](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory2)

**Reference**