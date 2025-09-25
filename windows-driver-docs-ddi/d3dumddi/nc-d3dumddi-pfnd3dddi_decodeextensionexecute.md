# PFND3DDDI_DECODEEXTENSIONEXECUTE callback function

## Description

The **DecodeExtensionExecute** function performs a decode operation by using the given DirectX Video Accelerator (DXVA) nonstandard, decode extension device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [**D3DDDIARG_DECODEEXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute) structure that describes the DXVA decode operation to perform.

## Return value

**DecodeExtensionExecute** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The DirectX VA decode operation is successfully performed.|
|E_OUTOFMEMORY|DecodeExtensionExecute could not allocate the required memory for it to complete.|

## Remarks

A user-mode display driver (UMD) can implement the **DecodeExtensionExecute** function to support extensions to the standard decode types (that is, nonstandard decode GUIDs). These nonstandard decode types are useful for configuring encryption and other miscellaneous enhancements.

**DecodeExtensionExecute** is called when DirectX VA 2.0 decoders require the nonstandard extensions.

For compatibility with DirectX VA 1.0 decoders that might require these nonstandard extensions, **DecodeExtensionExecute** is called whenever a DirectX VA 1.0 decoder makes an execution call in which any bDXVA_Func value that is greater than 4 is set in the most significant 8 bits of the **Function** member of the [**D3DDDIARG_DECODEEXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute) structure. **DecodeExtensionExecute** is also called whenever DirectX VA 1.0 decoder makes a configuration call in which any DXVA_ConfigQueryOrReplyFunc flag other than DXVA_QUERYORREPLYFUNCFLAG_DECODER_PROBE_QUERY (0xFFFFF1) or DXVA_QUERYORREPLYFUNCFLAG_DECODER_LOCK_QUERY (0xFFFFF5) flag is set in the most significant 24 bits of **Function**. For more information about the meanings for the bit settings of **Function**, see the [DXVA_ConfigQueryOrReplyFlag and DXVA_ConfigQueryorReplyFunc Variables](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-configqueryorreplyflag-and-dxva-configqueryorreplyfunc-variables) and [bDXVA_Func Variable](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) topics.

Because of compatibility issues with DirectX VA 1.0 decoders that might make such a configuration call before DXVA_QUERYORREPLYFUNCFLAG_DECODER_LOCK_QUERY, those decoders can make such a configuration call also before a decode device is created. If such a configuration call is made before a decode device is created, the **hDecode** member of the [**D3DDDIARG_DECODEEXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute) structure that the **pData** parameter points to is set to NULL. In this situation, the driver might be required to return an error (for example, E_FAIL) if the driver cannot support the situation independent of a decode device.

## See also

[**CreateExtensionDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[**D3DDDIARG_DECODEEXTENSIONEXECUTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeextensionexecute)

[**D3DDDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)