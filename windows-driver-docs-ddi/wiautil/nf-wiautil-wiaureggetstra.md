## Description

The **wiauRegGetStr** function gets a string value from the **DeviceData** section of the registry.

## Parameters

### `hkKey` [in]

Specifies the registry key handle. This parameter should be set to the value pointed to by the *phkeyDeviceData* parameter when [wiauRegOpenData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiauregopendataw) returns.

### `pszValueName` [in]

Points to the first character of a Unicode string containing the name of the registry entry.

### `pszValue` [out]

Pointer to a memory location that receives the string value, including a terminating null character.

### `pdwLength` [in, out]

Pointer to a memory location that receives the length, in bytes, of the string value pointed to by the *pwszValue* parameter. The length includes the terminating null character.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauRegGetDword](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaureggetdwordw)

[wiauRegOpenData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiauregopendataw)