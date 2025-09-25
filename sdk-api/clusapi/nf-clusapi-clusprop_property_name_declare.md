# CLUSPROP_PROPERTY_NAME_DECLARE macro

## Description

Creates a [CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85)) structure with
the **sz** member set to a size determined by the caller.

## Parameters

### `name`

Name of the [CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
structure to be created.

### `cch`

The size (that is, count of characters) of the **sz** member array. This value must
be a constant.

## Remarks

ClusAPI.h defines
**CLUSPROP_PROPERTY_NAME_DECLARE** as follows:

``` syntax
#define CLUSPROP_PROPERTY_NAME_DECLARE( name, cch ) \
    struct {                                        \
        CLUSPROP_SYNTAX Syntax;                     \
        DWORD           cbLength;                   \
        WCHAR           sz[(cch + 1) & ~1];         \
    } name
```

#### Examples

The following example shows how to use
**CLUSPROP_PROPERTY_NAME_DECLARE**. For
another example, see
[Creating Physical Disk Resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-physical-disk-resources).

```cpp
WCHAR szName[] = L"Name";
CLUSPROP_PROPERTY_NAME_DECLARE( PropName, sizeof( szName ) / sizeof( WCHAR ) );
PropName.Syntax.dw = CLUSPROP_SYNTAX_LIST_VALUE_SZ;
PropName.cbLength  = sizeof( szName );
StringCbCopy( PropName.sz, PropName.cbLength, szName );

```

## See also

[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))