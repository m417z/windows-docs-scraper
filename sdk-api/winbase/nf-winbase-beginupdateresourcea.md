# BeginUpdateResourceA function

## Description

Retrieves a handle that can be used by the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) function to add, delete, or replace resources in a binary module.

## Parameters

### `pFileName` [in]

Type: **LPCTSTR**

The binary file in which to update resources. An application must be able to obtain write-access to this file; the file referenced by *pFileName* cannot be currently executing. If *pFileName* does not specify a full path, the system searches for the file in the current directory.

### `bDeleteExistingResources` [in]

Type: **BOOL**

Indicates whether to delete the *pFileName* parameter's existing resources. If this parameter is **TRUE**, existing resources are deleted and the updated file includes only resources added with the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) function. If this parameter is **FALSE**, the updated file includes existing resources unless they are explicitly deleted or replaced by using **UpdateResource**.

## Return value

Type: **HANDLE**

If the function succeeds, the return value is a handle that can be used by the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) and [EndUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-endupdateresourcea) functions. The return value is **NULL** if the specified file is not a PE, the file does not exist, or the file cannot be opened for writing. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is recommended that the resource file is not loaded before this function is called. However, if that file is already loaded, it will not cause an error to be returned.

There are some restrictions on resource updates in files that contain Resource Configuration(RC Config) data: LN files and the associated .mui files. Details on which types of resources are allowed to be updated in these files are in the Remarks section for the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) function.

This function can update resources within modules that contain both code and resources. As noted above, there are restrictions on resource updates in LN files and .mui files, both of which contain RC Config data; details of the restrictions are in the reference for the [UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea) function.

#### Examples

For an example see, [Updating Resources](https://learn.microsoft.com/windows/desktop/menurc/using-resources).

> [!NOTE]
> The winbase.h header defines BeginUpdateResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EndUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-endupdateresourcea)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)

[UpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-updateresourcea)