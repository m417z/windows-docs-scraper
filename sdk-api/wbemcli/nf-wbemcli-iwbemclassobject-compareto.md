# IWbemClassObject::CompareTo

## Description

The **IWbemClassObject::CompareTo** method compares an object to another Windows Management object. Note that there are certain constraints in this comparison process.

## Parameters

### `lFlags` [in]

Specifies the object characteristics to consider in comparison to another object. It can be **WBEM_COMPARISON_INCLUDE_ALL** to consider all features, or any combination of these flags.

#### WBEM_FLAG_IGNORE_OBJECT_SOURCE

Ignore the source of the objects, namely the server and the namespace they came from, in comparison to other objects.

#### WBEM_FLAG_IGNORE_QUALIFIERS

Ignore all qualifiers (including **Key** and **Dynamic**) in comparison.

#### WBEM_FLAG_IGNORE_DEFAULT_VALUES

Ignore default values of properties. This flag is only meaningful when comparing classes.

#### WBEM_FLAG_IGNORE_FLAVOR

Ignore qualifier flavors. This flag still takes qualifier values into account, but ignores flavor distinctions such as propagation rules and override restrictions (for more information, see
[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)).

#### WBEM_FLAG_IGNORE_CASE

Compare string values in a case-insensitive manner. This applies both to strings and to qualifier values. Property and qualifier names are always compared in a case-insensitive manner whether this flag is specified or not.

#### WBEM_FLAG_IGNORE_CLASS

Assume that the objects being compared are instances of the same class. Consequently, this flag compares instance-related information only. Use this flag to optimize performance. If the objects are not of the same class, the results are undefined.

### `pCompareTo` [in]

Object in comparison. This pointer must point to a valid
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) instance. It cannot be **NULL**.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)

[WBEM_COMPARISON_FLAG](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_comparison_flag)