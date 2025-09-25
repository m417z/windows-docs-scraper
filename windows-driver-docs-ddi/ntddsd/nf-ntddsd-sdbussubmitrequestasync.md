# SdBusSubmitRequestAsync function

## Description

The **SdBusSubmitRequestAsync** routine sends an asynchronous Secure Digital (SD) request to the bus driver interface.

## Parameters

### `InterfaceContext` [in]

Contains the context information returned by the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine in the **Context** member of the [SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85)) structure.

### `Packet` [in]

Pointer to a caller-supplied structure of type [SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85)) that describes the request.

### `Irp` [in]

Points to a caller-supplied IRP that the SD library uses to transmit the request packet. The **SdBusSubmitRequestAsync** routine stores the packet in the next stack location of the IRP, which allows the caller to reuse IRPs created by a driver higher in the stack.

### `CompletionRoutine` [in]

Pointer to a completion routine of type [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) that **SdBusSubmitRequestAsync** registers for the IRP specified in the *Irp* parameter.

### `UserContext` [in]

Pointer to context data that the system passes to the completion routine registered for the IRP specified by the *Irp* parameter.

## Return value

Returns STATUS_SUCCESS or STATUS_PENDING if the operation succeeds, or the appropriate error message if the operation fails.

## Remarks

Callers of **SdBusSubmitRequestAsync** must be running at IRQL <= DISPATCH_LEVEL.

Callers of [SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) must be running at IRQL < DISPATCH_LEVEL.

This request is handled asynchronously and might return STATUS_PENDING.

## See also

[SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85))

[SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface)

[SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)