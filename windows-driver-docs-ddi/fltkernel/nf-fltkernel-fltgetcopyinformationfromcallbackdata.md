## Description

The **FltGetCopyInformationFromCallbackData** routine retrieves copy information from the callback data, if present. The copy information is in the IRP extension for read/write calls coming from [**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk).

## Parameters

### `Data` [in]

Pointer to a [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that holds the callback data.

### `CopyInformation` [out]

Pointer to a [**COPY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-copy_information) structure into which the copy information will be written.

## Return value

**FltGetCopyInformationFromCallbackData** returns STATUS_SUCCESS upon success, or an error code such as the following.

| Error code | Meaning |
| ---------- | ------- |
| STATUS_INVALID_PARAMETER | The callback data is not for an IRP operation. |
| STATUS_NOT_FOUND | The copy information IRP extension was not set on the IRP. |

## Remarks

Any trusted read or write operations from [**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk) will have the following:

* The IRP's requestor mode set to **KernelMode**.
* An IRP extension with an **IopCopyInformationType** type and [information about the copy operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-copy_information).

Filters do not have access to IRP extensions directly, but can check for the presence of the copy extension and get copy information by calling **FltGetCopyInformationFromCallbackData**.

See [Kernel-mode file copy and detecting copy file scenarios](https://learn.microsoft.com/windows-hardware/drivers/ifs/km-file-copy) for more information.

## See also

[**COPY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-copy_information)

[**IoCheckFileObjectOpenedAsCopyDestination**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopydestination)

[**IoCheckFileObjectOpenedAsCopySource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopysource)

[**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)