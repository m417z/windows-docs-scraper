# IRangeValueProvider::get_LargeChange

## Description

Specifies the value that is added to or subtracted from the [IRangeValueProvider::Value](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irangevalueprovider-get_value)
property when a large change is made, such as when the PAGE DOWN key is pressed.

This property is read-only.

## Parameters

## Remarks

The LargeChange property can support Not a Number (NaN) value. When returning a NaN value, the provider should return a quiet (non-signaling) NaN to avoid raising an exception if floating-point exceptions are turned on. The following example shows how to create a quiet NaN:

```
ULONGLONG ulNaN = 0xFFFFFFFFFFFFFFFF;
    *pRetVal = *reinterpret_cast<double*>(&ulNaN);
```

Alternatively, you can use the following function from the standard C++ libraries:

```
numeric_limits<double>::quiet_NaN( )
```

## See also

[IRangeValueProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irangevalueprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)