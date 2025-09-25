# UMDF_VERSION_DATA structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **UMDF_VERSION_DATA** structure describes a version of the framework.

## Members

### `MajorNumber`

A number that specifies the major version of the framework.

### `MinorNumber`

A number that specifies the minor version of the framework.

### `ServiceNumber`

A number that specifies the service of the framework.

## Remarks

A UMDF driver supplies a pointer to a **UMDF_VERSION_DATA** structure to the [IWDFDriver::IsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-isversionavailable) method to describe the minimum version of the framework that the driver supports.

**Note** **Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

[Microsoft_WDF_UMDF_Version](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-umdf_version_data) is a global variable of type **UMDF_VERSION_DATA** that specifies the major version, minor version, and service number for the current release of the framework.

For example, in Windows 8, Wudfddi.h specifies:
```
UMDF_VERSION_DATA Microsoft_WDF_UMDF_Version = {1, 11,  0}
```

When you compile a driver using Wudfddi.h, [Microsoft_WDF_UMDF_Version](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-umdf_version_data) is included in the driver binary and exported using [__declspec(dllexport)](https://learn.microsoft.com/cpp/build/exporting-from-a-dll-using-declspec-dllexport).

 When the system loads your driver, the host process (WUDFHost.exe) verifies that the driver's major version matches the framework's major version and that the driver's minor version is less than or equal to the framework's minor version.

 The driver does not need to take any action to provide this version number to the framework, other than building with Wudfddi.h.

End of support:
Unavailable in UMDF 2.0 and later.

Minimum UMDF version:
1.0

Header:
Wudfddi.h (include Wudfddi.h)

## See also

[IWDFDriver::IsVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-isversionavailable)

[Microsoft_WDF_UMDF_Version](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-umdf_version_data)