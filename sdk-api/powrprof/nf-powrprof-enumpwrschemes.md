# EnumPwrSchemes function

## Description

[**EnumPwrSchemes** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) instead.]

Enumerates all power schemes. For each power scheme enumerated, the function calls a callback function with information about the power scheme.

## Parameters

### `lpfn` [in]

A pointer to a callback function to be called for each power scheme enumerated. For more information, see Remarks.

### `lParam` [in]

A user-defined value to be passed to the callback function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For each power scheme enumerated, the callback function is called with the following parameters:

``` syntax

typedef BOOLEAN (CALLBACK* PWRSCHEMESENUMPROC)(
  UINT uiIndex,      // power scheme index
  DWORD dwName,      // size of the sName string, in bytes
  LPWSTR sName,      // name of the power scheme
  DWORD dwDesc,      // size of the sDesc string, in bytes
  LPWSTR sDesc,      // description string
  PPOWER_POLICY pp,  // receives the power policy
  LPARAM lParam      // user-defined value
);
```

The *sName* and *sDesc* parameters are null-terminated Unicode strings. The *pp* parameter is a pointer to a
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure containing the power policy scheme. To continue until all power schemes have been enumerated, the callback function must return **TRUE**. To stop the enumeration, the callback function must return **FALSE**.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)