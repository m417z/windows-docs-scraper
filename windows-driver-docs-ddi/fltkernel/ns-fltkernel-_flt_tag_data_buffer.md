# _FLT_TAG_DATA_BUFFER structure

## Description

The FLT_TAG_DATA_BUFFER structure contains information about a reparse point tag.

## Members

### `FileTag`

Tag that uniquely identifies the reparse point. Can be one of the Microsoft-defined **IO_REPARSE_TAG_*XXX*** values defined in *ntifs.h*, or an ISV-defined value.

### `TagDataLength`

Size, in bytes, of the reparse data pointed to by the **DataBuffer** member.

### `UnparsedNameLength`

Length, in bytes, of the unparsed portion of the file name pointed to by the **FileName** member of the associated file object. For more information about the **FileName** member, see [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object).

### `SymbolicLinkReparseBuffer`

When **FileTag** is IO_REPARSE_TAG_SYMLINK, you can use this structure to interpret the payload.

### `SymbolicLinkReparseBuffer.SubstituteNameOffset`

Offset, in bytes, of the substitute name string in the **PathBuffer** array. Note that this offset must be divided by **sizeof**(WCHAR) to get the array index.

### `SymbolicLinkReparseBuffer.SubstituteNameLength`

Length, in bytes, of the substitute name string. If this string is NULL_terminated, **SubstituteNameLength** does not include space for the UNICODE_NULL terminator.

### `SymbolicLinkReparseBuffer.PrintNameOffset`

Offset, in bytes, of the print name string in the **PathBuffer** array. Note that this offset must be divided by **sizeof**(WCHAR) to get the array index.

### `SymbolicLinkReparseBuffer.PrintNameLength`

Length, in bytes, of the print name string. If this string is NULL_terminated, **PrintNameLength** does not include space for the UNICODE_NULL terminator.

### `SymbolicLinkReparseBuffer.Flags`

Indicates whether the symbolic link is absolute or relative. If **Flags** contains SYMLINK_FLAG_RELATIVE, the symbolic link contained in **PathBuffer** (at offset **SubstituteNameOffset**) is processed as a relative link; otherwise, it is processed as an absolute link.

### `SymbolicLinkReparseBuffer.PathBuffer`

First character of the path string. This character is followed in memory by the remainder of the string. The path string contains the substitute name string and print name string. The substitute name and print name strings can appear in any order in the PathBuffer. To locate the substitute name and print name strings in the PathBuffer, use the **SubstituteNameOffset**, **SubstituteNameLength**, **PrintNameOffset**, and **PrintNameLength** members.

### `MountPointReparseBuffer`

When **FileTag** is IO_REPARSE_TAG_MOUNT_POINT, you can use this structure to interpret the payload.

### `MountPointReparseBuffer.SubstituteNameOffset`

Offset, in bytes, of the substitute name string in the **PathBuffer** array. Note that this offset must be divided by **sizeof**(WCHAR) to get the array index.

### `MountPointReparseBuffer.SubstituteNameLength`

Length, in bytes, of the substitute name string. If this string is NULL_terminated, **SubstituteNameLength** does not include space for the UNICODE_NULL terminator.

### `MountPointReparseBuffer.PrintNameOffset`

Offset, in bytes, of the print name string in the **PathBuffer** array. Note that this offset must be divided by **sizeof**(WCHAR) to get the array index.

### `MountPointReparseBuffer.PrintNameLength`

Length, in bytes, of the print name string. If this string is NULL_terminated, **PrintNameLength** does not include space for the UNICODE_NULL terminator.

### `MountPointReparseBuffer.PathBuffer`

First character of the path string. This character is followed in memory by the remainder of the string. The path string contains the substitute name string and print name string. The substitute name and print name strings can appear in any order in the PathBuffer. To locate the substitute name and print name strings in the PathBuffer, use the **SubstituteNameOffset**, **SubstituteNameLength**, **PrintNameOffset**, and **PrintNameLength** members.

### `GenericReparseBuffer`

You can use this structure to interpret the payload for any Microsoft-defined **IO_REPARSE_TAG_*XXX*** tag.

### `GenericReparseBuffer.DataBuffer`

Pointer to a buffer that contains user-defined data for the reparse point.

### `GenericGUIDReparseBuffer`

You can use this structure to interpret the payload for any **IO_REPARSE_TAG_*XXX*** tag.

### `GenericGUIDReparseBuffer.TagGuid`

Globally unique identifier (GUID) that identifies the type of reparse point. If **FileTag** is not a Microsoft tag, this member cannot be **NULL**.

### `GenericGUIDReparseBuffer.DataBuffer`

Pointer to a buffer that contains user-defined data for the reparse point.

## Remarks

A minifilter can use the FLT_TAG_DATA_BUFFER structure to store information about a reparse point tag.

From the union, you can use the **GenericGUIDReparseBuffer** structure to interpret the payload for any **IO_REPARSE_TAG_*XXX*** tag, or optionally use one of the other structures within the union as follows:

* Use the **GenericReparseBuffer** structure for any Microsoft-defined **IO_REPARSE_TAG_*XXX*** tag.

* Use the **SymbolicLinkReparseBuffer** structure when **FileTag** is IO_REPARSE_TAG_SYMLINK.

* Use the **MountPointReparseBuffer** structure when **FileTag** is IO_REPARSE_TAG_MOUNT_POINT.

A pointer to an FLT_TAG_DATA_BUFFER structure that contains reparse point tag data for an operation is stored in the **TagData** member of the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure for the operation.

The FLT_TAG_DATA_BUFFER_HEADER_SIZE macro returns the size of the fixed portion of the FLT_TAG_DATA_BUFFER structure.

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[FltTagFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfileex)

[FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)