# DrawEscape function

## Description

The **DrawEscape** function provides drawing capabilities of the specified video display that are not directly available through the graphics device interface (GDI).

## Parameters

### `hdc` [in]

A handle to the DC for the specified video display.

### `iEscape` [in]

The escape function to be performed.

### `cjIn` [in]

The number of bytes of data pointed to by the *lpszInData* parameter.

### `lpIn` [in]

A pointer to the input structure required for the specified escape.

## Return value

If the function is successful, the return value is greater than zero except for the QUERYESCSUPPORT draw escape, which checks for implementation only.

If the escape is not implemented, the return value is zero.

If an error occurred, the return value is less than zero.

## Remarks

When an application calls the **DrawEscape** function, the data identified by *cbInput* and *lpszInData* is passed directly to the specified display driver.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)