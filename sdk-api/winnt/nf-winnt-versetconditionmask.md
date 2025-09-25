# VerSetConditionMask function

## Description

Sets the bits of a 64-bit value to indicate the comparison operator to use for a specified operating system version attribute. This function is used to build the *dwlConditionMask* parameter of the
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function.

## Parameters

### `ConditionMask` [in]

A value to be passed as the *dwlConditionMask* parameter of the
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function. The function stores the comparison information in the bits of this variable.

Before the first call to **VerSetCondition**, initialize this variable to zero. For subsequent calls, pass in the variable used in the previous call.

### `TypeMask` [in]

A mask that indicates the member of the
[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) structure whose comparison operator is being set. This value corresponds to one of the bits specified in the *dwTypeMask* parameter for the
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_BUILDNUMBER**<br><br>0x0000004 | dwBuildNumber |
| **VER_MAJORVERSION**<br><br>0x0000002 | dwMajorVersion |
| **VER_MINORVERSION**<br><br>0x0000001 | dwMinorVersion |
| **VER_PLATFORMID**<br><br>0x0000008 | dwPlatformId |
| **VER_PRODUCT_TYPE**<br><br>0x0000080 | wProductType |
| **VER_SERVICEPACKMAJOR**<br><br>0x0000020 | wServicePackMajor |
| **VER_SERVICEPACKMINOR**<br><br>0x0000010 | wServicePackMinor |
| **VER_SUITENAME**<br><br>0x0000040 | wSuiteMask |

### `Condition` [in]

The operator to be used for the comparison. The
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function uses this operator to compare a specified attribute value to the corresponding value for the currently running system.

For all values of *dwTypeBitMask* other than VER_SUITENAME, this parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_EQUAL**<br><br>1 | The current value must be equal to the specified value. |
| **VER_GREATER**<br><br>2 | The current value must be greater than the specified value. |
| **VER_GREATER_EQUAL**<br><br>3 | The current value must be greater than or equal to the specified value. |
| **VER_LESS**<br><br>4 | The current value must be less than the specified value. |
| **VER_LESS_EQUAL**<br><br>5 | The current value must be less than or equal to the specified value. |

If *dwTypeBitMask* is VER_SUITENAME, this parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_AND**<br><br>6 | All product suites specified in the **wSuiteMask** member must be present in the current system. |
| **VER_OR**<br><br>7 | At least one of the specified product suites must be present in the current system. |

## Return value

The function returns the condition mask value.

## Remarks

Call this function once for each bit set in the *dwTypeMask* parameter of the
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function.

#### Examples

For an example, see
[Verifying the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/verifying-the-system-version).

## See also

[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)

[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)

[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa)