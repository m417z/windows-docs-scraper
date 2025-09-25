# IWDTFSystemAction2::PowerTracingEnd

## Description

This method ends a power trace session. Any power state events that occurred between the last [PowerTracingStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nf-wdtfsystemaction-iwdtfsystemaction2-powertracingstart) or [PowerTracingStartByFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nf-wdtfsystemaction-iwdtfsystemaction2-powertracingstartbyfile) method and this
end method will be captured in the associated trace message (.etl) log file. In addition, the related namespace and fields for the system and any applicable devices
can be queried.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)