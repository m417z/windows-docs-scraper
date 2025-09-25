# wiauRegOpenDataA function

## Description

The **wiauRegOpenData** function opens the **DeviceData** registry key.

## Parameters

### `hkeyAncestor` [in]

Specifies the key handle of the parent. This parameter should be set to the value used in the call to the [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.

### `phkeyDeviceData` [in, out]

Pointer to a memory location that receives the opened key handle.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## Remarks

Call this function only in the STI [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method. Call **RegCloseKey** (described in the Microsoft Windows SDK documentation) when you are finished with the registry.

## See also

[IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize)