# WdfDriverRetrieveDriverDataDirectoryString function

## Description

[Applies to UMDF only]

The **WdfDriverRetrieveDriverDataDirectoryString** method returns a path to a directory on disk in which the driver can store information. The files in that directory apply to a specific framework driver object.

## Parameters

### `Driver` [_In_]

A handle to the driver's framework driver object that the driver obtained from a previous call to [**WdfDriverCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [**WdfDeviceGetDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdriver).

### `String` [_In_]

A handle to a framework string object that the driver obtained from a previous call to [**WdfStringCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate). The framework assigns the fully qualified path of the requested driver directory to the string object.

## Return value

**WdfDriverRetrieveDriverDataDirectoryString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method returns an appropriate NTSTATUS error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To achieve the same result, a KMDF driver should call [**IoGetDriverDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverdirectory) instead.

For more information about string objects, see [Using String Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects).

#### Examples

The following code example shows how to call **WdfDriverRetrieveDriverDataDirectoryString**:

```cpp
NTSTATUS status;
WDFSTRING string;

status = WdfStringCreate(
                         NULL,
                         WDF_NO_OBJECT_ATTRIBUTES,
                         &string
                         );
if (NT_SUCCESS(status)) {
    status = WdfDriverRetrieveDriverDataDirectoryString(
                         Driver,
                         string
                         );
    if (!NT_SUCCESS(status)) {
        return status;
    }
}
```

## See also

[**IoGetDriverDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverdirectory)

[_DRIVER_DIRECTORY_TYPE Enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_driver_directory_type)