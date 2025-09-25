## Description

The **DdWaitForVerticalBlank** callback function returns the vertical blank status of the device.

## Parameters

### `unnamedParam1`

Points to a [DD_WAITFORVERTICALBLANKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_waitforverticalblankdata) structure that contains the information required to obtain the vertical blank status.

## Return value

**DdWaitForVerticalBlank** returns one of the following callback codes:

## Remarks

Depending on the value of the **dwFlags** member of the DD_WAITFORVERTICALBLANKDATA structure at *lpWaitForVerticalBlank*, the driver should do the following:

* If **dwFlags** is DDWAITVB_I_TESTVB, the driver should query the current vertical blanking status. The driver should set the **bIsInVB** member of DD_WAITFORVERTICALBLANKDATA to **TRUE** if the monitor is currently in a vertical blank; otherwise the driver should set **bIsInVB** to **FALSE**.
* If **dwFlags** is DDWAITVB_BLOCKBEGIN, the driver should block and wait until a vertical blank begins. If a vertical blank is in progress when the driver begins the block, the driver should wait until the next vertical blank begins before returning.
* If **dwFlags** is DDWAITVB_BLOCKEND, the driver should block and wait until a vertical blank ends.

When the driver successfully handles the action specified in **dwFlags**, it should set DD_OK in the **ddRVal** member of DD_WAITFORVERTICALBLANKDATA and return DDHAL_DRIVER_HANDLED. The driver should return DDHAL_DRIVER_NOTHANDLED for those flags that it is incapable of handling.

**DdWaitForVerticalBlank** allows an application to synchronize itself with the vertical blanking interval (VBI).

**Note** **DdWaitForVerticalBlank** should never enter a polling loop if the monitor power state will cause the driver to hang. For example, during a monitor power-down, an application might call **WaitForVerticalBlank**. The DirectDraw runtime calls the display driver's **DdWaitForVerticalBlank** entry point, which waits for the status to change. If the monitor is powered down, this value will never change--unless the driver writer prepares for this scenario. One solution is to include a time out in the polling loop while waiting for a vertical blank. The sample Permedia2 driver is simply set to not poll at all if the monitor is powered down.

There is also an issue with the WHQL Display Compatibility Tests (DCTs). One of the DCTs for power management powers down the monitor and then polls the vertical blank status, waiting for it to change. If the driver always reports the same vertical blank status when the monitor is powered down, then the test application will hang waiting for the result to change. This was fixed in the Permedia2 sample driver by returning alternating results while the monitor is powered down. That is, the first time the driver's **DdWaitForVerticalBlank** entry point is called with the DDWAIT_I_TESTVB flag (when the monitor is powered down), it returns **FALSE**, the next time it returns **TRUE**, next time **FALSE**, etc.

## See also

[DD_WAITFORVERTICALBLANKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_waitforverticalblankdata)