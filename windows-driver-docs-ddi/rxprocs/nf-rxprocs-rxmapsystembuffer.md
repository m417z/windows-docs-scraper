# RxMapSystemBuffer function

## Description

**RxMapSystemBuffer** returns the system buffer address from the IRP.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure for this request.

### `Irp` [in]

A pointer to the IRP for this request.

## Return value

**RxMapSystemBuffer** returns a mapped address pointer.

## Remarks

The **RxMapSystemBuffer** routine checks that **Irp->MdlAddress** is not **NULL** and returns the **Irp->AssociatedIrp.SystemBuffer** when this is the case.

On retail builds, **RxMapSystemBuffer** will call **MmGetSystemAddressForMdlSafe** to return the MDL from the IRP if **Irp->MdlAddress** is **NULL**. On checked builds, **RxMapSystemBuffer** causes the system to ASSERT if **Irp->MdlAddress** is **NULL**.

## See also

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxLowIoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiocompletion)

[RxLowIoGetBufferAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiogetbufferaddress)

[RxNewMapUserBuffer](https://learn.microsoft.com/windows-hardware/drivers/ifs/rxnewmapuserbuffer)