# WdfGetDriver function

## Description

[Applies to KMDF and UMDF]

The **WdfGetDriver** method returns a handle to the framework driver object that represents the calling driver.

## Return value

**WdfGetDriver** returns a handle to a framework driver object, or **NULL** if the driver has not called [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate).

## See also

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)