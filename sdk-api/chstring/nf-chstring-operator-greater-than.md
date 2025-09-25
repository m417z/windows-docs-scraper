# operator>

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class is part of the WMI Provider Framework which is now considered in final state, and no further development, enhancements, or updates will be available for non-security related issues affecting these libraries.
The [MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new development.]

The **CHString** comparison operators compare two strings.
These operators are a convenient substitute for the case-sensitive [Compare](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-compare) method.

## Parameters

### `s1`

Reference to the **CHString** to the left of the operator for this comparison.

### `s2`

Reference to the **CHString** to the right of the operator for this comparison.

## Return value

If the strings meet the comparison condition, the operators return a nonzero value.
Otherwise, 0 is returned.

## Remarks

#### Examples

The following code example shows the use of a **CHString** Comparison Operator:

```cpp
CHString s1( L"abc" );
CHString s2( L"abd" );

assert( s1 > s2 );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)