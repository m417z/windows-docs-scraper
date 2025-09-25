## Description

The **COPY_INFORMATION** structure correlates read and write calls to a copy operation from [**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk).

## Members

### `SourceFileObject`

The source file object of the copy.

### `SourceFileOffset`

The file offset of the source file of the copy. This value can be compared to the destination's file offset during write to ensure the copy is complete and faithful.

## Remarks

A copy's read and write operations contain the same information in their respective IRP extensions, so correlation can be done using **COPY_INFORMATION** for all writes that have the **IopCopyInformationType** IRP extension.

If the read and write operations are correlated and the copied data is verified, the written destination file can be considered a complete and faithful copy of the source. This means trust can be passed from the source file to the destination.

Copies generally happen in chunks. To validate the entire file copy:

* Each chunk (each call to [**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk)) must have its write operation correlated to a previous read operation.

* All chunks copied together should cover the entire range of the file.

A filter can verify the correctness of the copied data with the source information provided in the IRP extension of the write as follows:

* Verify that a matching read occurred on **SourceFileObject**.
* Verify that **SourceFileOffset** matches the write operation's file offset.

See [Kernel-mode file copy and detecting copy file scenarios](https://learn.microsoft.com/windows-hardware/drivers/ifs/km-file-copy) for more information.

## See also

[**FltGetCopyInformationFromCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcopyinformationfromcallbackdata)

[**IoCheckFileObjectOpenedAsCopySource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopysource)

[**IoCheckFileObjectOpenedAsCopyDestination**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopydestination)

[**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)