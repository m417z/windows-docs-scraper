# ASSEMBLY_FILE_DETAILED_INFORMATION structure

## Description

The
**ASSEMBLY_FILE_DETAILED_INFORMATION** structure is used by the
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `ulFlags`

This value is always 0.

### `ulFilenameLength`

Length in bytes of the file name pointed to by **lpFileName**. The count does not include the terminating null character.

### `ulPathLength`

Length in bytes of the path string pointed to by **lpFilePath** The count does not include the terminating null character.

### `lpFileName`

Null-terminated string that specifies the name of the file.

### `lpFilePath`

Null-terminated string that specifies the path to the file named in **lpFileName**.

## Remarks

If
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) is called with the FileInformationInAssemblyOfAssemblyInActivationContext option, and the function succeeds, the information in the returned buffer is in form of the
**ASSEMBLY_FILE_DETAILED_INFORMATION** structure. The following is an example of a structure used to hold detailed information about the activation context and a call from
**QueryActCtxW**.

```cpp
PASSEMBLY_FILE_DETAILED_INFORMATION pAssemblyInfo = NULL;
ACTIVATION_CONTEXT_QUERY_INDEX QueryIndex;
BOOL fSuccess = FALSE;
SIZE_T cbRequired;
HANDLE hActCtx = INVALID_HANDLE_VALUE;
BYTE bTemporaryBuffer[512];
PVOID pvDataBuffer = (PVOID)bTemporaryBuffer;
SIZE_T cbAvailable = sizeof(bTemporaryBuffer);

// Request the first file in the root assembly
QueryIndex.ulAssemblyIndex = 1;
QueryIndex.ulFileIndexInAssembly = 0;

if (GetCurrentActCtx(&hActCtx)) {

    // Attempt to use our stack-based buffer first - if that's not large
    // enough, allocate from the heap and try again.
    fSuccess = QueryActCtxW(
        0,
        hActCtx,
        (PVOID)&QueryIndex,
        FileInformationInAssemblyOfAssemblyInActivationContext,
        pvDataBuffer,
        cbAvailable,
        &cbRequired);

    // Failed, because the buffer was too small.
    if (!fSuccess && (GetLastError() == ERROR_INSUFFICIENT_BUFFER)) {

        // Allocate what we need from the heap - fail if there isn't enough
        // memory to do so.
        pvDataBuffer = HeapAlloc(GetProcessHeap(), 0, cbRequired);
        if (pvDataBuffer == NULL) {
            fSuccess = FALSE;
            goto DoneQuerying;
        }
        cbAvailable = cbRequired;

        // If this fails again, exit out.
        fSuccess = QueryActCtxW(
            0,
            hActCtx,
            (PVOID)&QueryIndex,
            FileInformationInAssemblyOfAssemblyInActivationContext,
            pvDataBuffer,
            cbAvailable,
            &cbRequired);

    }

    if (fSuccess) {
        // Now that we've found the assembly info, cast our target buffer back to
        // the assembly info pointer.  Use pAssemblyInfo->lpFileName
        pAssemblyInfo = (PASSEMBLY_FILE_DETAILED_INFORMATION)pvDataBuffer;
    }
}

DoneQuerying:
    if (hActCtx != INVALID_HANDLE_VALUE)
        ReleaseActCtx(hActCtx);

    if (pvDataBuffer && (pvDataBuffer != bTemporaryBuffer)) {
        HeapFree(GetProcessHeap(), 0, pvDataBuffer);
        pvDataBuffer = 0;
    }

```