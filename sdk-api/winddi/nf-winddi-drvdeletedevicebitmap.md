# DrvDeleteDeviceBitmap function

## Description

The **DrvDeleteDeviceBitmap** function deletes a device bitmap created by [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap).

## Parameters

### `dhsurf`

Handle to the bitmap to be deleted. This handle identifies the bitmap created by [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap).

## Remarks

A driver must implement **DrvDeleteDeviceBitmap** if it supplies [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap).

The driver should free any resources associated with the device bitmap.

## See also

[DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)