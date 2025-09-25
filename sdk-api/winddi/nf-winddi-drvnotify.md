# DrvNotify function

## Description

The **DrvNotify** function allows a display driver to be notified about certain information by GDI.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the primary surface for which notification is occurring.

### `iType`

Identifies the type of information about which GDI is notifying the driver. This parameter can be one of the following values:

#### DN_DEVICE_ORIGIN

Notifies the driver of the device's origin. The *pvData* parameter points to a POINTL structure that identifies the origin of the physical device in desktop space. This notification is useful for drivers of devices that are a part of a multimonitor system. The value to which *pvData* points is always (0,0) on a single monitor system.

#### DN_DRAWING_BEGIN

Notifies the driver that the first drawing operation is about to occur for this instance of the PDEV that is associated with the specified surface. The *pvData* parameter points to **NULL**.

### `pvData`

Pointer to notification data or **NULL**, depending on the value of *iType*.

## Remarks

A display driver can optionally implement **DrvNotify**. GDI will call **DrvNotify** only in display drivers that do implement it.

## See also

[EngQueryDeviceAttribute](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engquerydeviceattribute)