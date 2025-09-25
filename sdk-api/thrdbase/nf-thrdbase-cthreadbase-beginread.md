# CThreadBase::BeginRead

## Description

[The [CThreadBase](https://learn.microsoft.com/windows/desktop/api/thrdbase/nl-thrdbase-cthreadbase) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **BeginRead** method provides thread safety by indicating the beginning of a data read operation when the provider is built on the WMI Provider Framework. [CThreadBase](https://learn.microsoft.com/windows/desktop/api/thrdbase/nl-thrdbase-cthreadbase) is called internally.

## Parameters

### `dwTimeOut`

Time-out for the read data operation. The default is no time-out.

## Return value

This method does not return a value.