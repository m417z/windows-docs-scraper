# EndUpdateResourceW function

## Description

Commits or discards changes made prior to a call to [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea).

## Parameters

### `hUpdate` [in]

Type: **HANDLE**

A module handle returned by the [BeginUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-beginupdateresourcea) function, and used by [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea), referencing the file to be updated.

### `fDiscard` [in]

Type: **BOOL**

Indicates whether to write the resource updates to the file. If this parameter is **TRUE**, no changes are made. If it is **FALSE**, the changes are made: the resource updates will take effect.

## Return value

Type: **BOOL**

Returns **TRUE** if the function succeeds; **FALSE** otherwise. If the function succeeds and *fDiscard* is **TRUE**, then no resource updates are made to the file; otherwise all successful resource updates are made to the file. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before you call this function, make sure all file handles other than the one returned by [BeginUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-beginupdateresourcea) are closed.

This function can update resources within modules that contain both code and resources. There are restrictions on resource updates in LN files and .mui files, both of which contain Resource Configuration data; details of the restrictions are in the reference for the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) function.

#### Examples

For an example, see [Updating Resources](https://learn.microsoft.com/windows/desktop/menurc/using-resources).

> [!NOTE]
> The winbase.h header defines EndUpdateResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BeginUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-beginupdateresourcea)

**Conceptual**

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)

[UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea)