## Description

An AVStream minidriver's routine is called when an activity on the pin is performed and it receives these IRPs:

- [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

- [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

## Parameters

### `Pin` [in]

Pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) that was just created.

### `Irp` [in]

Pointer to the IRP for *Pin*.

## Return value

If the routine succeeds, the operation is guaranteed to succeed. Return STATUS_SUCCESS or STATUS_PENDING.

## Remarks

| IRP | Description |
|---|---|
| [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) | Typically, this routine is used by minidrivers that want to initialize the context and resources associated with the pin. The minidriver specifies this routine's address in the **Create** member of its [**KSPIN_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure. This routine is called when a pin is created. At the point at which this routine is called, the file object has an associated context, and the KS object header has been allocated. Typically, this function will be provided by minidrivers that want to initialize the context and resources associated with the pin. The filter control mutex is held while in this function. The function will be called at IRQL = PASSIVE_LEVEL. This routine is optional. If the routine succeeds, the create operation is guaranteed to succeed. Return STATUS_SUCCESS or STATUS_PENDING. If a minidriver returns STATUS_PENDING, AVStream will not complete the [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) immediately. Before returning STATUS_PENDING, however, the minidriver must call [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending). Once the processing of the create is complete, the minidriver must set the IRP's status code and then call [KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest). |
| [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) | The minidriver specifies this routine's address in the **Close** member of its [**KSPIN_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure. At the point at which the routine is called, any registered events on the pin have been freed, but the object is otherwise intact. The filter control mutex is held while in this function. For more information about mutexes, please see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream). This routine is optional. |

## See also

[IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)