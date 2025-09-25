## Description

The **IoCheckFileObjectOpenedAsCopyDestination** routine checks whether a file was previously opened with copy intent as a destination file.

## Parameters

### `FileObject` [in]

Pointer to the destination file object to check for copy intent.

## Return value

**IoCheckFileObjectOpenedAsCopyDestination** returns TRUE if the file object represents a destination file that was previously opened with copy file intent; otherwise it returns FALSE. A return value of TRUE only signals the intent at create time; it does not mean that all operations on the file object are all part of copies.

## Remarks

See [**IoCheckFileObjectOpenedAsCopySource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopysource)
for sample code that shows how to check if a file object was opened with copy intent.

See [Kernel-mode file copy and detecting copy file scenarios](https://learn.microsoft.com/windows-hardware/drivers/ifs/km-file-copy) for more information.

## See also

[**EXTENDED_CREATE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-extended_create_information)

[**IoCheckFileObjectOpenedAsCopySource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopysource)

[**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)