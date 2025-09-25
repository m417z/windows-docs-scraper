# IPrintOemUI2::QueryJobAttributes

## Description

The `IPrintOemUI2::QueryJobAttributes` method allows a UI plug-in to postprocess the core driver's results after a call to the [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) DDI. The plug-in can choose to overwrite the values that the core driver placed in the *lpAttributeInfo* output buffer.

## Parameters

### `hPrinter`

Specifies the caller-supplied printer handle.

### `pDevmode`

Pointer to a caller-supplied [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `dwLevel`

Specifies a caller-supplied value indicating the type of structure pointed to by *lpAttributeInfo*, as indicated in the following table.

| Value | Structure Pointed to by *lpAttributeInfo* |
| --- | --- |
| 1 | [ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1) |
| 2 | [ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2) |
| 3 | [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3) |
| 4 | [ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4) |

Note that if this method changes any dwDrv*Xxx* member of the ATTRIBUTE_INFO_*N* structures, the spooler assumes that the plug-in is able to support the behavior represented by that member.

### `lpAttributeInfo`

Pointer to a memory location that receives the address of a structure of the type identified by *dwLevel*.

## Return value

If the UI plug-in supports this method, and the method succeeded, it should return S_OK. This causes the core driver to return **TRUE** for the [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) DDI. If the UI plug-in supports this method, but the method failed, it should return E_FAIL. This causes the core driver to return **FALSE** for the DrvQueryJobAttributes DDI. If the UI plug-in does not support this method, it should return E_NOTIMPL.

## Remarks

When the printer has multiple UI plug-ins installed, the core driver calls the UI plug-ins in the order they were installed. The HRESULT returned by the last UI plug-in that supports this method is used to determine the core driver's DrvQueryJobAttributes DDI return value as described in the previous section.

See [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) for more information.

## See also

[ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1)

[ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2)

[ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3)

[ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4)

[DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes)

[IPrintOemUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui2)