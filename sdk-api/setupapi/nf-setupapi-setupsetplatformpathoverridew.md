# SetupSetPlatformPathOverrideW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupSetPlatformPathOverride** function is used to set a platform path override for a target machine when working with INFs from a different machine. As such, it can refer to a different platform than it is currently running on. For dealing with media sources, it can refer to platforms that are no longer supported, such as Alpha, MIPS, and PPC. It removes the platform path override if none is specified.

## Parameters

### `Override` [in]

Pointer to a **null**-terminated string that contains the replacement platform information. For example, "alpha" or "x86". This parameter may be **NULL**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NOT_ENOUGH_MEMORY,
**SetupSetPlatformPathOverride** was unable to store the *Override* string.

## Remarks

**SetPlatformPathOverride** is used to change the source path when queuing files. If a platform path override has been set by a call to **SetPlatformPathOverride**, any setup function that queues file copy operations will examine the final component of the source path and if the final component matches the name of the user's platform, replace it with the override string set by **SetPlatformPathOverride**.

For example, consider a MIPS-platform machine where the platform has been set to Alpha by a call to **SetPlatformPathOverride**. After the platform path override has been set, a file copy operation is queued with a source path of \\pop\top\baz\mips\x.exe, the path will be changed to \\pop\top\baz\alpha\x.exe.

The paths of file copy operations queued before the path override is set are not changed.

> [!NOTE]
> The setupapi.h header defines SetupSetPlatformPathOverride as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupSetDirectoryId](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetdirectoryida)