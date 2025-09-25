# DXGK_DISPLAY_DRIVERCAPS_EXTENSION structure

## Description

The **DXGK_DISPLAY_DRIVERCAPS_EXTENSION** structure specifies driver capabilities for WDDM 2.0 and later drivers. The OS queries these capabilities at start time.

## Members

### `SecureDisplaySupport`

Indicates that the miniport supports secure display connection.

### `VirtualModeSupport`

Indicates the virtual display mode support.

### `NonSpecificPrimarySupport`

Indicates non-specific primary support.

### `HdrFP16ScanoutSupport`

HDR pixel format scanout capability support.

### `HdrARGB10ScanoutSupport`

The display is HDR capable.

### `Hdr10MetadataSupport`

The driver supports HDR10 metadata. Available starting in Windows 10 version 2004 (WDDM 2.7).

### `VirtualRefreshRateSupport`

Indicates that the driver supports virtual refresh rate. Available starting in Windows Server 2022 (WDDM 2.9).

### `SupportUsb4Targets`

Indicates that the driver supports USB4 targets. Available starting in Windows 11 (WDDM 3.0).

### `Reserved`

Reserved.

### `Value`

An alternative way to access the structure bit fields.