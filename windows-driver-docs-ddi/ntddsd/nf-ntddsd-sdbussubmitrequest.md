# SdBusSubmitRequest function

## Description

The **SdBusSubmitRequest** routine sends a synchronous Secure Digital (SD) request to the bus driver.

## Parameters

### `InterfaceContext` [in]

Contains the context information returned by the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine in the **Context** member of the [SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85)) structure.

### `Packet`

Pointer to a caller-supplied structure of type [**SDBUS_REQUEST_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85)) that describes the request.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or the appropriate error code if the operation fails.

## Remarks

The **SdBusSubmitRequest** routine completes the request synchronously. It never returns a status code of STATUS_PENDING, but waits for the request to completed before returning.

This routine is a wrapper for the [SdBusSubmitRequestAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync) routine.

Callers of [SdBusSubmitRequestAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync) must be running at IRQL <= DISPATCH_LEVEL.

## See also

[SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85))

[SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85))

[SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface)

[SdBusSubmitRequestAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync)