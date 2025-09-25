# _SERCX_ACTIVITY structure

## Description

The **SERCX_ACTIVITY** structure contains a summary of work items that are ready for the serial controller driver to process.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCxGetActivity](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetactivity) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `Transmitting`

Whether a transmit (write) operation is in progress. This member is TRUE if a transmit operation is in progress. Otherwise, it is FALSE.

### `Receiving`

Whether a receive (read) operation is in progress. This member is TRUE if a receive operation is in progress. Otherwise, it is FALSE.

## Remarks

This structure must be initialized by the [SERCX_ACTIVITY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_activity_init) function before its initial use. Thereafter, calls to the [SerCxGetActivity](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetactivity) method update the contents of this structure to indicate the work that is currently pending.

The **SERCX_ACTIVITY** structure summarizes the pending work that the serial framework extension (SerCx) assigns to the serial controller driver. This work is driven by I/O requests from clients, but an I/O request does not necessarily spawn a work item. For example, if SerCx has a sufficient amount of received data in its memory buffer to complete a pending read request, this request does not cause the **Receiving** member of the **SERCX_ACTIVITY** structure to be set to TRUE.

Typically, **SerCxGetActivity** is called from the main loop of the transmit/receive DPC function in the serial controller driver. This function calls **SerCxGetActivity**, processes a complete transmit or receive operation, and then calls **SerCxGetActivity** again to determine whether an operation of another type requires work. If more work is available, the DPC function might perform this work before it returns.

## See also

[SERCX_ACTIVITY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_activity_init)

[SerCxCompleteWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxcompletewait)

[SerCxGetActivity](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetactivity)

[SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive)

[SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit)