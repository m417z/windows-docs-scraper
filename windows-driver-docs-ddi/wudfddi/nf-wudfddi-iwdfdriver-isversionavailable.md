# IWDFDriver::IsVersionAvailable

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IsVersionAvailable** method determines whether the specified version of the framework is available.

## Parameters

### `pMinimumVersion` [in]

A pointer to a [UMDF_VERSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-umdf_version_data) structure that describes the minimum version of the framework that the driver supports.

## Return value

**IsVersionAvailable** returns a BOOL value that indicates whether the given version of the framework is available. **TRUE** indicates the version of the framework is available. **FALSE** indicates the version of the framework is not available.

## See also

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)

[UMDF_VERSION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-umdf_version_data)