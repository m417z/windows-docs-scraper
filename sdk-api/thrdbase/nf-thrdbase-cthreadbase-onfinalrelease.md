# CThreadBase::OnFinalRelease

## Description

[The [CThreadBase](https://learn.microsoft.com/windows/desktop/api/thrdbase/nl-thrdbase-cthreadbase) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **OnFinalRelease** method is a virtual function called by [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the reference count reaches zero. [CThreadBase](https://learn.microsoft.com/windows/desktop/api/thrdbase/nl-thrdbase-cthreadbase) is called internally.