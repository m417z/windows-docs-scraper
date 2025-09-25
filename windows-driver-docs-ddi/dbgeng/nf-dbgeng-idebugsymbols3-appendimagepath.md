# IDebugSymbols3::AppendImagePath

## Description

The **AppendImagePath** method appends directories to the executable image path.

## Parameters

### `Addition` [in]

Specifies the directories to append to the executable image path. This is a string that contains directory names separated by semicolons (;).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The executable image path is used by the [engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/e) when searching for executable images.

The executable image path can consist of several directories separated by semicolons (;). These directories are searched in order.

## See also

[GetImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getimagepath)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setimagepath)