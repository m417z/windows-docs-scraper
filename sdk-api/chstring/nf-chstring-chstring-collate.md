# CHString::Collate

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Collate** method uses the wcscoll function to compare a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string with another string.

## Parameters

### `lpsz`

The other string used for comparison.

## Return value

The **Collate** method returns the following values.

## Remarks

The **Collate** method performs a case-sensitive comparison of the strings according to the code page currently in use.

#### Examples

The following code example shows how to use **CHString::Collate**:

```cpp
CHString str1 = L"co-op";
CHString str2 = L"con";

int n;

// collation uses language rules, such as ignoring dashes
n = str1.Collate(str2);
assert(n > 0);

// comparison is a strict ASCII comparison with no language rules
n = str1.Compare(str2);
assert(n < 0);
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Compare](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-compare)

[CHString::CompareNoCase](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-comparenocase)