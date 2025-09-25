# WbemComparisonFlagEnum enumeration

## Description

The
WbemComparisonFlagEnum constants define the settings for object comparison and are used by
[SWbemObject.CompareTo_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-compareto-).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use the Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemComparisonFlagIncludeAll:0`

Used to compare all properties, qualifiers, and flavors.

### `wbemComparisonFlagIgnoreQualifiers:0x1`

Ignores all qualifiers (including [Key](https://learn.microsoft.com/windows/desktop/WmiSdk/key-qualifier) and [Dynamic](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-wmi-qualifiers)) in comparison.

### `wbemComparisonFlagIgnoreObjectSource:0x2`

Ignores the source of the objects, namely the server and the namespace they came from, in comparison to other objects.

### `wbemComparisonFlagIgnoreDefaultValues:0x4`

Ignores default values of properties (only meaningful when comparing classes).

### `wbemComparisonFlagIgnoreClass:0x8`

Instructs the system to assume that the objects being compared are instances of the same class. Consequently, this constant compares instance-related information only. Use to optimize performance. If the objects are not of the same class, the results will be undefined.

### `wbemComparisonFlagIgnoreCase:0x10`

Compares string values in a case-insensitive manner. This applies both to strings and to qualifier values. Property and qualifier names are always compared in a case-insensitive manner whether this constant is specified or not.

### `wbemComparisonFlagIgnoreFlavor:0x20`

Ignore qualifier flavors. This constant still takes qualifier values into account, but ignores flavor distinctions such as propagation rules and override restrictions.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)