# SetupSetDirectoryIdA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupSetDirectoryId** function associates a directory identifier in an INF file with a specific directory.

## Parameters

### `InfHandle` [in]

A handle for a loaded INF file.

### `Id` [in]

A directory identifier (DIRID) to use for an association. This parameter can be **NULL**. This DIRID must be greater than or equal to DIRID_USER. If an association already exists for this DIRID, it is overwritten. If *Id* is **NULL**, the *Directory* parameter is ignored, and the current set of user-defined DIRIDs is deleted.

### `Directory` [in]

A pointer to a **null**-terminated string that specifies the directory path to associate with *Id*. This parameter can be **NULL**. If *Directory* is **NULL**, any directory associated with *Id* is unassociated. No error results if *Id* is not currently associated with a directory.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupSetDirectoryId** can be used prior to queuing file copy operations to specify a target location that is only known at runtime.

After setting the directory identifier, this function traverses all appended INF files, and if any of them have unresolved string substitutions, the function attempts to re-apply string substitution to them based on the new DIRID mapping. Because of this, some INF values may change after calling
**SetupSetDirectoryId**.

DIRID_ABSOLUTE_16BIT is not a valid value for *Id*, which ensures compatibility with 16-bit setup.

> [!NOTE]
> The setupapi.h header defines SetupSetDirectoryId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)