# IGPM::GetRSOP

## Description

Creates and returns an
[GPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop). You can specify the Resultant Set of Policy (RSoP) mode and a Windows Management Instrumentation (WMI) namespace.

## Parameters

### `gpmRSoPMode` [in]

Required. Mode in which to open the object. The following modes are supported.

#### rsopPlanning

Specifies RSoP planning mode

#### rsopLogging

Specifies RSoP logging mode

#### rsopUnknown

Valid only if the *bstrNamespace* parameter is specified

To perform the query, RSoP planning mode requires a domain controller that is running Windows Server.

### `bstrNamespace` [in]

WMI namespace for the [IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop)**GPMRSOP****GPMRSOP**. Use a null-terminated string. This parameter can be **NULL**. For more information about how to retrieve the namespace, see the "Remarks" section.

### `lFlags` [in]

This parameter must be zero.

### `ppIGPMRSOP` [out]

Address of a pointer to the
[IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop) object.

### VB

Returns a reference to a [GPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop) object.

## Remarks

To retrieve the WMI namespace, call the
[Namespace](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/igpmrsop-property-methods) property method of the [IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop) interface. Or, call the **RsopCreateSession** method of the
[RsopLoggingModeProvider](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsoploggingmodeprovider) and
[RsopPlanningModeProvider](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsopplanningmodeprovider) WMI classes. For more information about these methods, see the [Group Policy](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-start-page) documentation.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop)