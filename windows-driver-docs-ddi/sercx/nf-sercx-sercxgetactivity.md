# SerCxGetActivity function

## Description

The **SerCxGetActivity** method retrieves the status of pending work for the serial controller driver.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Activity` [in, out]

A pointer to a caller-allocated [SERCX_ACTIVITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx_activity) structure. The caller must have previously called the [SERCX_ACTIVITY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_activity_init) function to initialize this structure before its initial use. Thereafter, each **SerCxGetActivity** call updates the contents of this structure to track the work items that are ready to be processed by the controller driver.

## Remarks

The serial controller driver calls this method to receive a summary of processing work that it needs to perform on behalf of the serial framework extension (SerCx). Typically, **SerCxGetActivity** is called by the transmit/receive DPC routine in the controller driver.

The *Activity* parameter points to a **SERCX_ACTIVITY** structure that describes pending work for the controller driver. The pending work that SerCx assigns to the controller driver is driven by I/O requests from clients, but an I/O request does not necessarily spawn a work item. For example, if SerCx has a sufficient amount of received data in its memory buffer to complete a pending read request, this request does not cause the **Receiving** member of the **SERCX_ACTIVITY** structure to be set to TRUE.

To cycle through pending work items, the transmit/receive DPC routine calls **SerCxGetActivity**, processes a complete transmit or receive operation, and then calls **SerCxGetActivity** again to determine whether another operation of a different type requires work. If another operation requires work, this work might begin during the same callback but must stop if the return value from a call to **SerCxProgressReceive** or **SerCxProgressTransmit** directs the DPC routine to reschedule itself to run at a later time.

A lock protects the **SERCX_ACTIVITY** structure that is updated by the **SerCxGetActivity** call. During the call, this lock is acquired by event handlers in SerCx to update the summary of work that is currently pending for the controller driver.

## See also

[SERCX_ACTIVITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx_activity)

[SERCX_ACTIVITY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_activity_init)

[SerCxCompleteWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxcompletewait)

[SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive)

[SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit)