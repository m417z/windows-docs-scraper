## Description

An AVStream minidriver's *AVStrMiniFilterCreate* routine is called when a filter receives an IRP.

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

## Parameters

### `Filter` [in]

Pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter).

### `Irp` [in]

Pointer to the IRP for *Filter*.

## Return value

If the routine succeeds, return STATUS_SUCCESS or the error code.

## Remarks

| IRP | Description |
|---|---|
| [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) | Typically, this routine is used by minidrivers that want to initialize the context and resources associated with the filter. The minidriver specifies this routine's address in the **Create** member of its [**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure. At the point at which the routine is called, the file object has an associated context, and the KS object header has been allocated. This routine is called at IRQL = PASSIVE_LEVEL with the device mutex held. If the routine succeeds, the create operation is guaranteed to succeed. Return STATUS_SUCCESS or the error code that was returned from the attempt to create the filter. STATUS_PENDING is also a legal return code. If a minidriver returns STATUS_PENDING, AVStream will not complete the [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) immediately. Before returning STATUS_PENDING, the minidriver must call [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending). When the processing of the create is complete, the minidriver must set the IRP's status code and then call [KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest). This routine is optional. |
| [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) | The minidriver specifies this routine's address in the **Close** member of its [**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure. At the point at which the routine is called, any registered events on the filter have been freed, but the object is otherwise intact. This routine is called at IRQL = PASSIVE_LEVEL with the device mutex held. For more information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream). This routine is optional. Return STATUS_SUCCESS or STATUS_PENDING. If a minidriver returns STATUS_PENDING, AVStream will not complete the [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) immediately. Before returning STATUS_PENDING, however, the minidriver must call [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending). Once the processing of the close is complete, the minidriver must set the IRP's status code and then call [KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest). |

## See also

[IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending)

**[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)**
[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)