# WdfDriverGetRegistryPath function

## Description

[Applies to KMDF and UMDF]

The **WdfDriverGetRegistryPath** method retrieves the path to the driver's registry key in the registry's [Services](https://learn.microsoft.com/windows-hardware/test/wpt/services) tree.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object, obtained by a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

## Return value

**WdfDriverGetRegistryPath** returns a pointer to a NULL-terminated Unicode string that represents the driver's registry path. A system bug check occurs if the *Driver* handle is invalid.

## Remarks

The registry path string that **WdfDriverGetRegistryPath** returns is obtained from the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that the driver received as input to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

For more information about the registry, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example obtains the path to a driver's registry key in the registry's **Services** tree.

```cpp
PWSTR  registryPath;

registryPath = WdfDriverGetRegistryPath(driver);
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)