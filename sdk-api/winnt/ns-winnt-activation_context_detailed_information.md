# ACTIVATION_CONTEXT_DETAILED_INFORMATION structure

## Description

The
**ACTIVATION_CONTEXT_DETAILED_INFORMATION** structure is used by the
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `dwFlags`

This value is always 0.

### `ulFormatVersion`

This value specifies the format of the returned information. On WindowsÂ XP and WindowsÂ Server 2003 this member is always 1.

### `ulAssemblyCount`

Number of assemblies in the activation context.

### `ulRootManifestPathType`

Specifies the kind of path from which this assembly's manifest was loaded.

This member is always one of the following constants:

### `ulRootManifestPathChars`

Number of characters in the manifest path.

### `ulRootConfigurationPathType`

Specifies the kind of path from which this assembly's application configuration manifest was loaded.

This member is always one of the following constants:

### `ulRootConfigurationPathChars`

Number of characters in any application configuration file path.

### `ulAppDirPathType`

Specifies the kind of path from which this application manifest was loaded.

This member is always one of the following constants:

### `ulAppDirPathChars`

Number of characters in the application directory.

### `lpRootManifestPath`

Path of the application manifest.

### `lpRootConfigurationPath`

Path of the configuration file.

### `lpAppDirPath`

Path of the application directory.

## Remarks

If
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) is called with the ActivationContextDetailedInformation option, and the function succeeds, the information in the returned buffer is in the form of the
**ACTIVATION_CONTEXT_DETAILED_INFORMATION** structure. The following is an example of a structure used to hold detailed information about the activation context and a call from
**QueryActCtxW**.

```cpp
PACTIVATION_CONTEXT_DETAILED_INFORMATION pAssemblyInfo = NULL;
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
        AssemblyDetailedInformationInActivationContext,
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
            AssemblyDetailedInformationInActivationContext,
            pvDataBuffer,
            cbAvailable,
            &cbRequired);

    }

    if (fSuccess) {
        // Now that we've found the assembly info, cast our target buffer back to
        // the assembly info pointer.  Use pAssemblyInfo->lpFileName
        pAssemblyInfo = (PACTIVATION_CONTEXT_DETAILED_INFORMATION)pvDataBuffer;
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