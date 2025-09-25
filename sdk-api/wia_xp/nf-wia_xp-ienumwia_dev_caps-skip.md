# IEnumWIA_DEV_CAPS::Skip

## Description

The **IEnumWIA_DEV_CAPS::Skip** method skips the specified number of hardware device capabilities during an enumeration of available device capabilities.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of items to skip.

## Return value

Type: **HRESULT**

If the method succeeds, the method returns S_OK. It returns S_FALSE if it could not skip the specified number of device capabilities. If the method fails, it returns a standard COM error code.