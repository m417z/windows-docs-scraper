# SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT structure

## Description

After Windows issues the SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT file system control for a file, it examines allocations to the file.

Once this file system control is issued for a file, the following allocations to the file will be examined to see if the given offset is being allocated. If so, the allocation's physical address will be aligned to the given **AlignmentValue** if enough free space is available at the aligned regions.

## Members

### `Flags`

The flags used for the file system control. There are two flags that can be used:

| Value | Meaning |
| ----- | ------- |
| DAX_ALLOC_ALIGNMENT_FLAG_MANDATORY | If allocation satisfying **AlignmentShift** (or at least **FallbackAlignmentShift** if specified) can't be found, then fail the file system operation (e.g. extending the file). |
| DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED | Indicates that the FallbackAlignmentShift field is present in the input structure and indicates a fallback alignment if the optimal alignment isn't available. |

### `AlignmentShift`

The block size used to align the given offset of the file. The file is allocated so that the file's physical address is aligned to this block size.

The actual alignment value is given by:

```cpp
AlignmentValue = (1 << AlignmentShift);
```

### `FileOffsetToAlign`

The file offset that should be aligned to the given *AlignmentValue*. This should be cluster aligned.

The Memory Manager supports huge page only if the file offset and the physical address are 1gb aligned.

### `FallbackAlignmentShift`

If DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED is present in **Flags**, this field specifies a fallback block size to align the given offset of the file whenever allocation satisfying AlignmentShift could not be found.

## Remarks

To reset the alignment constraint you can issue this FSCTL with an *AlignmentValue* of 1; that is, **AlignmentShift** as 0.