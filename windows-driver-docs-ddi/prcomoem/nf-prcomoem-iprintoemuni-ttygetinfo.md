# IPrintOemUni::TTYGetInfo

## Description

The `IPrintOemUni::TTYGetInfo` method enables a rendering plug-in to supply Unidrv with information relevant to text-only printers.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwInfoIndex`

Caller-supplied constant identifying the type of information being requested. The following constant values are defined:

#### OEMTTY_INFO_CODEPAGE

The *pOutputBuf* parameter points to a DWORD in which the method should return the number of the code page to be used.

#### OEMTTY_INFO_MARGINS

The *pOutputBuf* parameter points to a RECT structure in which the method should return page margin widths, in tenths of millimeters (for example, 20 represents 2 mm). If the entire page is printable, all margin values must be 0.

#### OEMTTY_INFO_NUM_UFMS

The *pOutputBuf* parameter points to a DWORD in which the method should return the number of resource IDs of the [UFMs](https://learn.microsoft.com/windows-hardware/drivers/) for 10, 12, and 17 CPI fonts. To actually obtain these resource IDs, perform a query using OEMTTY_INFO_UFM_IDS.

#### OEMTTY_INFO_UFM_IDS

The *pOutputBuf* parameter points to an array of DWORDs of sufficient size to hold the number of resource IDs of the UFMs for 10, 12, and 17 CPI fonts. (This number is obtained by using OEMTTY_INFO_NUM_UFMS in a query.) The method should return the resource IDs of the [UFMs](https://learn.microsoft.com/windows-hardware/drivers/) for 10,12, and 17 CPI fonts.

### `pOutputBuf`

Caller-supplied pointer to a buffer to receive the requested information.

### `dwSize`

Caller-supplied size, in bytes, of the buffer pointed to by *pOutputBuf*.

### `pcbcNeeded`

Caller-supplied pointer to a location to receive the number of bytes written into the buffer pointed to by *pOutputBuf*. If the number of bytes required is smaller than the number specified by *dwSize*, the method should supply the required size and return E_FAIL.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::TTYGetInfo` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "TTYGetInfo" as input.