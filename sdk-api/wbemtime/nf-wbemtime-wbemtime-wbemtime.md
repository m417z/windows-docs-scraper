# WBEMTime::WBEMTime

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]
The **WBEMTime** class constructor facilitates conversions between various Windows and ANSI C run-time time formats.

### Overload list

| Constructor | Description |
| --- | --- |
| [WBEMTime()](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(constbstr)) | Creates an uninitialized time object. |
| [WBEMTime(BSTR)](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(constbstr)) | Initializes the new time object to the value in the parameter. |
| [WBEMTime(const time_t&)](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(consttime_t_)) | Initializes the new time object to the value in the parameter. |
| [WBEMTime(const struct tm)](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(consttm_)) | Initializes the new time object to the value in the parameter. |
| [WBEMTime(const FILETIME&)](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(constfiletime_)) | Initializes the new time object to the value in the parameter. |
| [WBEMTime(const SYSTEMTIME&)](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-wbemtime(constsystemtime_)) | Initializes the new time object to the value in the parameter. |