# RxInferFileType function

## Description

**RxInferFileType** tries to infer the file type (directory or non-directory) from a member in the RX_CONTEXT structure.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure.

## Return value

**RxInferFileType** returns the storage type implied by the open.

| Return code | Description |
| --- | --- |
| **FileTypeDirectory** | The file type is a directory. |
| **FileTypeFile** | The file type is a file. |
| **FileTypeNotYetKnown** | The file type could not be determined. <br><br>If RxInferFileType cannot determine the file type, this routine returns this value. |

## Remarks

**RxInferFileType** tries to infer the file type (directory or non-directory) from the **Create.NtCreateParameters.CreateOptions** member in the RX_CONTEXT structure.

The **RxInferFileType** routine is not called internally by RDBSS. The **RxInferFileType** routine might be used as a helper routine by a network mini-redirector driver in the **MRxCreate** routine provided by the network mini-redirector. **MRxCreate** would normally be called when an I/O request packet is received for IRP_MJ_CREATE. This IRP is normally received by RDBSS in response to a user-mode application requesting a file open or create operation. It is also possible for another kernel driver to issue such an IRP.

## See also

[MRxCreate](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxcreate)

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)