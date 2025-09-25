# DrvDrawEscape function

## Description

The **DrvDrawEscape** function is the entry point that serves more than one function call; the particular function depends on the value of the *iEsc* parameter.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface to which the call is directed.

### `iEsc` [in]

Specifies the operation to be performed. The meanings of the remaining parameters depend on this parameter. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| ESC_PASSTHROUGH | Passes raw device data to the device driver. The number of bytes of raw data is indicated by *cjIn*. The data is pointed to by *pvIn*. The return value is the number of bytes written if the function is successful. Otherwise, it is zero, and an error code is logged. |

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that can be queried to find the area on the surface that the caller can overwrite.

### `prcl` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the window rectangle on the surface. The application does not know the position of the window on the surface. GDI supplies this rectangle and holds a lock that ensures the rectangle is stable for the duration of the call. Coordinates received from the application are relative to the upper left corner of the window rectangle.

### `cjIn` [in]

Specifies the size, in bytes, of the buffer pointed to by *pvIn*.

### `pvIn` [in]

Pointer to the input data for the call. The format of the input data depends on the function specified by *iEsc*.

## Return value

The return value depends on the function specified by *iEsc*. The driver should return 0xFFFFFFFF if an unsupported function is called.

## Remarks

This entry point differs from [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape) in that a CLIPOBJ structure is provided. This allows a driver to implement its own [drawing functions](https://learn.microsoft.com/windows-hardware/drivers/display/optional-display-driver-functions) in a windowed environment.

GDI passes data directly from a (possibly malicious) client application to the driver, which means that the **DrvDrawEscape** function must validate all input arguments. Specifically, this function must:

* Verify that the value received in the *iEsc* parameter represents a valid query.
* Verify that the size of the input buffer (the value in the *cjIn* parameter) is valid for the specified query.
* Verify that the contents of the buffer pointed to by the *pvIn* parameter are valid for the specified query.

The escapes that a device supports are determined by a call to [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape).

For more information about the escape codes that Microsoft reserves, see [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape).

**DrvDrawEscape** is optional for all drivers.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver)

[DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape)