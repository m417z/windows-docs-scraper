# VAL structure

## Description

The VAL structure is used by the microdriver and WIA Flatbed driver to pass information between each other.

## Members

### `lVal`

Specifies a command value to return to the WIA Flatbed driver. See [WIA Microdriver Commands](https://learn.microsoft.com/windows-hardware/drivers/image/wia-microdriver-commands) for a list of available commands for this parameter.

### `dblVal`

Specifies a command value to return to the WIA Flatbed driver. See [WIA Microdriver Commands](https://learn.microsoft.com/windows-hardware/drivers/image/wia-microdriver-commands) for a list of available commands for this parameter.

### `pGuid`

Points to the GUID of the pressed button. If no button was pressed, this member points to GUID_NULL.

### `pScanInfo`

Points to a [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure.

### `handle`

Points to a ShutDown event handle that will be signaled by the WIA Flatbed Driver when the driver is being unloaded or shut down.

### `ppButtonNames`

Specifies the address of a pointer to an array of button names.

### `pHandle`

Points to an event handle.

### `lReserved`

Reserved. Do not use.

### `szVal`

Specifies the device name in ASCII form. If needed for interrupt checking, the microdriver can use this name to pass to [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in order to obtain a file handle to the device.