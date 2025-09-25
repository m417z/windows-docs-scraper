# STARTUPINFOEXA structure

## Description

Specifies the window station, desktop, standard handles, and attributes for a new process. It is used with the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) and
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) functions.

## Members

### `StartupInfo`

A [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure.

### `lpAttributeList`

An attribute list. This list is created by the [InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist) function.

## Remarks

Be sure to set the **cb** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure to `sizeof(STARTUPINFOEX)`.

> [!NOTE]
> The winbase.h header defines STARTUPINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist)