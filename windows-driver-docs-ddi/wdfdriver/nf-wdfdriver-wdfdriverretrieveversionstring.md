# WdfDriverRetrieveVersionString function

## Description

[Applies to KMDF and UMDF]

The **WdfDriverRetrieveVersionString** method retrieves a Unicode string that identifies the version of the Kernel-Mode Driver Framework that the driver is running with.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

### `String` [in]

A handle to a framework string object that the driver obtained from a previous call to [WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate). The framework assigns the version string to the string object.

## Return value

**WdfDriverRetrieveVersionString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate a buffer for the Unicode string. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the *Driver* handle is invalid.

## Remarks

Your driver can call **WdfDriverRetrieveVersionString** if you want to display a string that identifies the framework library's version. The string's format might change from one version to another, so the driver must not attempt to interpret the string's format or content.

For more information about library versions, see [Framework Library Versioning](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-library-versioning).

#### Examples

The following code example creates a string object, assigns the version string to the object, and displays the string if a debugger is running.

```cpp
WDFSTRING string;
UNICODE_STRING us;

status = WdfStringCreate(
                         NULL,
                         WDF_NO_OBJECT_ATTRIBUTES,
                         &string
                         );
if (NT_SUCCESS(status)) {
    status = WdfDriverRetrieveVersionString(
                                            driver,
                                            string
                                            );
    if (NT_SUCCESS(status)) {
        WdfStringGetUnicodeString(
                                  string,
                                  &us
                                  );
        DbgPrint(
                 "WDF Version string:  %wZ\n",
                 &us
                 );
    }
    WdfObjectDelete(string);
}
```

## See also

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfDriverIsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriverisversionavailable)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)

[WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring)