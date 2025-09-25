# UFX_PROPRIETARY_CHARGER_DETECT callback function

## Description

The filter driver's implementation to detect if a charger is attached and get details about the charger.

## Parameters

### `Context` [in]

 A pointer to a driver-defined context.

### `DetectedCharger` [out]

A pointer to a [UFX_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxproprietarycharger/ns-ufxproprietarycharger-_ufx_proprietary_charger) structure that the driver fills with charger information.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

To support handling of proprietary chargers, the USB lower filter driver must publish support. During the publishing process, the driver also registers its implementation of this callback function. For more information, see [USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85)).

In this callback function, the driver assigns the charger a GUID and sets the minimum required Dx state when the device is connected for charging.

#### Examples

```
NTSTATUS
UsbLowerFilter_ProprietaryChargerDetect(
    __in PVOID Context,
    __out PUFX_PROPRIETARY_CHARGER DetectedCharger
    )
{
    NTSTATUS Status = STATUS_SUCCESS;

    PPDCP_CONTEXT PdcpContext = NULL;

    PAGED_CODE();

    PdcpContext = DeviceGetUsbLowerFilterContext((WDFDEVICE)Context);

    // Clear our event
     KeClearEvent(&PdcpContext>AbortOperation);

    // Wait for a while
     Timeout.QuadPart = WDF_REL_TIMEOUT_IN_MS(PdcpContext>DetectionDelayInms);

    Status = KeWaitForSingleObject(
        &PdcpContext>AbortOperation,
        Executive,
        KernelMode,
        FALSE,
        &Timeout);

    switch (Status)
    {
    case STATUS_SUCCESS:

        // The abort event was set. Abort.

        Status = STATUS_REQUEST_ABORTED;
        break;

    case STATUS_TIMEOUT:

        // Timed out, detection has completed successfully.
        // Check if we want to fail this.

        if (PdcpContext>RejectNextRequest)
        {
            PdcpContext->RejectNextRequest = FALSE;
            Status = STATUS_UNSUCCESSFUL;
        }
        else if (!PdcpContext->PdcpChargerAttached)
        {
            Status = STATUS_NOT_FOUND;
        }
        else
        {
            Status = STATUS_SUCCESS;
        }
        break;

    default:
        break;
    }

    if (NT_SUCCESS(Status))
    {
        PdcpContext->PdcpChargerDetected = TRUE;
        DetectedCharger->ChargerId = GUID_USBFN_PROPRIETARY_CHARGER;
        DetectedCharger->DxState = PowerDeviceD2;
    }

    return Status;
}
```

## See also

[USB filter driver for supporting proprietary chargers](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188012(v=vs.85))