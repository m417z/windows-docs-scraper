# ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION structure

## Description

The
**ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION** structure is used by the
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `ulFlags`

This value is always 0.

### `ulEncodedAssemblyIdentityLength`

Length of the encoded assembly identity in bytes.

### `ulManifestPathType`

This value always a constant.

### `ulManifestPathLength`

Length of the assembly manifest path in bytes.

### `liManifestLastWriteTime`

The last time the manifest was written. This is in the form of a
**FILETIME** data structure.

### `ulPolicyPathType`

This value always a constant.

### `ulPolicyPathLength`

Length of the publisher policy path in bytes.

### `liPolicyLastWriteTime`

The last time the policy was written. This is in the form of a
**FILETIME** data structure.

### `ulMetadataSatelliteRosterIndex`

Metadata satellite roster index.

### `ulManifestVersionMajor`

Major version of the assembly queried by
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw). For more information, see
[Assembly Versions](https://learn.microsoft.com/windows/desktop/SbsCs/assembly-versions).

### `ulManifestVersionMinor`

Minor version of the assembly queried by
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw). For more information, see
[Assembly Versions](https://learn.microsoft.com/windows/desktop/SbsCs/assembly-versions).

### `ulPolicyVersionMajor`

Major version of any policy, if one exists.

### `ulPolicyVersionMinor`

Minor version of any policy, if one exists.

### `ulAssemblyDirectoryNameLength`

Length of the assembly directory name in bytes.

### `lpAssemblyEncodedAssemblyIdentity`

Pointer to a null-terminated string that contains a textually-encoded format of the assembly's identity.

### `lpAssemblyManifestPath`

Pointer to a null-terminated string that indicates the original path to this assembly's manifest.

### `lpAssemblyPolicyPath`

Pointer to a null-terminated string that indicates the path of whatever policy assembly was used to determine that this version of the assembly should be loaded. If this member is null, no policy was used to decide to load this version.

### `lpAssemblyDirectoryName`

Pointer to a null-terminated string that indicates the folder from which this assembly was loaded.

### `ulFileCount`

## Remarks

If
[QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) is called with the AssemblyDetailedInformationInActivationContext option, and the function succeeds, the information in the returned buffer is in the form of the
**ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION** structure.

```cpp
PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION pAssemblyInfo = NULL;
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
        pAssemblyInfo = (PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION)pvDataBuffer;
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