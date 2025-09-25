# IMiniportDMus::Service

## Description

 This method does not currently need to be implemented in the miniport driver. The `Service` method is currently unused.

## Remarks

`Service` was intended to be called during a deferred procedure call (DPC) and was to be executed as the result of a call of the [IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify) method. Instead, the DMus port driver sends notification to the miniport driver's input stream by calling [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage) with a **NULL** parameter value. Hence, `Service` is currently unused.

## See also

[IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage)

[IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus)

[IPortDMus::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iportdmus-notify)