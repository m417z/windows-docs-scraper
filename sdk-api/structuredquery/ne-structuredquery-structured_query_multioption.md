# STRUCTURED_QUERY_MULTIOPTION enumeration

## Description

A set of flags used by [IQueryParser::SetMultiOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setmultioption) to indicate individual options.

## Constants

### `SQMO_VIRTUAL_PROPERTY:0`

To indicate that a leaf node with property name P and constant C should be replaced with a leaf node with property name Q, operation op, and constant C by [IConditionFactory::Resolve](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation), do the following: call [IQueryParser::SetMultiOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setmultioption) with SQMO_VIRTUAL_PROPERTY as *option*, P as *pszOptionKey*, and for *pOptionValue* provide a **VT_UNKNOWN** with an [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface that enumerates exactly two values: a **VT_BSTR** with value Q, and a **VT_I4** that is a [CONDITION_OPERATION](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/ne-structuredquerycondition-condition_operation) operation.

### `SQMO_DEFAULT_PROPERTY`

To indicate that a leaf node with no property name and a semantic type T (or one that is a subtype of T) should be replaced with one having property name P by [IConditionFactory::Resolve](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-resolve), do the following: call [IQueryParser::SetMultiOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setmultioption) with SQMO_DEFAULT_PROPERTY as *option*, T as *pszOptionKey*, and for *pOptionValue* provide a **VT_LPWSTR** with value P.

### `SQMO_GENERATOR_FOR_TYPE`

To indicate that an [IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator) G should be used to recognize named entities of the semantic type named T, and that [IConditionFactory::Resolve](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iconditionfactory-resolve) should generate condition trees for those named entities, call [IQueryParser::SetMultiOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setmultioption) with SQMO_GENERATOR_FOR_TYPE as *option*, T as *pszOptionKey* and for *pOptionValue* provide a **VT_UNKNOWN** with value G.

### `SQMO_MAP_PROPERTY`

Windows 7, and later. To indicate that a node with property P should map to one or more other properties, call [IQueryParser::SetMultiOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setmultioption) with SQMO_MAP_PROPERTY as *option*, P as *pszOptionKey*, and for *pOptionValue* provide a **VT_VECTOR** or **VT_LPWSTR**, where each string is a property name. During resolution, this map is added to those of the loaded schema. Calling **IQueryParser::SetMultiOption** with *pOptionValue* as **VT_NULL** removes the mapping.