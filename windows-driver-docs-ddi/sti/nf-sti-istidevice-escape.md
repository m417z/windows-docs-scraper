# IStiDevice::Escape

## Description

The **IStiDevice::Escape** method sends a request for a vendor-specific I/O operation to a still image device.

## Parameters

### `EscapeFunction` [in]

Caller-supplied, vendor-defined, DWORD-sized value representing an I/O operation. The device's minidriver must recognize this value and must export an **IStiUSD** interface. Vendor-defined values must be greater than STI_RAW_RESERVED, which is defined in *Sti.h*.

### `lpInData` [in]

Caller-supplied pointer to a buffer containing data to be sent to the device.

### `cbInDataSize`

Caller-supplied length, in bytes, of the data contained in the buffer pointed to by *lpInData*.

### `pOutData` [in, out]

Caller-supplied pointer to a memory buffer to receive data from the device.

### `dwOutDataSize`

Caller-supplied length, in bytes, of the buffer pointed to by *lpOutData*.

### `pdwActualData` [out]

Receives the number of bytes actually written to *pOutData*.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::Escape** method calls [IStiUSD::Escape](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-escape), which is exported by vendor-supplied minidrivers. The device's minidriver defines the Method parameter usage.

Before calling **IStiDevice::Escape**, clients of the **IStiDevice** COM interface must call [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)) to obtain an **IStiDevice** interface pointer, which provides access to a specified device.

A call to **IStiDevice::Escape** must be preceded by a call to [IStiDevice::LockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-lockdevice) and followed by a call to [IStiDevice::UnLockDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-unlockdevice).