# IPrintOemUni::CommandCallback

## Description

The `IPrintOemUni::CommandCallback` method is used to provide dynamically generated printer commands for Unidrv-supported printers.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwCallbackID`

Caller-supplied value representing the printer command's ***CallbackID** attribute in the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file. (For more information, see the following Remarks section.)

### `dwCount`

Caller-supplied value representing the number of elements in the array pointed to by *pdwParams*. Can be 0.

### `pdwParams`

Caller-supplied pointer to an array of DWORD-sized parameters containing values specified by the printer commands ***Params** attribute in the printer's GPD file. (For more information, see the following Remarks section.) Can be **NULL**.

### `piResult` [out]

Receives a method-supplied result value. See the following Remarks section.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::CommandCallback` method is used by rendering plug-ins to dynamically generate printer commands, for printers that are supported by [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/).

If you want to dynamically generate a printer command, you must include a ***CallbackID** attribute and, optionally, a ***Params** attribute, within the command's *Command entry in the printer's GPD file. For more information see [Dynamically Generated Printer Commands](https://learn.microsoft.com/windows-hardware/drivers/print/dynamically-generated-printer-commands).

When Unidrv calls the `IPrintOemUni::CommandCallback` method, it supplies the *Command entry's ***CallbackID** attribute value as the *dwCallbackID* parameter. It also places the *Command entry's ***Params** attribute value inside a DWORD array and supplies the array's address as the *pParams* parameter. The array contains set of Unidrv-defined [standard variables](https://learn.microsoft.com/windows-hardware/drivers/print/standard-variables) values, and the *dwCount* parameter specifies the number of parameters contained in the array. For more information about the attributes see [Command Attributes](https://learn.microsoft.com/windows-hardware/drivers/print/command-attributes).

The method should use the *dwCallbackID* parameter value to determine which command to process. For each supported command, the method must be aware of which, if any, standard variables have been specified by the *Command entry's ***Params** attribute, and in which order.

The method is responsible for constructing a printer command, and then sending the command to the print spooler by calling the [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) method.

The value supplied for *piResult* should always return zero unless the method is processing a cursor command. For [cursor commands](https://learn.microsoft.com/windows-hardware/drivers/print/cursor-commands) that move the cursor in either the *x* or  direction, the method should return the new cursor position.

The `IPrintOemUni::CommandCallback` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "CommandCallback" as input.