# _FILE_DISPOSITION_INFORMATION_EX structure

## Description

The **FILE_DISPOSITION_INFORMATION_EX** structure is used as an argument to the [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetinformationfile) routine and indicates how the operating system should delete a file.

## Members

### `Flags`

Specifies what actions the system should take with a specific file while deleting.

| Flag Name | Value | Meaning |
|--|--|--|
| FILE_DISPOSITION_DO_NOT_DELETE | 0x00000000 | Specifies the system should not delete a file. |
| FILE_DISPOSITION_DELETE | 0x00000001 | Specifies the system should delete a file. |
| FILE_DISPOSITION_POSIX_SEMANTICS | 0x00000002 | Specifies the system should perform a POSIX-style delete. See more info in Remarks. |
| FILE_DISPOSITION_FORCE_IMAGE_SECTION_CHECK | 0x00000004 | Specifies the system should force an image section check. |
| FILE_DISPOSITION_ON_CLOSE | 0x00000008 | Specifies if the system sets or clears the on-close state. |
| FILE_DISPOSITION_IGNORE_READONLY_ATTRIBUTE | 0x00000010 | Allows read-only files to be deleted. |

## Remarks

The caller must have DELETE access to a given file to call ZwSetInformationFile with **FILE_DISPOSITION_DELETE**.

When **FILE_DISPOSITION_POSIX_SEMANTICS** is not set, a file marked for deletion is not actually deleted until all open handles for the file have been closed and the link count for the file is zero. When **FILE_DISPOSITION_POSIX_SEMANTICS** is set, the link is removed from the visible namespace as soon as the POSIX delete handle has been closed, but the file's data streams remain accessible by other existing handles until the last handle has been closed. That is, applications that already had the file open can still use their handle to read/write even though the name they used to open it is gone and the file's link count may have reached zero.

If the file is being deleted at user request, using POSIX semantics allows the system to delete the file as requested, but also allows any process with an open handle to continue to access the file's data as long as the handle is open.

A return value of STATUS_CANNOT_DELETE indicates that either the file is read-only, or there is an existing mapped view to the file.

## See also

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwclose)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetinformationfile)