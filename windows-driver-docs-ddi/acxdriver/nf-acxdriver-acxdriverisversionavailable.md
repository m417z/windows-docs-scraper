## Description

The **AcxDriverIsVersionAvailable** function returns a Boolean value indicating if the specified driver version is available.

## Parameters

### `Driver`

The **WDFDRIVER** object to check for the version specified by *VersionAvailableParams*.

### `VersionAvailableParams`

Pointer to an [ACX_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_version_available_params) structure that indicates the version of the audio driver you are seeking.

## Return value

**AcxDriverIsVersionAvailable** returns a Boolean value indicating if the specified driver version is available.

## Remarks

Call the [ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_version_available_params_init) function to initialize the *VersionAvailableParams* structure before calling this function.

### Example

```cpp
WDFDRIVER                           driver;
ACX_DRIVER_VERSION_AVAILABLE_PARAMS ver;

// Code to initialize the WDFDRIVER object...

// Initialize the audio driver version available structure
ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT(&ver, 1, 0);

// Check if version 1.0 is available
if (!AcxDriverIsVersionAvailable(driver, &ver))
{
    DbgPrint("Unexpected library version.\n");
    return STATUS_REVISION_MISMATCH;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_DRIVER_VERSION_AVAILABLE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/ns-acxdriver-acx_driver_version_available_params)
- [ACX_DRIVER_VERSION_AVAILABLE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/nf-acxdriver-acx_driver_version_available_params_init)
- [acxdriver.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdriver/)