## Description

A still image minidriver's **IStiUSD::Escape** method performs a vendor-specific I/O operation on a still image device.

## Parameters

### `EscapeFunction`

Caller-supplied, vendor-defined, DWORD-sized value representing an I/O operation. Vendor-defined values must be greater than STI_RAW_RESERVED, which is defined in *Sti.h*.

### `lpInData`

Caller-supplied pointer to a buffer containing data sent to the device.

### `cbInDataSize`

Caller-supplied length, in bytes, of the buffer pointed to by *lpInData*.

### `pOutData`

Caller-supplied pointer to a memory buffer to receive data from the device.

### `cbOutDataSize`

Caller-supplied length, in bytes, of the buffer pointed to by *lpOutData*.

### `pdwActualData`

Receives the number of bytes actually written to *pOutData*.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*. If the method is not implemented, it should return STIERR_UNSUPPORTED.

## Remarks

A still image minidriver only needs to implement **IStiUSD::Escape** if I/O operations are required that cannot be implemented within [IStiUSD::RawReadData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawreaddata), [IStiUSD::RawWriteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawwritedata), [IStiUSD::RawReadCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawreadcommand), or [IStiUSD::RawWriteCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-rawwritecommand) methods. The minidriver defines parameter usage for **IStiUSD::Escape**.

## See also

[IStiDevice::Escape](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-escape)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)