# Provider::CreateNewInstance

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **CreateNewInstance** method allocates a new [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) object and returns a pointer to it.

## Parameters

### `pMethodContext`

A pointer to the context associated with this instance.

## Return value

Returns a pointer to the new instance.

## Remarks

The caller must call either CInstance::Release or [Provider::Commit](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-commit) on the returned pointer. Either of these methods may be used, but they are not interchangeable. Refer to the Remarks section on each of these methods to determine which is appropriate.

This method does not return a **NULL** pointer. If it fails, it throws an exception.