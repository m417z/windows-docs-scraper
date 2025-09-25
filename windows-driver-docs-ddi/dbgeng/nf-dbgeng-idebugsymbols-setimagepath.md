# IDebugSymbols::SetImagePath

## Description

The **SetImagePath** method sets the executable image path.

## Parameters

### `Path` [in]

Specifies the new executable image path. This is a string that contains directories separated by semicolons (**;**).

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The executable image path is used by the engine when searching for executable images.

The executable image path can consist of several directories separated by semicolons. These directories are searched in order.

## See also

[AppendImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendimagepath)

[GetImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getimagepath)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)