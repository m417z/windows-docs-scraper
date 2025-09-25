# ECP_OPEN_PARAMETERS structure

## Description

The **ECP_OPEN_PARAMETERS** structure contains the extra create parameters (ECP) context that allows a caller to specify the purpose of opening of a file without interfering with existing handles and/or opportunistic locks (oplocks) on the file.

## Members

### `Size`

Specifies the size of this context structure, in bytes.

### `Reserved`

Reserved for future use. This must be initialized to 0.

### `Flags`

Flags that specify the parameters or purpose for opening a file. *Flags* can be any combination of the following values:

| Value | Description |
| ----- | ----------- |
| ECP_OPEN_PARAMETERS_FLAG_OPEN_FOR_READ (0x0001) | Opening file to read it. |
| ECP_OPEN_PARAMETERS_FLAG_OPEN_FOR_WRITE (0x0002) | Opening file to write to it. |
| ECP_OPEN_PARAMETERS_FLAG_OPEN_FOR_DELETE (0x0004) | Opening file to delete it. |
| ECP_OPEN_PARAMETERS_FLAG_IGNORE_DIR_CASE_SENSITIVITY (0x0008) | Forces a case-insensitive lookup for this file open, even under a case-sensitive directory. Available starting with Windows 10, version 2004. |
| ECP_OPEN_PARAMETERS_FLAG_FAIL_ON_CASE_SENSITIVE_DIR ( 0x0010) | Fails the file open or create request if the path has any case sensitive directories. Available starting with Windows 10, version 2004. |

## Remarks

The ECP_OPEN_PARAMETERS_FLAG_OPEN_FOR_READ and ECP_OPEN_PARAMETERS_FLAG_OPEN_FOR_WRITE flags allow read/write access to encrypted files without having to actually open such files for read/write access. These ECP flags allow a kernel-mode component to open for metadata-only access, thus not interfering with other access while still getting the encryption context setup in order to do read/writes. A filter can set these flags to avoid conflicts with locking. Setting up the encryption state for read/write operations is expensive and are not typically done when files aren't opened for read/write access.

The system-defined GUID_ECP_OPEN_PARAMETERS value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.

## See also

[**FltAllocateExtraCreateParameterList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[**FltCreateFileEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)