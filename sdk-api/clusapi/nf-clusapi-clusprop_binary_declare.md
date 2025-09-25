# CLUSPROP_BINARY_DECLARE macro

## Description

Creates a [CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary) structure with the **rgb** member set to a size determined by the caller.

## Parameters

### `name`

Name of the [CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary) structure to be created.

### `cb`

The size (count of bytes) of the **rgb** member array. This value must be a constant.

## Remarks

ClusAPI.h defines **CLUSPROP_BINARY_DECLARE** as follows:

``` syntax
#define CLUSPROP_BINARY_DECLARE( name, cch ) \
    struct {                                 \
        CLUSPROP_SYNTAX Syntax;              \
        DWORD           cbLength;            \
        BYTE            rgb[(cch + 3) & ~3]; \
    } name
```

#### Examples

The following example shows how to use **CLUSPROP_BINARY_DECLARE**:

```cpp
BYTE ByteData[] = { 'A', 1, 'B', 2, 'C' };
CLUSPROP_BINARY_DECLARE( ByteValue, sizeof( ByteData ) );
ByteValue.Syntax.dw = CLUSPROP_SYNTAX_LIST_VALUE_SZ;
ByteValue.cbLength = sizeof( ByteData );
memcpy( ByteValue.rgb, ByteData, sizeof( ByteData ) );

```

## See also

[CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary)