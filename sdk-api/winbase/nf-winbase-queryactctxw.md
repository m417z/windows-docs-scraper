# QueryActCtxW function

## Description

The
**QueryActCtxW** function queries the activation context.

## Parameters

### `dwFlags` [in]

This parameter should be set to one of the following flag bits.

| Flag | Meaning |
| --- | --- |
| **QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX** | **QueryActCtxW** queries the activation context active on the thread instead of the context specified by *hActCtx*. This is usually the last activation context passed to [ActivateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-activateactctx). If **ActivateActCtx** has not been called, the active activation context can be the activation context used by the executable of the current process. In other cases, the operating system determines the active activation context. For example, when the callback function to a new thread is called, the active activation context may be the context that was active when you created the thread by calling [CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread). |
| **QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE** | **QueryActCtxW** interprets *hActCtx* as an **HMODULE** data type and queries an activation context that is associated with a DLL or EXE. <br><br>When a DLL or EXE is loaded, the loader checks for a manifest stored in a resource. If the loader finds an RT_MANIFEST resource with a resource identifier set to ISOLATIONAWARE_MANIFEST_ RESOURCE_ID, the loader associates the resulting activation context with the DLL or EXE. This is the activation context that **QueryActCtxW** queries when the QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE flag has been set. |
| **QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS** | **QueryActCtxW** interprets *hActCtx* as an address within a DLL or EXE and queries an activation context that has been associated with the DLL or EXE. This can be any address within the DLL or EXE. For example, the address of any function within a DLL or EXE or the address of any static data, such as a constant string. <br><br>When a DLL or EXE is loaded, the loader checks for a manifest stored in a resource in the same way as QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE. |

### `hActCtx` [in]

Handle to the activation context that is being queried.

### `pvSubInstance` [in, optional]

Index of the assembly, or assembly and file combination, in the activation context. The meaning of the *pvSubInstance* depends on the option specified by the value of the *ulInfoClass* parameter.

 This parameter may be null.

| ulInfoClass Option | Meaning |
| --- | --- |
| **AssemblyDetailedInformationInActivationContext** | Pointer to a **DWORD** that specifies the index of the assembly within the activation context. This is the activation context that **QueryActCtxW** queries. |
| **FileInformationInAssemblyOfAssemblyInActivationContext** | Pointer to an [ACTIVATION_CONTEXT_QUERY_INDEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-activation_context_query_index) structure. If **QueryActCtxW** is called with this option and the function succeeds, the returned buffer contains information for a file in the assembly. This information is in the form of the [ASSEMBLY_FILE_DETAILED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-assembly_file_detailed_information) structure. |

### `ulInfoClass` [in]

This parameter can have only the values shown in the following table.

| Option | Meaning |
| --- | --- |
| **ActivationContextBasicInformation**<br><br>1 | Not available. |
| **ActivationContextDetailedInformation**<br><br>2 | If **QueryActCtxW** is called with this option and the function succeeds, the returned buffer contains detailed information about the activation context. This information is in the form of the [ACTIVATION_CONTEXT_DETAILED_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-activation_context_detailed_information) structure. |
| **AssemblyDetailedInformationInActivationContext**<br><br>3 | If **QueryActCtxW** is called with this option and the function succeeds, the buffer contains information about the assembly that has the index specified in *pvSubInstance*. This information is in the form of the [ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-activation_context_assembly_detailed_information) structure. |
| **FileInformationInAssemblyOfAssemblyInActivationContext**<br><br>4 | Information about a file in one of the assemblies in Activation Context. The *pvSubInstance* parameter must point to an [ACTIVATION_CONTEXT_QUERY_INDEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-activation_context_query_index) structure. If **QueryActCtxW** is called with this option and the function succeeds, the returned buffer contains information for a file in the assembly. This information is in the form of the [ASSEMBLY_FILE_DETAILED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-assembly_file_detailed_information) structure. |
| **RunlevelInformationInActivationContext**<br><br>5 | If **QueryActCtxW** is called with this option and the function succeeds, the buffer contains information about requested run level of the activation context. This information is in the form of the [ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-activation_context_run_level_information) structure.<br><br>**Windows Server 2003 and Windows XP:** This value is not available. |
| **CompatibilityInformationInActivationContext**<br><br>6 | If **QueryActCtxW** is called with this option and the function succeeds, the buffer contains information about requested compatibility context. This information is in the form of the [ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-activation_context_compatibility_information) structure.<br><br>**Windows Server 2008 and earlier, and Windows Vista and earlier:** This value is not available. This option is available beginning with Windows Server 2008 R2 and Windows 7. |

### `pvBuffer` [out]

Pointer to a buffer that holds the returned information. This parameter is optional. If *pvBuffer* is **null**, then *cbBuffer* must be zero. If the size of the buffer pointed to by *pvBuffer* is too small,
**QueryActCtxW** returns ERROR_INSUFFICIENT_BUFFER and no data is written into the buffer. See the Remarks section for the method you can use to determine the required size of the buffer.

### `cbBuffer` [in, optional]

Size of the buffer in bytes pointed to by *pvBuffer*. This parameter is optional.

### `pcbWrittenOrRequired` [out, optional]

Number of bytes written or required. The parameter *pcbWrittenOrRequired* can only be **NULL** when *pvBuffer* is **NULL**. If *pcbWrittenOrRequired* is non-**NULL**, it is filled with the number of bytes required to store the returned buffer.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The parameter *cbBuffer* specifies the size in bytes of the buffer pointed to by *pvBuffer*. If *pvBuffer* is **NULL**, then *cbBuffer* must be 0. The parameter *pcbWrittenOrRequired* can only be **NULL** if *pvBuffer* is **NULL**. If *pcbWrittenOrRequired* is non-**NULL** on return, it is filled with the number of bytes required to store the returned information. When the information data returned is larger than the provided buffer,
**QueryActCtxW** returns ERROR_INSUFFICIENT_BUFFER and no data is written to the buffer pointed to by *pvBuffer*.

The following example shows the method of calling first with a small buffer and then recalling if the buffer is too small.

``` syntax
SIZE_T cbRequired;
PVOID pvData = NULL;
SIZE_T cbAvailable = 0;

if (!QueryActCtxW(..., pvData, cbAvailable, &cbRequired) && (GetLastError()== ERROR_INSUFFICIENT_BUFFER))
{
    // Allocate enough space to store the returned buffer, fail if too small
    if (NULL == (pvData = HeapAlloc(GetProcessHeap(), 0, cbRequired)))
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    cbAvailable = cbRequired;
    // Try again, this should succeed.
    if (QueryActCtxW(..., pvData, cbAvailable, &cbRequired))
    {
        // Use the returned data in pvData
    }
    HeapFree(GetProcessHeap(), 0, pvData);
    pvData = NULL;
}
```