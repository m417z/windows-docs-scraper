# Provider::ValidateFlags

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ValidateFlags** method determines whether a set of flags is valid.

## Parameters

### `lFlags`

Bitmask of flags that are validated.

### `lAcceptableFlags`

Bitmask of *IFlags* values that are acceptable to the calling method. For more information, see Remarks.

## Return value

Returns **WBEM_S_NO_ERROR** if the flags are valid and **WBEM_E_UNSUPPORTED_PARAMETER** if one or more flags are not valid.

## Remarks

This helper method can be called by an override of any of the following virtual methods to indicate which flags are acceptable as arguments to the virtual method:

* [Provider::ValidateDeletionFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validatedeletionflags)
* [Provider::ValidateEnumerationFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validateenumerationflags)
* [Provider::ValidateGetObjFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validategetobjflags)
* [Provider::ValidateMethodFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validatemethodflags)
* [Provider::ValidatePutInstanceFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validateputinstanceflags)
* [Provider::ValidateQueryFlags](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-validatequeryflags)

The values for *IAcceptableFlags* are limited to the [FlagDefs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt432263(v=vs.85)) enumeration defined as the following:

```cpp
    enum FlagDefs
    {
        EnumerationFlags = 0,
        GetObjFlags = 0,
        MethodFlags = 0,
        DeletionFlags = 0,
        PutInstanceFlags = (WBEM_FLAG_CREATE_OR_UPDATE |
                            WBEM_FLAG_CREATE_ONLY |
                            WBEM_FLAG_UPDATE_ONLY),
        QueryFlags = 0
    };
```