# CObjectPathParser::Unparse

## Description

[The [CObjectPathParser](https://learn.microsoft.com/windows/desktop/api/objpath/nl-objpath-cobjectpathparser) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

Converts a structure that contains the parsed path to a string. Use of this object is not recommended. Instead, use the [IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath) COM interface.

## Parameters

### `pInput` [in]

A structure that contains WMI path parts such as server, namespaces, classes, key value identifying a specific instance, and others.

### `pwszPath` [out]

A structure that contains the WMI path.

## Remarks

**UnParse** is a static method.

## See also

[CObjectPathParser](https://learn.microsoft.com/windows/desktop/api/objpath/nl-objpath-cobjectpathparser)