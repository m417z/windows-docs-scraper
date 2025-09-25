# IWiaItemExtras::Escape

## Description

The **IWiaItemExtras::Escape** method sends a request for a vendor-specific I/O operation to a still image device.

## Parameters

### `dwEscapeCode` [in]

Type: **DWORD**

Calling application-supplied, vendor-defined, DWORD-sized value that represents an I/O operation.

### `lpInData` [in]

Type: **BYTE***

Pointer to a calling application-supplied buffer that contains data to be sent to the device.

### `cbInDataSize` [in]

Type: **DWORD**

Calling application-supplied length, in bytes, of the data contained in the buffer pointed to by *lpInData*.

### `pOutData` [out]

Type: **BYTE***

Pointer to a calling application-supplied memory buffer to receive data from the device.

### `dwOutDataSize` [in]

Type: **DWORD**

Calling application-supplied length, in bytes, of the buffer pointed to by *pOutData*.

### `pdwActualDataSize` [out]

Type: **DWORD***

Receives the number of bytes actually written to *pOutData*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWiaItemExtras](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitemextras)