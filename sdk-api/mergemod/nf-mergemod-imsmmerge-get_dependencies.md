# IMsmMerge::get_Dependencies

## Description

The
**get_Dependencies** method retrieves the
[Dependencies](https://learn.microsoft.com/windows/desktop/Msi/merge-dependencies) property of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::get_Dependencies** Mergemod.dll version 2.0 or later.**IMsmMerge::get_Dependencies** All Mergemod.dll versions.

## Parameters

### `Dependencies`

Pointer to a memory location to be filled with a pointer to a collection of unsatisfied dependencies for the current database. If there is an error, the memory location pointed to by *Dependencies* is set to null.

## Return value

The
**get_Dependencies** function returns the following values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was no database open. |
| **E_INVALIDARG** | The *Dependencies* pointer is null. |
| **E_OUTOFMEMORY** | The system ran out of memory. |
| **E_UNEXPECTED** | Unable to verify dependencies due to internal error. |
| **S_OK** | The function succeeded. |

## Remarks

A module does not need to be open to retrieve dependency information. The client is responsible for releasing the interface returned by this function.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)