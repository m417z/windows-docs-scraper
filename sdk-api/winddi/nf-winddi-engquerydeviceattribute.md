# EngQueryDeviceAttribute function

## Description

The **EngQueryDeviceAttribute** function allows the driver to query the system about particular attributes of the device.

## Parameters

### `hdev` [in]

Handle to the device. This parameter is the GDI handle received by the driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev) function.

### `devAttr` [in]

Specifies the attribute for which GDI should return information. This parameter must be QDA_ACCELERATION_LEVEL, which queries the driver accelerations that GDI currently allows.

### `pvIn` [in]

Reserved for system use. This parameter is currently ignored by GDI.

### `ulInSize` [in]

Reserved for system use. This parameter is currently ignored by GDI.

### `pvOut` [out]

Pointer to a buffer of *ulOutSize* bytes in which GDI writes information about the attribute being queried. When *devAttr* is QDA_ACCELERATION_LEVEL, GDI writes in the buffer a DWORD value from 0 through 5 that indicates the current acceleration level. See [Display Driver Testing Tools](https://learn.microsoft.com/windows-hardware/drivers/display/display-driver-testing-tools) for a description of the acceleration levels.

### `ulOutSize` [out]

Specifies the size, in bytes, of the buffer to which *pvOut* points.

## Return value

**EngQueryDeviceAttribute** returns **TRUE** upon success; otherwise, it returns **FALSE**.

## Remarks

The video card's acceleration level can be dynamically set through the Display program in Control Panel. **EngQueryDeviceAttribute** allows the driver to determine the acceleration level currently set.

## See also

[DrvNotify](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvnotify)