# FSCTL_QUERY_RETRIEVAL_POINTERS control code

The **FSCTL_QUERY_RETRIEVAL_POINTERS** control code retrieves a mapping between virtual cluster numbers (VCN, offsets within the file/stream space) and logical cluster numbers (LCN, offsets within the volume space), starting at the beginning of the file up to the map size specified in *InputBuffer*.

**FSCTL_QUERY_RETRIEVAL_POINTERS** is similar to [**FSCTL_GET_RETRIEVAL_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-retrieval-pointers). However, **FSCTL_QUERY_RETRIEVAL_POINTERS** only works in kernel mode on local paging files or the system hives. The paging file is guaranteed to have a one-to-one mapping from the VCN in a volume to the LCN that refer more directly to the underlying physical storage. You must not use **FSCTL_QUERY_RETRIEVAL_POINTERS** with files other than the page file, because they might reside on volumes, such as mirrored volumes, that have one-to-many mappings of VCNs to LCNs.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) with the following parameters.

## Parameters

- **FileObject** [in]: [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the paging file or hibernation file. This parameter is required and cannot be **NULL**.

- **FileHandle** [in]: [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) only. A file handle for the paging file or hibernation file. This parameter is required and cannot be **NULL**.

- **FsControlCode** [in]: The control code for the operation. Use FSCTL_GET_RETRIEVAL_POINTERS for this operation.

- **InputBuffer** [in]: A user-supplied buffer that contains a pointer to a quadlet that specifies the map size. The map size is the number of clusters to map.

- **InputBufferLength** [in]: Length, in bytes, of the input buffer at *InputBuffer*.

- **OutputBuffer** [out]: A pointer to a buffer of paged pool memory that contains an array of elements of the following type:

```cpp
  struct {
   LONGLONG  SectorLengthInBytes;
   LONGLONG  StartingLogicalOffsetInBytes;
    } MappingPair;
  ```

 This array of quadlet pairs defines the disk runs of the file. The value of the **SectorLengthInBytes** member in the last element of the array is zero.

- **OutputBufferLength** [out]: The size, in bytes, of the buffer pointed to by the *OutputBuffer* parameter.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) and [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) both return STATUS_SUCCESS or an appropriate NTSTATUS error value.

## Remarks

This code is not supported by ReFS.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h*) |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FSCTL_GET_RETRIEVAL_POINTERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-retrieval-pointers)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))