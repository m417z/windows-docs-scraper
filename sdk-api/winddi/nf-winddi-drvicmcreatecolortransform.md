# DrvIcmCreateColorTransform function

## Description

The **DrvIcmCreateColorTransform** function creates an ICM color transform.

## Parameters

### `dhpdev` [in]

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/).

### `pLogColorSpace` [in]

Pointer to a logical color space structure. The LOGCOLORSPACEW structure is defined in the Microsoft Windows SDK documentation. The driver should obtain source color space information from this structure when *pvSourceProfile* is **NULL**.

### `pvSourceProfile` [in, optional]

Pointer to the memory map of the source profile. This parameter can be **NULL**.

### `cjSourceProfile` [in]

Specifies the size, in bytes, of the source profile memory map. If *pvSourceProfile* is **NULL**, this parameter should be set to zero.

### `pvDestProfile` [in]

Pointer to the memory map of the destination profile.

### `cjDestProfile` [in]

Specifies the size, in bytes, of the destination profile memory map.

### `pvTargetProfile` [in, optional]

Pointer to the memory map of the target profile. This parameter can be **NULL**.

### `cjTargetProfile` [in]

Specifies the size, in bytes, of the target profile memory map. If *pvTargetProfile* is **NULL**, this parameter should be set to zero.

### `dwReserved` [in]

Reserved parameter that should be set to zero.

## Return value

**DrvIcmCreateColorTransform** returns a handle to the created transform upon success. Otherwise, it reports an error and returns **NULL**.

## Remarks

The driver creates a color transform from the profile data as follows:

* The driver should use the source profile that *pvSourceProfile* points to when it is not **NULL**. Otherwise, the driver should use the data in the structure to which *pLogColorSpace* points for source color space information.
* When the driver receives a destination profile but no target profile, it should store the data required to transform colors from the specified source color space into the specified destination color space.
* When the driver receives both destination and target profiles, it should store the data required to transform colors from the specified source color space into the specified target color space and from the target color space back to the destination color space. In this scenario, the driver's device is the destination device on which an image can be proofed. The driver must then be able to convert the color space of the proofing image into the target device's color space.

Regardless of whether a target profile is specified, the driver's device is always the destination device.

The provided profiles adhere to version 2.10 of the ICC profile format. If the driver does not understand the specified format, it should fail the call.

The driver can safely access the entire memory map of each profile. The *pvSourceProfile*, *pvDestProfile*, and *pvTargetProfile* pointers are valid only during the scope of the call to **DrvIcmCreateTransform**.

Drivers that report ICM support should implement this function. A driver indicates support for ICM by setting the GCAPS_ICM flag in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

## See also

[DrvIcmDeleteColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmdeletecolortransform)