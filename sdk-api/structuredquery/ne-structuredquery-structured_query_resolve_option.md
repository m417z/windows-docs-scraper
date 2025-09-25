# STRUCTURED_QUERY_RESOLVE_OPTION enumeration

## Description

Options for resolving data into a condition tree.

## Constants

### `SQRO_DEFAULT:0`

**Windows 7 and later.** The default flag.

### `SQRO_DONT_RESOLVE_DATETIME:0x1`

Unless this flag is set, any relative date/time expression in *pConditionTree* is replaced with an absolute date/time range that has been resolved against the reference date/time pointed to by *pstReferenceTime*. For example, if an AQS query contained the relative date/time expression "date:this month" and the reference date/time was 9/19/2006 10:28:33, the resolved condition tree would contain a date/time range beginning at 9/1/2006 00:00:00 and ending at 10/1/2006 00:00:00 (in the UTC time zone).

### `SQRO_ALWAYS_ONE_INTERVAL:0x2`

Unless this flag is set, resolving a relative date/time expression may result in an **OR** of several intervals. For example, if an AQS query contained "date:Monday" and the reference date/time was 9/19/2006 10:28:33 (a Tuesday), the resolved condition tree would contain an **OR** of three 24 hour ranges corresponding to the Mondays of 9/11/2006, 9/18/2006 and 9/25/2006, because it is not clear which Monday was referenced. If this flag is set, the result will always be a single date/time range (for this example, it would be a date/time range beginning at 9/18/2006 00:00:00 and ending at 9/19/2006 00:00:00).

### `SQRO_DONT_SIMPLIFY_CONDITION_TREES:0x4`

Unless this flag is set, the resulting condition tree will have any possible simplifications applied to it.

### `SQRO_DONT_MAP_RELATIONS:0x8`

Unless this flag is true, a leaf node with a virtual property that maps to several properties will be replaced by an **OR** of leaf nodes containing the actual properties. For example, the AQS query "to:Bill" may result in a leaf node where the property named `System.StructuredQuery.Virtual.To` actually maps to the two properties `System.Message.ToAddress` and `System.Message.ToName`, so the resolved condition tree would have an **OR** that looks for "Bill" in those two properties.

### `SQRO_DONT_RESOLVE_RANGES:0x10`

A range resulting from a date/time expression, an expression such as "20..40", is first resolved to a leaf node that has a **VT_UNKNOWN** value where the punkVal member implements the [IInterval](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iinterval) interface. Unless this flag is set, the returned condition tree will have been further resolved to an **AND** of simple comparisons such as *COP_GREATERTHANOREQUAL* and *COP_LESSTHAN*. For example, for an AQS query "date:this month" resolved against 9/19/2006 10:28:33, if this flag is not set, the resulting condition tree is an **AND** of System.ItemDate *COP_GREATERTHANOREQUAL* 9/1/2006 00:00:00 and System.ItemDate *COP_LESSTHAN* 10/1/2006 00:00:00. If this flag is set, the resulting condition tree will relate System.ItemDate to an **IInterval** such that its [IInterval::GetLimits](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iinterval-getlimits) method returns *ILK_EXPLICIT_INCLUDED*, 9/1/2006 00:00:00, *ILK_EXPLICIT_EXCLUDED* and 10/1/2006 00:00:00.

### `SQRO_DONT_REMOVE_UNRESTRICTED_KEYWORDS:0x20`

An unrestricted keyword is a keyword that is not associated with a value that completes the condition. For example, in the following AQS query, the property denoted by "From" is considered an unrestricted keyword: "Kind:email Subject:"My Resume" From:". If this flag is set, such a property will be present in the resulting condition tree as a leaf node having a *COP_IMPLICIT* operation, an empty string value, and a semantic type of System.StructuredQueryType.Value. Otherwise, it will be removed entirely.

### `SQRO_DONT_SPLIT_WORDS:0x40`

If this flag is set, a group of words not separated by white space will be kept together in a single leaf node. If this flag is not set, the group will be broken up into separate leaf nodes. An application may want to set this flag when resolving a condition tree if the resulting tree will be further processed by code that should do any additional word breaking.

### `SQRO_IGNORE_PHRASE_ORDER:0x80`

If a phrase in an AQS query is enclosed in double quotes, the words in that phrase go into a single leaf node (regardless of whether [SQRO_DONT_SPLIT_WORDS](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-resolve) is set) unless this flag is set, in which case they end up in separate leaf nodes and their order no longer matters. An application can set this flag if it is not able to handle leaf nodes with multiple words correctly.

### `SQRO_ADD_VALUE_TYPE_FOR_PLAIN_VALUES:0x100`

### `SQRO_ADD_ROBUST_ITEM_NAME:0x200`

Work around known issues in word breakers, adding conditions on *PKEY_ItemNameDisplay* as needed.

#### - SQRO_NULL_VALUE_TYPE_FOR_PLAIN_VALUES

**Windows 7 and later.** Supports backward compatibility. Unless this flag is set the query engine generates a value type on resolved leaves that are unnamed entities. Setting this flag is encouraged, as the value type adds no information.

## Remarks

The **STRUCTURED_QUERY_RESOLVE_OPTION** type is defined in StructuredQuery.h as shown here.

``` syntax
typedef int STRUCTURED_QUERY_RESOLVE_OPTION;
```

## See also

[CASE_REQUIREMENT](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-case_requirement)