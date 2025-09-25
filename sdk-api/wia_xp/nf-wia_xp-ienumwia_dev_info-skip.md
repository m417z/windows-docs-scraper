# IEnumWIA_DEV_INFO::Skip

## Description

The **IEnumWIA_DEV_INFO::Skip** method skips the specified number of hardware devices during an enumeration of available devices.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of devices to skip.

## Return value

Type: **HRESULT**

If the method succeeds, the method returns S_OK. If it is unable to skip the specified number of devices, it returns S_FALSE. If the method fails, it returns a standard COM error code.