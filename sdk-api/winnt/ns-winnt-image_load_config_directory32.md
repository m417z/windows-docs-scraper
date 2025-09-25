# IMAGE_LOAD_CONFIG_DIRECTORY32 structure

## Description

Contains the load configuration data of an image.

## Members

### `Size`

The size of the structure. For Windows XP, the size must be specified as 64 for x86 images.

### `TimeDateStamp`

The date and time stamp value. The value is represented in the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Universal Coordinated Time, according to the system clock. The time stamp can be printed using the C run-time (CRT) function **ctime**.

### `MajorVersion`

The major version number.

### `MinorVersion`

The minor version number.

### `GlobalFlagsClear`

The global flags that control system behavior. For more information, see Gflags.exe.

### `GlobalFlagsSet`

The global flags that control system behavior. For more information, see Gflags.exe.

### `CriticalSectionDefaultTimeout`

The critical section default time-out value.

### `DeCommitFreeBlockThreshold`

The size of the minimum block that must be freed before it is freed (de-committed), in bytes. This value is advisory.

### `DeCommitTotalFreeThreshold`

The size of the minimum total memory that must be freed in the process heap before it is freed (de-committed), in bytes. This value is advisory.

### `LockPrefixTable`

 The VA of a list of addresses where the LOCK prefix is used. These will be replaced by NOP on single-processor systems. This member is available only for x86.

### `MaximumAllocationSize`

The maximum allocation size, in bytes. This member is obsolete and is used only for debugging purposes.

### `VirtualMemoryThreshold`

The maximum block size that can be allocated from heap segments, in bytes.

### `ProcessHeapFlags`

The process heap flags. For more information, see [HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate).

### `ProcessAffinityMask`

The process affinity mask. For more information, see
[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask). This member is available only for .exe files.

### `CSDVersion`

The service pack version.

### `DependentLoadFlags`

### `EditList`

Reserved for use by the system.

### `SecurityCookie`

A pointer to a cookie that is used by Visual C++ or GS implementation.

### `SEHandlerTable`

 The VA of the sorted table of RVAs of each valid, unique handler in the image. This member is available only for x86.

### `SEHandlerCount`

The count of unique handlers in the table. This member is available only for x86.

### `GuardCFCheckFunctionPointer`

### `GuardCFDispatchFunctionPointer`

### `GuardCFFunctionTable`

### `GuardCFFunctionCount`

### `GuardFlags`

### `CodeIntegrity`

### `GuardAddressTakenIatEntryTable`

### `GuardAddressTakenIatEntryCount`

### `GuardLongJumpTargetTable`

### `GuardLongJumpTargetCount`

### `DynamicValueRelocTable`

### `CHPEMetadataPointer`

### `GuardRFFailureRoutine`

### `GuardRFFailureRoutineFunctionPointer`

### `DynamicValueRelocTableOffset`

### `DynamicValueRelocTableSection`

### `Reserved2`

### `GuardRFVerifyStackPointerFunctionPointer`

### `HotPatchTableOffset`

### `Reserved3`

### `EnclaveConfigurationPointer`

### `VolatileMetadataPointer`

#### - Reserved1

Reserved for use by the operating system.

## Remarks

If **_WIN64** is defined, then **IMAGE_LOAD_CONFIG_DIRECTORY** is defined as **IMAGE_LOAD_CONFIG_DIRECTORY64**. However, if **_WIN64** is not defined, then **IMAGE_LOAD_CONFIG_DIRECTORY** is defined as **IMAGE_LOAD_CONFIG_DIRECTORY32**.

```cpp
typedef struct {
    DWORD   Size;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   GlobalFlagsClear;
    DWORD   GlobalFlagsSet;
    DWORD   CriticalSectionDefaultTimeout;
    DWORD   DeCommitFreeBlockThreshold;
    DWORD   DeCommitTotalFreeThreshold;
    DWORD   LockPrefixTable;            // VA
    DWORD   MaximumAllocationSize;
    DWORD   VirtualMemoryThreshold;
    DWORD   ProcessHeapFlags;
    DWORD   ProcessAffinityMask;
    WORD    CSDVersion;
    WORD    Reserved1;
    DWORD   EditList;                   // VA
    DWORD   SecurityCookie;             // VA
    DWORD   SEHandlerTable;             // VA
    DWORD   SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;
```

## See also

[GetImageConfigInformation](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-getimageconfiginformation)

[GetProcessAffinityMask](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessaffinitymask)

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)

[SetImageConfigInformation](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-setimageconfiginformation)