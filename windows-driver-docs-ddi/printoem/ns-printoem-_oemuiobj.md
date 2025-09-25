## Description

The **OEMUIOBJ** structure is used as an input argument to several of the methods exported by user interface plug-ins.

## Members

### `cbSize`

Size of the **OEMUIOBJ** structure.

### `pOemUIProcs`

Pointer to an [**OEMUIPROCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiprocs) structure, which is a private, internal structure.

## Remarks

User interface plug-ins do not need to reference an **OEMUIOBJ** structure's members. Plug-ins receive a pointer to this structure as input to their [IPrintOemUI::DeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicecapabilities), [IPrintOemUI::DevQueryPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devqueryprintex) and [IPrintOemUI::QueryColorProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-querycolorprofile) methods.

Additionally, the **OEMCUIPPARAM** structure contains an **OEMUIOBJ** structure pointer. Plug-ins must supply the received pointer when calling [IPrintOemDriverUI::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvgetdriversetting) or [IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting).