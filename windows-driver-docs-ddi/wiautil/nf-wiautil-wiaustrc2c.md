# wiauStrC2C function

## Description

The **wiauStrC2C** function copies an ANSI character string to another ANSI character string.

## Parameters

### `pszSrc` [in]

Points to the ANSI string to be copied.

### `pszDst` [out]

Pointer to a memory location that receives the copied string

### `iSize`

Specifies the size, in bytes, of the buffer pointed to by *pszDst*.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauStrC2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2w)

[wiauStrW2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2c)

[wiauStrW2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2w)