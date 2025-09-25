# INamedEntityCollector::Add

## Description

Adds a single (potential) named entity to this [INamedEntityCollector](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-inamedentitycollector) collection, as identified in a tokenized span of the input string being parsed.

## Parameters

### `beginSpan` [in]

Type: **ULONG**

The beginning of the overall token span, including any leading quotation marks.

### `endSpan` [in]

Type: **ULONG**

The end of the overall token span including any trailing quotation marks.

### `beginActual` [in]

Type: **ULONG**

The beginning of the part of the token span that identifies the potential named entity.

### `endActual` [in]

Type: **ULONG**

The end of the part of the token span that identifies the potential named entity.

### `pType` [in]

Type: **[IEntity](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ientity)***

The semantic type of the named entity.

### `pszValue` [in]

Type: **LPCWSTR**

The name of the entity as a string.

### `certainty` [in]

Type: **[NAMED_ENTITY_CERTAINTY](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-named_entity_certainty)**

One of the following values:

| Value | Information |
| --- | --- |
| NEC_LOW | It could be this named entity, but additional evidence is advisable. |
| NEC_MEDIUM | It is likely this named entity; it is okay to use it. |
| NEC_HIGH | It almost certainly is this named entity; it should be okay to discard other possibilities. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a query parser parses an input string into condition nodes, the parser invokes an [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator) object that, in turn, invokes **INamedEntityCollector::Add** to collect possible named entities in the input string. The [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator) object must call this method for each potential named entity it recognizes in the input string. For each entity, the condition generator must provide the following information:

* what part of the input string it covers
* the semantic type of the named entity
* a string representation of the value of the named entity
* the level of certainty that the input really is that named entity

If the named entity was used in the interpretation of the input string, the [GenerateForLeaf](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditiongenerator-generateforleaf) method of the condition generator will be invoked with the value string as one of the arguments.

The following relationship must be maintained between the four first arguments: *beginSpan* = *beginActual* < *endActual* = *endSpan*.