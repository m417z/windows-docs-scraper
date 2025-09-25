# DXGKCB_MIRACAST_SEND_MESSAGE callback function

## Description

Sends an asynchronous message to the user-mode display driver.

## Parameters

### `MiracastHandle` [in]

A driver-supplied handle to the Miracast display device. This handle was originally passed in the **MiracastHandle** member of the [DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks) structure in a call to the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function.

### `InputBufferSize` [in]

The size, in bytes, of the input buffer pointed to by *pInputBuffer*.

### `pInputBuffer` [in]

A pointer to the input buffer. *InputBufferSize* specifies the size of the buffer.

See Remarks for more info about the input buffer.

### `OutputBufferSize` [in]

The size, in bytes, of the output buffer pointed to by *pOutputBuffer*.

### `pOutputBuffer` [out]

A pointer to the output buffer. *OutBufferSize* specifies the size of the buffer.

See Remarks for more info about the output buffer.

### `pCallback` [in, optional]

An optional pointer, supplied by the display miniport driver, to the [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback) callback function.

If the display miniport driver supplies the pointer to [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback), then after the user-mode driver handles the message, the operating system sends a message to the user-mode driver asynchronously by calling **DxgkCbMiracastSendMessageCallback**.

See Return value and Remarks sections for more about calls to [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback).

### `pCallbackContext` [in, optional]

An optional driver-supplied pointer to the driver-supplied callback context. The operating system passes this context to the driver-supplied callback routine after the operation has completed.

## Return value

Returns **STATUS_PENDING** if it successfully delivers the message. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

If the display miniport driver needs to know the status of message handling in user mode, it should supply the [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback) function in the *pCallback* parameter and check the return status in that function's *pIoStatusBlock* parameter.

## Remarks

If the display miniport driver supplies the *pInputBuffer* and *pOutputBuffer* buffers, it is the driver’s responsibility to hold these two buffers until the [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback) function is called. Otherwise, a random memory corruption issue can be created.

If the driver supplies the [DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback) in the *pCallback* parameter, it's possible that **DxgkCbMiracastSendMessageCallback** will return before **DxgkCbMiracastSendMessage** returns.

### Example calling sequence

Here's example code that shows how to use this function:

```cpp
typedef struct _CALLBACK_CONTEXT
{
    UCHAR InputBuffer[INPUT_BUFFER_SIZE];
    UCHAR OutputBuffer[OUTPUT_BUFFER_SIZE];
} CALLBACK_CONTEXT, *PCALLBACK_CONTEXT;

...

_IRQL_requires_(PASSIVE_LEVEL)
VOID
DriverCallbackFunction(
    _In_ PVOID Context,
    _In_ PIO_STATUS_BLOCK pIoStatusBlock
    )
{
    PCALLBACK_CONTEXT CallbackContex = (PCALLBACK_CONTEXT)Context;

    ExFreePool(CallbackContex);
}

...

    CallbackContex = (PCALLBACK_CONTEXT)ExAllocatePoolWithTag(
                            PagedPool,
                            sizeof(CALLBACK_CONTEXT),
                            DRIVER_TAG);

    if (CallbackContex == NULL)
    {
        return STATUS_NO_MEMORY;
    }

    RtlZeroMemory(CallbackContex, sizeof(CALLBACK_CONTEXT));

    CallbackContex->InputBuffer[0] = 0xaa;
    CallbackContex->InputBuffer[1] = 0x55;

    Status =
      pDeviceContext->MiracastCallbacks.DxgkCbMiracastSendMessage(
          pDeviceContext->MiracastCallbacks.MiracastHandle,
          sizeof(CallbackContex->InputBuffer),
          CallbackContex->InputBuffer,
          sizeof(CallbackContex->OutputBuffer),
          CallbackContext->OutputBuffer,
          &DriverCallbackFunction,
          CallbackContex);

```

## See also

[DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks)

[DxgkCbMiracastSendMessageCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message_callback)

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)