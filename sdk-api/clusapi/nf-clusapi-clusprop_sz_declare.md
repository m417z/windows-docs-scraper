# CLUSPROP_SZ_DECLARE macro

## Description

Creates a
[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85)) structure with the **sz**
member set to a size determined by the caller.

## Parameters

### `name`

Name of the [CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85)) structure to be
created.

### `cch`

The size (that is, count of characters) of the **sz** member array. This value must
be a constant.

## Remarks

ClusAPI.h defines **CLUSPROP_SZ_DECLARE** as follows:

``` syntax
#define CLUSPROP_SZ_DECLARE( name, cch )    \
    struct {                                \
        CLUSPROP_SYNTAX Syntax;             \
        DWORD           cbLength;           \
        WCHAR           sz[(cch + 1) & ~1]; \
    } name
```

#### Examples

The following example shows how to use
**CLUSPROP_SZ_DECLARE**:

```cpp
WCHAR szNameData[] = L"Object Name";
CLUSPROP_SZ_DECLARE( NameValue, sizeof( szNameData ) / sizeof( WCHAR ) );
NameValue.Syntax.dw = CLUSPROP_SYNTAX_LIST_VALUE_SZ;
NameValue.cbLength = sizeof( szNameData );
StringCbCopy( NameValue.sz, NameValue.cbLength, szNameData );

```

## See also

[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85))