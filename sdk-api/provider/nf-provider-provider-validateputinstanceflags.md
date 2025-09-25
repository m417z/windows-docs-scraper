# Provider::ValidatePutInstanceFlags

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ValidatePutInstanceFlags** method determines whether a set of flags is valid for an instance update operation.

## Parameters

### `lFlags`

Bitmask of flags that are validated.

## Return value

Returns **WBEM_S_NO_ERROR** if the flags are valid and **WBEM_E_UNSUPPORTED_PARAMETER** if one or more flags are not valid.

## Remarks

Framework providers can override this method to validate flags that are unknown to the base [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class.

At present, the [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class supports the following update flags:

* **WBEM_FLAG_CREATE_ONLY**
* **WBEM_FLAG_CREATE_OR_UPDATE**
* **WBEM_FLAG_UPDATE_ONLY**