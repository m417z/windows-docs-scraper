# WdfDriverIsVersionAvailable function

## Description

[Applies to KMDF and UMDF]

The **WdfDriverIsVersionAvailable** method returns a Boolean value that indicates whether the driver is running with a specified version of the Kernel-Mode Driver Framework library.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

### `VersionAvailableParams` [in]

A pointer to a [WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params) structure that identifies a version of the framework library.

## Return value

**WdfDriverIsVersionAvailable** returns **TRUE** if the driver is running with the version of the library that the *VersionAvailableParams* parameter specifies.

The method returns **FALSE** if the driver is not running with the specified library version or if the WDF_DRIVER_VERSION_AVAILABLE_PARAMS structure is invalid.

A system bug check occurs if the *Driver* handle is invalid.

## Remarks

For more information about library versions, see [Framework Library Versioning](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-library-versioning).

#### Examples

The following code example reports an error if it detects an unexpected library version number.

```cpp
WDF_DRIVER_VERSION_AVAILABLE_PARAMS ver;

WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT(&ver, 1, 0);
if (!WdfDriverIsVersionAvailable(
                                 driver,
                                 &ver
                                 )) {
    DbgPrint("Unexpected library version.\n");
}
```

## See also

[WDF_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_version_available_params)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfDriverRetrieveVersionString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriverretrieveversionstring)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)