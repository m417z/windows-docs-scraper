# ACTCTXA structure

## Description

The
**ACTCTX** structure is used by the
[CreateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createactctxa) function to create the activation context.

## Members

### `cbSize`

The size, in bytes, of this structure. This is used to determine the version of this structure.

### `dwFlags`

Flags that indicate how the values included in this structure are to be used. Set any undefined bits in **dwFlags** to 0. If any undefined bits are not set to 0, the call to
[CreateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createactctxa) that creates the activation context fails and returns an invalid parameter error code.

| Bit flag | Meaning |
| --- | --- |
| **ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID**<br><br>1 | 0x001 |
| **ACTCTX_FLAG_LANGID_VALID**<br><br>2 | 0x002 |
| **ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID**<br><br>4 | 0x004 |
| **ACTCTX_FLAG_RESOURCE_NAME_VALID**<br><br>8 | 0x008 |
| **ACTCTX_FLAG_SET_PROCESS_DEFAULT**<br><br>16 | 0x010 |
| **ACTCTX_FLAG_APPLICATION_NAME_VALID**<br><br>32 | 0x020 |
| **ACTCTX_FLAG_HMODULE_VALID**<br><br>128 | 0x080 |

### `lpSource`

Null-terminated string specifying the path of the manifest file or PE image to be used to create the activation context. If this path refers to an EXE or DLL file, the **lpResourceName** member is required.

### `wProcessorArchitecture`

Identifies the type of processor used. Specifies the system's processor architecture.

This value can be one of the following values:

### `wLangId`

Specifies the language manifest that should be used. The default is the current user's current UI language.

If the requested language cannot be found, an approximation is searched for using the following order:

* The current user's specific language. For example, for US English (1033).
* The current user's primary language. For example, for English (9).
* The current system's specific language.
* The current system's primary language.
* A nonspecific worldwide language. Language neutral (0).

### `lpAssemblyDirectory`

The base directory in which to perform private assembly probing if assemblies in the activation context are not present in the system-wide store.

### `lpResourceName`

Pointer to a null-terminated string that contains the resource name to be loaded from the PE specified in **hModule** or **lpSource**. If the resource name is an integer, set this member using MAKEINTRESOURCE. This member is required if **lpSource** refers to an EXE or DLL.

### `lpApplicationName`

The name of the current application. If the value of this member is set to null, the name of the executable that launched the current process is used.

### `hModule`

Use this member rather than **lpSource** if you have already loaded a DLL and wish to use it to create activation contexts rather than using a path in **lpSource**. See **lpResourceName** for the rules of looking up resources in this module.

## Remarks

If the file identified by the value of the **lpSource** member is a PE image file,
[CreateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createactctxa) searches for the manifest in the .manifest file located in the same directory and in the first RT_MANIFEST resource located in the PE image file. To find a specific named resource from the image, set the **lpResourceName** to the name of the resource, and add the ACTCTX_FLAG_RESOURCE_NAME_VALID to the **dwFlags** member. Refer to
[FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea) for more information on specifying resource names.

In most cases, the caller should not set the ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID and ACTCTX_FLAG_LANGID_VALID flags of the **dwFlags** member. Also, in most cases, the value of the **lpResourceName** member should be set to null.

The values of **lpApplicationName** and **lpAssemblyDirectory** are not set to null when the executable creating the activation context is a host for the application. In this case, the host can set a different name for the application to find configuration files, report errors, and so forth.

> [!NOTE]
> The winbase.h header defines ACTCTX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data)

[CreateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createactctxa)