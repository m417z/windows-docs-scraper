# RxNewMapUserBuffer function

**RxNewMapUserBuffer** returns the user buffer address used for low I/O.

## Parameters

*RxContext* \[in\]
A pointer to the RX\_CONTEXT structure for this request.

## Return value

**RxNewMapUserBuffer** returns a mapped address pointer on success or **NULL** on failure.

## Remarks

If an MDL exists, then the assumption is that the MDL describes the user buffer, and the system address for the MDL is returned by **RxNewMapUserBuffer**. Otherwise, the user buffer is returned directly by **RxNewMapUserBuffer**.

The **RxNewMapUserBuffer** routine checks if the **CurrentIrp**->**MdlAddress** member of the *RxContext* variable is **NULL** and returns the **CurrentIrp**->**UserBuffer** member of the *RxContext* variable when this is the case. If the **CurrentIrp**->**MdlAddress** member is not **NULL**, then **RxNewMapUserBuffer** will call [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe) to return the MDL from the IRP.

Note that the **RxNewMapUserBuffer** routine is only available on Windows XP and Windows 2000.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | The RxNewMapUserBuffer routine is only available on Windows XP and Windows 2000. |
| Header | Rxprocs.h (include Rxcontx.h or Rxprocs.h) |
| IRQL | <= APC_LEVEL |

## See also

[**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[**RxLowIoCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiocompletion)

[**RxLowIoGetBufferAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/lowio/nf-lowio-rxlowiogetbufferaddress)

[**RxMapSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxmapsystembuffer)

[**RX\_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

