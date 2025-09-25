## Description

The **wiauRegGetDword** function gets a **DWORD** value from the **DeviceData** section of the registry.

## Parameters

### `hkKey` [in]

Specifies the registry key handle. This parameter should be set to the value pointed to by the *phkeyDeviceData*parameter when [wiauRegOpenData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiauregopendataw) returns.

### `pszValueName` [in]

Points to the first byte of a Unicode string containing the name of the registry entry.

### `pdwValue` [out]

Pointer to a memory location that receives the returned DWORD value.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauRegGetStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaureggetstrw)

[wiauRegOpenData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiauregopendataw)