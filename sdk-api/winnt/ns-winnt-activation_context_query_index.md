# ACTIVATION_CONTEXT_QUERY_INDEX structure

## Description

The
**ACTIVATION_CONTEXT_QUERY_INDEX** structure is used by
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `ulAssemblyIndex`

One-based index of the assembly whose file table is to be queried.

### `ulFileIndexInAssembly`

Zero-based index of the file in the above assembly to be queried.

## Remarks

Calling the
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function with the FileInformationInAssemblyOfAssemblyInActivationContext option requires that the *pvSubInstance* parameter point to an
**ACTIVATION_CONTEXT_QUERY_INDEX** structure. See the sample for
[ASSEMBLY_FILE_DETAILED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-assembly_file_detailed_information) for an example of its use.