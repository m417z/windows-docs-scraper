# wiauStrW2C function

## Description

The **wiauStrW2C** function converts a Unicode string to an ANSI character string.

## Parameters

### `pwszSrc` [in]

Points to the Unicode string to be converted.

### `pszDst` [out]

Pointer to a memory location that receives the converted ANSI string.

### `iSize`

Specifies the size, in bytes, of the buffer pointed to by *pszDst*.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauStrC2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2c)

[wiauStrC2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2w)

[wiauStrW2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2w)