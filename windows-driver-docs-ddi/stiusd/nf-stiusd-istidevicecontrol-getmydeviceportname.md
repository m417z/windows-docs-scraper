# IStiDeviceControl::GetMyDevicePortName

## Description

The **IStiDeviceControl::GetMyDevicePortName** method allows a user-mode still image minidriver to obtain a device's port name.

## Parameters

### `lpszDevicePath`

Caller-supplied pointer to a buffer to receive the device's port name.

### `cwDevicePathSize`

Caller-supplied number of characters (of type TCHAR) in the buffer pointed to by *lpszDevicePath*.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The path name that a still image minidriver receives by calling **IStiDeviceControl::GetMyDevicePortName** can be used as an input argument to [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) (described in the Microsoft Windows SDK documentation).

A still image minidriver receives an **IStiDeviceControl** interface pointer as an input argument to its [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.