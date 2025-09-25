## Description

Contains information about a deferred symbol load.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. The caller must set this member to `sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD64)`.

### `BaseOfImage`

The base virtual address where the image is loaded.

### `CheckSum`

The computed checksum of the image. This value can be zero.

### `TimeDateStamp`

The date and timestamp value. The value is represented in the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Universal Coordinated Time, according to the system clock. The timestamp can be printed using the C run-time (CRT) function **ctime**.

### `FileName`

The image name. The name may or may not contain a full path.

### `Reparse`

If this member is **TRUE**, the operation should be performed again. Otherwise, it should not.

### `hFile`

A handle to a file. This member is used with **CBA_DEFERRED_SYMBOL_LOAD_PARTIAL** and **IMAGEHLP_DEFERRED_SYMBOL_LOAD_FAILURE** callbacks.

## Remarks

This structure supersedes the **IMAGEHLP_DEFERRED_SYMBOL_LOAD** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **IMAGEHLP_DEFERRED_SYMBOL_LOAD** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_DEFERRED_SYMBOL_LOAD IMAGEHLP_DEFERRED_SYMBOL_LOAD64
#define PIMAGEHLP_DEFERRED_SYMBOL_LOAD PIMAGEHLP_DEFERRED_SYMBOL_LOAD64
#else
typedef struct _IMAGEHLP_DEFERRED_SYMBOL_LOAD {
    DWORD    SizeOfStruct;
    DWORD    BaseOfImage;
    DWORD    CheckSum;
    DWORD    TimeDateStamp;
    CHAR     FileName[MAX_PATH];
    BOOLEAN  Reparse;
    HANDLE   hFile;
} IMAGEHLP_DEFERRED_SYMBOL_LOAD, *PIMAGEHLP_DEFERRED_SYMBOL_LOAD;
#endif
```

## See also

[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback)