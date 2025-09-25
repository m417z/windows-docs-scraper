# DrvEscape function

## Description

The **DrvEscape** function is used for retrieving information from a device that is not available in a device-independent device driver interface; the particular query depends on the value of the *iEsc* parameter.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface to which the call is directed.

### `iEsc` [in]

Specifies a query. The meaning of the other parameters depends on this value. QUERYESCSUPPORT is the only predefined value; it queries whether the driver supports a particular escape function. In this case, *pvIn* points to an escape function number; *cjOut* and *pvOut* are ignored. If the specified function is supported, the return value is nonzero.

### `cjIn` [in]

Specifies the size, in bytes, of the buffer pointed to by *pvIn*.

### `pvIn` [in]

Pointer to the input data for the call. The format of the input data depends on the query specified by the *iEsc* parameter.

### `cjOut` [in]

Specifies the size, in bytes, of the buffer pointed to by *pvOut*.

### `pvOut` [out]

Pointer to the output buffer. The format of the output data depends on the query specified by the *iEsc* parameter.

## Return value

The return value is dependent on the query specified by the *iEsc* parameter. If the function specified in the query is not supported, the return value is zero.

## Remarks

Drawing on the device is not allowed in this function. [DrvDrawEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdrawescape) is to be used for specialized drawing support.

GDI passes data directly from a (possibly malicious) client application to the driver, which means that the **DrvEscape** function must validate all input arguments. Specifically, this function must:

* Verify that the value received in the *iEsc* parameter represents a valid query.
* Verify that the size of the input buffer (the value in the *cjIn* parameter) is valid for the specified query.
* Verify that the contents of the buffer pointed to by the *pvIn* parameter are valid for the specified query.
* Verify that the size of the specified output buffer (the value in the *cjOut* parameter) is valid for the specified query.

Microsoft reserves the range 0 to 0X10000 for its escape codes. Third-party vendors are free to choose escape codes for their own use above this range. Since driver-specific escape codes may conflict with those used in other display drivers, it is important for a display driver to validate escape parameters before processing the escape. One way to do this would be to validate the input and output block sizes and the input block parameters. For added security, drivers should also include a "magic" value which must be set appropriately in every input block to ensure that the input block is from a trusted source.

**DrvEscape** is optional for all drivers.

## See also

[DrvDrawEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdrawescape)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)