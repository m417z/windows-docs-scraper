# wiauStrW2W function

## Description

The **wiauStrW2W** function copies a Unicode string to another Unicode string.

## Parameters

### `pwszSrc` [in]

Points to the Unicode string to be copied.

### `pwszDst` [out]

Pointer to a memory location that receives the copied string.

### `iSize`

Specifies the size, in bytes, of the buffer pointed to by *pwszDst*.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## See also

[wiauStrC2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2c)

[wiauStrC2W](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrc2w)

[wiauStrW2C](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaustrw2c)