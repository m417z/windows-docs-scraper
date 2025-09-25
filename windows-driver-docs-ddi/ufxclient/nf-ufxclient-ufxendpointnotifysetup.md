# UfxEndpointNotifySetup function

## Description

Notifies UFX when the client driver receives a setup packet from the host.

## Parameters

### `UfxEndpoint`

A handle to a UFX device object that the driver created by calling [**UfxDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `SetupInfo` [in]

A pointer to a USB setup packet described in a **USB_DEFAULT_PIPE_SETUP_PACKET** structure (defined in Usbspec.h).

## Remarks

The following example shows how to handle setup packet completion.

```
    if (ControlContext->SetupRequested) {
        TRACE_TRANSFER("COMPLETE (Setup)", Endpoint, NULL);

        ControlContext->SetupRequested = FALSE;
        TransferContext->TransferStarted = FALSE;

        UfxEndpointNotifySetup(Endpoint, ControlContext->SetupPacket);

    }

```