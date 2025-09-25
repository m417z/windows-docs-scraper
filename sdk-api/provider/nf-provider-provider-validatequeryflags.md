# Provider::ValidateQueryFlags

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ValidateQueryFlags** method determines whether a set of flags is valid for a query operation.

## Parameters

### `lFlags`

Bitmask of flags that are validated.

## Return value

Returns **WBEM_S_NO_ERROR** if the flags are valid and **WBEM_E_UNSUPPORTED_PARAMETER** if one or more flags are not valid.

## Remarks

At present, the [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class does not support any query flags. Therefore, if *lFlags* is set to a value other than zero (0), **Provider::ValidateQueryFlags** automatically returns **WBEM_E_UNSUPPORTED_PARAMETER**.

Framework providers must override this method to validate flags that are unknown to the base [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class.