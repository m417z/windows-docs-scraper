## Description

The **Scan** function reads data from the device and returns the data to the WIA Flatbed driver.

## Parameters

### `pScanInfo` [in, out]

Specifies the [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure that represents the microdriver's settings. This is stored by the WIA Flatbed driver to guarantee that the settings between the microdriver and the WIA Flatbed driver are synchronized.

### `lPhase`

Specifies the scan phase requested. This parameter can be set to one of the following values.

| Value | Meaning |
|--|--|
| SCAN_FIRST | This signals the first phase of the scan. The microdriver performs three tasks: it initializes the device, it uses the data in the [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure to set up the scan (for example, set the resolution, the start position, the width and the height on the device), and it starts the scan. Data must be returned from this call. Data must be put into the buffer pointed to by *pBuffer* and the *pReceived* parameter must be set to the amount of data put in the buffer. |
| SCAN_NEXT | This will be repeatedly called during the data transfer. Data should be put into the buffer pointed to by *pBuffer* and the *pReceived* parameter must be set to the amount of data put in the buffer. |
| SCAN_FINISHED | This will be called at the end of the scan to terminate the scanning process. No data should be transferred. SCAN_FINISHED will always be called even if the user cancels the scan. The microdriver should stop transferring data and the scanner should be reset so that it is ready for the next scan. The data returned from this function should be in raw format without any header. The data can be either packed or planar, aligned or unaligned, and in RGB or BGR order. Set the **RawDataFormat**, **RawPixelOrder**, and **bNeedDataAlignment** members of the [SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo) structure appropriately in response to the CMD_INITIALIZE command. |

### `pBuffer` [out]

Specifies the buffer that will be filled with scanned data by the microdriver. This buffer is allocated by the WIA Flatbed Driver and is guaranteed to be at least *lLength* bytes in length.

### `lLength`

Specifies the requested amount of data that will be scanned. The microdriver must never overfill the buffer pointed to by *pBuffer*.

### `plReceived` [out]

Specifies the amount of data actually scanned into *pBuffer*. This value should never exceed the value of *lLength*, but can be less.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns a standard COM error code.

## See also

[SCANINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamicro/ns-wiamicro-_scaninfo)

[WIA Microdriver Commands](https://learn.microsoft.com/windows-hardware/drivers/image/wia-microdriver-commands)

[WIA Microdriver Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)