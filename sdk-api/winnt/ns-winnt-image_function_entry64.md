# IMAGE_FUNCTION_ENTRY64 structure

## Description

Represents an entry in the function table.

## Members

### `StartingAddress`

The image address of the start of the function.

### `EndingAddress`

The image address of the end of the function.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.EndOfPrologue`

The image address of the end of the prologue code.

### `DUMMYUNIONNAME.UnwindInfoAddress`

## Remarks

The following definition exists for 64-bit support.

```cpp
typedef struct _IMAGE_FUNCTION_ENTRY64 {
    ULONGLONG   StartingAddress;
    ULONGLONG   EndingAddress;
    union {
        ULONGLONG   EndOfPrologue;
        ULONGLONG   UnwindInfoAddress;
    };
} IMAGE_FUNCTION_ENTRY64, *PIMAGE_FUNCTION_ENTRY64;
```

## See also

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)

[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe)