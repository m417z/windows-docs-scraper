# PreFetchCacheLine macro

## Syntax

```cpp
void PreFetchCacheLine(
    int l,
    VOID CONST *a
);
```

## Description

Indicates to the processor that a cache line will be needed in the near future.

## Parameters

### `l`

How often the cache line will be needed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PF_TEMPORAL_LEVEL_1** | The cache line should be loaded into all caches and is likely to be accessed multiple times. |
| **PF_NON_TEMPORAL_LEVEL_ALL** | The cache line is not likely to be needed again after the first reference. |

### `a`

The address of the cache line to be loaded. This address is not required to be on a cache line boundary.

## Remarks

This macro can be called on all processor platforms where Windows is supported, but it has no effect on some platforms. The definition varies from platform to platform. The following are some definitions of this macro in Winnt.h:

``` syntax
#define PreFetchCacheLine(l, a)  _mm_prefetch((CHAR CONST *) a, l)

#define PreFetchCacheLine(l, a)

#define PreFetchCacheLine  __lfetch

```