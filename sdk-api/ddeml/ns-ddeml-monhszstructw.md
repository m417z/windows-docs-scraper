# MONHSZSTRUCTW structure

## Description

Contains information about a Dynamic Data Exchange (DDE) string handle. A DDE monitoring application can use this structure when monitoring the activity of the string manager component of the DDE Management Library.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `fsAction`

Type: **BOOL**

The action being performed on the string identified by the **hsz** member.

| Value | Meaning |
| --- | --- |
| **MH_CLEANUP**<br><br>4 | An application is freeing its DDE resources, causing the system to delete string handles the application had created. (The application called the [DdeUninitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeuninitialize) function.) |
| **MH_CREATE**<br><br>1 | An application is creating a string handle. (The application called the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function.) |
| **MH_DELETE**<br><br>3 | An application is deleting a string handle. (The application called the [DdeFreeStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreestringhandle) function.) |
| **MH_KEEP**<br><br>2 | An application is increasing the usage count of a string handle. (The application called the [DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle) function.) |

### `dwTime`

Type: **DWORD**

The Windows time at which the action specified by the **fsAction** member takes place. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hsz`

Type: **HSZ**

A handle to the string. Because string handles are local to the process, this member is a global atom.

### `hTask`

Type: **HANDLE**

A handle to the task (application instance) performing the action on the string handle.

### `str`

Type: **TCHAR[1]**

Pointer to the string identified by the **hsz** member.

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONCONVSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monconvstruct)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**

## Remarks

> [!NOTE]
> The ddeml.h header defines MONHSZSTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).