# IInterval::GetLimits

## Description

Specifies the lower and upper limits of an interval, each of which may be infinite or a specific value.

When a condition tree expresses that the value of a property must fall in a certain range, the property can be expressed as a leaf node. The node must be a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) containing a **vt** value type tag of VT_UNKNOWN and an IUnknown* **punkVal** that is a pointer to an object that implements [IInterval](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iinterval).

## Parameters

### `pilkLower` [out]

Type: **[INTERVAL_LIMIT_KIND](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-interval_limit_kind)***

Receives a pointer to a value from the [INTERVAL_LIMIT_KIND](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-interval_limit_kind) enumeration that indicates whether the lower bound of the interval is inclusive, exclusive, or infinite.

### `ppropvarLower` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives a pointer to the value for the lower limit of the interval. If the *pilkLower* parameter is set to *ILK_NEGATIVE_INFINITY* or *ILK_POSITIVE_INFINITY*, this value is set to **VT_EMPTY**.

### `pilkUpper` [out]

Type: **[INTERVAL_LIMIT_KIND](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-interval_limit_kind)***

Receives a pointer to a value from the [INTERVAL_LIMIT_KIND](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-interval_limit_kind) enumeration that indicates whether the upper bound of the interval is inclusive, exclusive, or infinite.

### `ppropvarUpper` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives a pointer to the value for the upper limit of the interval. If the *pilkUpper* parameter is set to *ILK_NEGATIVE_INFINITY* or *ILK_POSITIVE_INFINITY*, this value will be set to **VT_EMPTY**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method retrieves interval limits in two [INTERVAL_LIMIT_KIND](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-interval_limit_kind)—[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) pairs. The first pair specifies the lower limit of the interval, and the second pari specifies the upper limit of the interval.

The lower limit must be less than the upper limit or the interval will be empty. The only exception is when the lower and upper limits are equal and both are set to *ILK_EXPLICIT_INCLUDED*. In this case the range is the single value to which both limits are set. The following table illustrates how the pairs work to define intervals.

| pilkLower | ppropvarLower | pilkLower | ppropvarLower | Description |
| --- | --- | --- | --- | --- |
| ILK_EXPLICIT_INCLUDED | 3 | ILK_EXPLICIT_INCLUDED | 3 | The lowest value in the range is 3 because the 3 is explicitly included in the range.<br><br>The highest value in the range is also 3 (explicitly included), and the interval consists of only the number 3. |
| ILK_EXPLICIT_INCLUDED | 3 | ILK_EXPLICIT_EXCLUDED | 3 | The lowest value in the range is 3 (explicitly included), but the upper limit is also 3 and is explicitly excluded. Therefore, the interval being described is an empty interval. |
| ILK_EXPLICIT_INCLUDED | 3 | ILK_EXPLICIT_EXCLUDED | 6 | The integer interval begins at and includes 3, and ends at but does not include 6. |
| ILK_NEGATIVE_INFINITY | VT_EMPTY | ILK_POSITIVE_INFINITY | VT_EMPTY | All integers are included in the interval. |