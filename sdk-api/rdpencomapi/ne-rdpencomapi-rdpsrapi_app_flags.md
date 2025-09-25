# RDPSRAPI_APP_FLAGS enumeration

## Description

Defines values for the type of application. You can retrieve these flags from the [IRDPSRAPIApplication](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiapplication) interface that represents each application.

You can retrieve the list of applications that are running on the sharing user session for both the sharer and the viewer through the [IRDPSRAPIApplicationFilter](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiapplicationfilter) interface by calling the [get_Applications](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiapplicationfilter-get_applications) method.

## Constants

### `APP_FLAG_PRIVILEGED:1`

This flag indicates that the application cannot be shared. The application runs at a higher level than the process that is using the Windows Desktop Sharing API. An application can use this flag to prevent the user from sharing it by either disabling the entry for the application in the user interface or by not showing the entry.