# CObjectPathParser::Parse

## Description

[The [CObjectPathParser](https://learn.microsoft.com/windows/desktop/api/objpath/nl-objpath-cobjectpathparser) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

Parses a string that contains a WMI path into a structure the contains the path parts, such as the server, namespace, class, key that identifies an instance, and others. Use of this object is not recommended. Instead, use the [IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath) COM interface.

## Parameters

### `RawPath` [in]

The raw path data.

### `pOutput` [out]

A structure that contains the parsed path parts.

## See also

[CObjectPathParser](https://learn.microsoft.com/windows/desktop/api/objpath/nl-objpath-cobjectpathparser)