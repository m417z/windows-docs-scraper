# WBEM_COMPARISON_FLAG enumeration

## Description

Contains flags that define the comparison to perform when using the [IWbemClassObject::CompareTo](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-compareto) method.

## Constants

### `WBEM_COMPARISON_INCLUDE_ALL:0`

Compare all features.

### `WBEM_FLAG_IGNORE_QUALIFIERS:0x1`

Ignore all qualifiers (including **Key** and **Dynamic**) in comparison.

### `WBEM_FLAG_IGNORE_OBJECT_SOURCE:0x2`

Ignore the source of the objects, namely the server and the namespace they came from, in comparison to other objects.

### `WBEM_FLAG_IGNORE_DEFAULT_VALUES:0x4`

Ignore default values of properties. This flag is only meaningful when comparing classes.

### `WBEM_FLAG_IGNORE_CLASS:0x8`

Assume that the objects being compared are instances of the same class. Consequently, this flag compares instance-related information only. Use this flag to optimize performance. If the objects are not of the same class, the results are undefined.

### `WBEM_FLAG_IGNORE_CASE:0x10`

Compare string values in a case-insensitive manner. This applies both to strings and to qualifier values. Property and qualifier names are always compared in a case-insensitive manner whether this flag is specified or not.

### `WBEM_FLAG_IGNORE_FLAVOR:0x20`

Ignore qualifier flavors. This flag still takes qualifier values into account, but ignores flavor distinctions such as propagation rules and override restrictions (for more information, see
[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)).