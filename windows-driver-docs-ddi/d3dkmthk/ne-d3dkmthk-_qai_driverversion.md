# QAI_DRIVERVERSION enumeration

## Description

A **QAI_DRIVERVERSION** (**D3DKMT_DRIVERVERSION**) enumeration value identifies the WDDM version that the display miniport driver (KMD) supports.

## Constants

### `KMT_DRIVERVERSION_WDDM_1_0:1000`

KMD supports WDDM 1.0 (the Windows Vista display driver model without Windows 7 features).

### `KMT_DRIVERVERSION_WDDM_1_1_PRERELEASE:1102`

KMD supports the Windows Vista display driver model with prereleased Windows 7 features.

### `KMT_DRIVERVERSION_WDDM_1_1:1105`

KMD supports the Windows Vista display driver model with released Windows 7 features.

### `KMT_DRIVERVERSION_WDDM_1_2:1200`

KMD supports the Windows Vista display driver model with released Windows 8 features.

### `KMT_DRIVERVERSION_WDDM_1_3:1300`

KMD supports the Windows display driver model with released Windows 8.1 features.

### `KMT_DRIVERVERSION_WDDM_2_0:2000`

KMD supports the Windows display driver model with released Windows 10 features.

### `KMT_DRIVERVERSION_WDDM_2_1:2100`

KMD supports the Windows display driver model with released Windows 10, version 1607 features.

### `KMT_DRIVERVERSION_WDDM_2_2:2200`

KMD supports the Windows display driver model with released Windows 10, version 1703 features.

### `KMT_DRIVERVERSION_WDDM_2_3:2300`

KMD supports the Windows display driver model with released Windows 10, version 1709 features.

### `KMT_DRIVERVERSION_WDDM_2_4:2400`

KMD supports the Windows display driver model with released Windows 10, version 1803 features.

### `KMT_DRIVERVERSION_WDDM_2_5:2500`

KMD supports the Windows display driver model with released Windows 10, version 1809 features.

### `KMT_DRIVERVERSION_WDDM_2_6:2600`

KMD supports the Windows display driver model with released Windows 10, version 1903 features.

### `KMT_DRIVERVERSION_WDDM_2_7:2700`

KMD supports the Windows display driver model with released Windows 10, version 2004 features.

### `KMT_DRIVERVERSION_WDDM_2_8:2800`

KMD supports the Windows display driver model with released Windows 10, version 2004 features.

### `KMT_DRIVERVERSION_WDDM_2_9:2900`

KMD supports the Windows display driver model with released Windows Server 2022 features.

### `KMT_DRIVERVERSION_WDDM_3_0:3000`

KMD supports the Windows display driver model with released Windows 11, version 21H2 features.

### `KMT_DRIVERVERSION_WDDM_3_1:3100`

KMD supports the Windows display driver model with released Windows 11, version 22H2 features.

### `KMT_DRIVERVERSION_WDDM_3_2:3200`

KMD supports the Windows display driver model with released Windows 11, version 24H2 features.

## Remarks

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo) returns a **D3DKMT_DRIVERVERSION** value in a variable that the **pPrivateDriverData** member of the [**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo) structure points to when the D3D runtime or a third party graphics client driver (ICD) sets the **Type** member of **D3DKMT_QUERYADAPTERINFO** to **KMTQAITYPE_DRIVERVERSION**.

## See also

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)