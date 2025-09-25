# VerifyVersionInfoW function

## Description

Compares a set of operating system version requirements to the corresponding values for the currently running version of the system.This function is subject to manifest-based behavior. For more information, see the Remarks section.

**Note:** This function has been deprecated for Windows 10. See [targeting your applications for Windows](https://learn.microsoft.com/windows/win32/sysinfo/targeting-your-application-at-windows-8-1) for more information.

## Parameters

### `lpVersionInformation` [in]

A pointer to an
[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) structure containing the operating system version requirements to compare. The *dwTypeMask* parameter indicates the members of this structure that contain information to compare.

You must set the **dwOSVersionInfoSize** member of this structure to `sizeof(OSVERSIONINFOEX)`. You must also specify valid data for the members indicated by *dwTypeMask*. The function ignores structure members for which the corresponding *dwTypeMask* bit is not set.

### `dwTypeMask` [in]

A mask that indicates the members of the
[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) structure to be tested. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **VER_BUILDNUMBER**<br><br>0x0000004 | **dwBuildNumber** |
| **VER_MAJORVERSION**<br><br>0x0000002 | **dwMajorVersion**<br><br>If you are testing the major version, you must also test the minor version and the service pack major and minor versions. |
| **VER_MINORVERSION**<br><br>0x0000001 | **dwMinorVersion** |
| **VER_PLATFORMID**<br><br>0x0000008 | **dwPlatformId** |
| **VER_SERVICEPACKMAJOR**<br><br>0x0000020 | **wServicePackMajor** |
| **VER_SERVICEPACKMINOR**<br><br>0x0000010 | **wServicePackMinor** |
| **VER_SUITENAME**<br><br>0x0000040 | **wSuiteMask** |
| **VER_PRODUCT_TYPE**<br><br>0x0000080 | **wProductType** |

### `dwlConditionMask` [in]

The type of comparison to be used for each **lpVersionInfo** member being compared. To build this value, call the
[VerSetConditionMask](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-versetconditionmask) function or the
[VER_SET_CONDITION](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-ver_set_condition) macro once for each
[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) member being compared.

## Return value

If the currently running operating system satisfies the specified requirements, the return value is a nonzero value.

If the current system does not satisfy the requirements, the return value is zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_OLD_WIN_VERSION.

If the function fails, the return value is zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns an error code other than ERROR_OLD_WIN_VERSION.

## Remarks

The
**VerifyVersionInfo** function retrieves version information about the currently running operating system and compares it to the valid members of the **lpVersionInfo** structure. This enables you to easily determine the presence of a required set of operating system version conditions. It is preferable to use
**VerifyVersionInfo** rather than calling the
[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) function to perform your own comparisons.

Typically,
**VerifyVersionInfo** returns a nonzero value only if all specified tests succeed. However, major, minor, and service pack versions are tested in a hierarchical manner because the operating system version is a combination of these values. If a condition exists for the major version, it supersedes the conditions specified for minor version and service pack version. (You cannot test for major version greater than 5 and minor version less than or equal to 1. If you specify such a test, the function will change the request to test for a minor version greater than 1 because it is performing a greater than operation on the major version.)

The function tests these values in this order: major version, minor version, and service pack version. The function continues testing values while they are equal, and stops when one of the values does not meet the specified condition. For example, if you test for a system greater than or equal to version 5.1 service pack 1, the test succeeds if the current version is 6.0. (The major version is greater than the specified version, so the testing stops.) In the same way, if you test for a system greater than or equal to version 5.1 service pack 1, the test succeeds if the current version is 5.2. (The minor version is greater than the specified versions, so the testing stops.) However, if you test for a system greater than or equal to version 5.1 service pack 1, the test fails if the current version is 5.0 service pack 2. (The minor version is not greater than the specified version, so the testing stops.)

To verify a range of system versions, you must call
**VerifyVersionInfo** twice. For example, to verify that the system version is greater than 5.0 but less than or equal to 5.1, first call
**VerifyVersionInfo** to test that the major version is 5 and the minor version is greater than 0, then call
**VerifyVersionInfo** again to test that the major version is 5 and the minor version is less than or equal to 1.

Identifying the current operating system is usually not the best way to determine whether a particular operating system feature is present. This is because the operating system may have had new features added in a redistributable DLL. Rather than using
[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) to determine the operating system platform or version number, test for the presence of the feature itself. For more information, see
[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version).

To verify whether the current operating system is either the Media Center or Tablet PC version of Windows, call [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics).

**Windows 10:** **VerifyVersionInfo** returns false when called by applications that do not have a compatibility manifest for Windows 8.1 or Windows 10 if the *lpVersionInfo* parameter is set so that it specifies Windows 8.1 or Windows 10, even when the current operating system version is Windows 8.1 or Windows 10. Specifically, **VerifyVersionInfo** has the following behavior:

* If the application has no manifest, **VerifyVersionInfo** behaves as if the operation system version is Windows 8 (6.2).
* If the application has a manifest that contains the GUID that corresponds to Windows 8.1, **VerifyVersionInfo** behaves as if the operation system version is Windows 8.1 (6.3).
* If the application has a manifest that contains the GUID that corresponds to Windows 10, **VerifyVersionInfo** behaves as if the operation system version is Windows 10 (10.0).

The [Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis) use the **VerifyVersionInfo** function, so the behavior [IsWindows8Point1OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows8point1orgreater) and [IsWindows10OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows10orgreater) are similarly affected by the presence and content of the manifest.

To manifest your applications for Windows 8.1 or Windows 10, see [Targeting your application for Windows](https://learn.microsoft.com/windows/desktop/SysInfo/targeting-your-application-at-windows-8-1).

#### Examples

For an example, see
[Verifying the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/verifying-the-system-version).

> [!NOTE]
> The winbase.h header defines VerifyVersionInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa)

[OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)

[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)

[VER_SET_CONDITION](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-ver_set_condition)

[VerSetConditionMask](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-versetconditionmask)