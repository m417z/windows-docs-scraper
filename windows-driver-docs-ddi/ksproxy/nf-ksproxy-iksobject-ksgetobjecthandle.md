# IKsObject::KsGetObjectHandle

## Description

The **KsGetObjectHandle** method retrieves a file handle to a KS object.

## Return value

Returns a file handle to a KS object if successful; otherwise, returns null.

## Remarks

Applications can use the handle that **KsGetObjectHandle** returns to send control-code requests to the driver that handles the KS object.

## See also

[KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol)