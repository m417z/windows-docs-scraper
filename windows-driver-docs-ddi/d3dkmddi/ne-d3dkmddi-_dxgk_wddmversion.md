# DXGK_WDDMVERSION enumeration

## Description

The **DXGK_WDDMVERSION** enumeration identifies the Windows Display Driver Model (WDDM) version. It is reserved for system use. Except for the case noted below, do not use it in your driver.

## Constants

### `DXGKDDI_WDDMv1`

Reserved for system use. NOTE: If a driver does not support Windows 7 features (DXGKDDI_INTERFACE_VERSION < DXGKDDI_INTERFACE_VERSION_WIN7), and you want to compile the driver with the Windows 7 WDK (Version 7600), set the **WDDMVersion** member of the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure to DXGKDDI_WDDMv1.

### `DXGKDDI_WDDMv1_2`

Reserved for system use. Supported beginning with Windows 8.

### `DXGKDDI_WDDMv1_3`

WDDM version for Windows 8.1.

### `DXGKDDI_WDDMv2`

WDDM version for Windows 10, version 1507.

### `DXGKDDI_WDDMv2_1`

WDDM version for Windows 10, version 1607.

### `DXGKDDI_WDDMv2_1_5`

### `DXGKDDI_WDDMv2_1_6`

### `DXGKDDI_WDDMv2_2`

WDDM version for Windows 10, version 1703.

### `DXGKDDI_WDDMv2_3`

WDDM version for Windows 10, version 1709.

### `DXGKDDI_WDDMv2_4`

WDDM version for Windows 10, version 1803.

### `DXGKDDI_WDDMv2_5`

WDDM version for Windows 10, version 1809.

### `DXGKDDI_WDDMv2_6`

WDDM version for Windows 10, version 1903.

### `DXGKDDI_WDDMv2_7`

WDDM version for Windows 10, version 2004.

### `DXGKDDI_WDDMv2_8`

WDDM version for Windows 10, Insider Preview Manganese.

### `DXGKDDI_WDDMv2_9`

WDDM version for Windows Server 2022.

### `DXGKDDI_WDDMv3_0`

WDDM version for Windows 11.

### `DXGKDDI_WDDMv3_1`

WDDM version for Windows 11, version 22H2.

### `DXGKDDI_WDDMv3_2`

WDDM version for Windows 11, version 24H2.

### `DXGKDDI_WDDM_LATEST`

The latest version of WDDM. **DXGK_WDDMVERSION** cannot be greater than **DXGKDDI_WDDM_LATEST**.

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGK_WDDMDEVICECAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_wddmdevicecaps)