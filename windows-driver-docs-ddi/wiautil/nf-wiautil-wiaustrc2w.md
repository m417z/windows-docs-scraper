# wiauStrC2W function

## Description

The **wiauStrC2W** function converts an ANSI character string to a Unicode string.

## Parameters

### `pszSrc` [in]

Points to the ANSI string to convert.

### `pwszDst` [out]

Pointer to a memory location that receives the converted Unicode string.

### `iSize`

Specifies the size, in bytes, of the buffer pointed to by *pwszDst*.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauStrC2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2c)

[wiauStrW2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2c)

[wiauStrW2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2w)