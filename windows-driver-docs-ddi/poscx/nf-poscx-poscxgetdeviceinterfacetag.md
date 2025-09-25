# PosCxGetDeviceInterfaceTag function

## Description

PosCxGetDeviceInterfaceTag returns the device interface tag that is set in [PosCxOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxopen).

## Parameters

### `fileObject` [in]

 A handle to a framework file object that identifies the caller, usually acquired with [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject).

## Return value

 The device interface tag value.

## See also

[PosCxOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxopen)