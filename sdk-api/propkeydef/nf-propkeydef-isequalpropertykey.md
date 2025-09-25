# IsEqualPropertyKey macro

## Syntax

```cpp
void IsEqualPropertyKey(
    PROPERTYKEY a,
    PROPERTYKEY b
);
```

## Description

Compares the members of two [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures and returns whether they are equal.

## Parameters

### `a`

The first [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

### `b`

The second [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

## Remarks

The **IsEqualPropertyKey** macro is defined as follows.

```
#define IsEqualPropertyKey(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
```