# IRDPSRAPIApplicationFilter::get_Windows

## Description

The list of sharable windows.

This property is read-only.

## Parameters

## Remarks

The window objects are also available through the list returned by [IRDPSRAPIApplication::Windows](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiapplication-get_windows). The windows are also exposed by the application filter because it provides easy access to all windows in the session, especially for applications that share only at the window level.

## See also

[IRDPSRAPIApplicationFilter](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiapplicationfilter)