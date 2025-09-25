# DXGKCB_MIRACAST_SEND_MESSAGE_CALLBACK callback function

## Description

Called in kernel mode when the message that was sent to the user-mode driver with a call to the DxgkCbMiracastSendMessage function has completed or has been canceled.

## Parameters

### `CallbackContext`

A pointer to the driver-supplied callback context. The operating system passes this context to the driver-supplied callback routine after the operation has completed.

### `pIoStatusBlock`

A pointer to a driver-supplied buffer to hold the returned IO_STATUS_BLOCK structure for the completed or canceled user-mode message. This structure holds the status of the I/O call and the number of bytes that the user-mode driver wrote to the output buffer.

## Remarks

This function can be called simultaneously from multiple execution threads.

The operating system guarantees that this function follows the zero level synchronization mode as defined in Threading and Synchronization Zero Level.

## See also

[DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks)

[DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback)

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)