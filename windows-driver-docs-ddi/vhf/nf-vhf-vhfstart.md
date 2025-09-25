# VhfStart function

## Description

The HID source driver calls this method to start the virtual HID device.

## Parameters

### `VhfHandle` [in]

A handle to a virtual HID device that your HID source driver received in the previous call to [VhfCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nf-vhf-vhfcreate).

## Return value

If the **VhfStart** call succeeds, the method returns STATUS_SUCCESS. Otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)  value.

## Remarks

Virtual HID Framework (VHF) does not invoke any callback functions implemented by the HID source driver until the source driver calls **VhfStart**. A callback can get invoked before **VhfStart** returns. After this call succeeds, the driver can call **VhfDelete**.

**VhfAsyncOperationComplete** and **VhfReadReportSubmit** may be called before **VhfStart** returns (e.g. from within an invoked callback).