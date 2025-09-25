# IPrintOemUI::QueryColorProfile

## Description

The `IPrintOemUI::QueryColorProfile` method allows a user interface plug-in to specify an ICC profile to use for color management.

## Parameters

### `hPrinter`

Caller-supplied printer handle.

### `poemuiobj`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `pPublicDM`

Caller-supplied pointer to a validated [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `pOEMDM`

Caller-supplied pointer to the user interface plug-in's private DEVMODEW structure members.

### `ulQueryMode`

One of the following caller-supplied bit flags, indicating the type of profile to be specified.

| Flag | Definition |
| --- | --- |
| QCP_DEVICEPROFILE | The caller is requesting a device profile. |
| QCP_SOURCEPROFILE | The caller is requesting a source profile. |

### `pvProfileData`

Caller-supplied pointer to a buffer to receive profile information.

### `pcbProfileData`

Caller-supplied pointer to a value representing the size, in bytes, of the buffer pointed to by *pvProfileData*.

### `pflProfileData`

One of the following method-supplied bit flags, indicating the type of information the method is returning.

| Flag | Definition |
| --- | --- |
| QCP_PROFILEDISK | The method is returning the file name of an ICC profile in the buffer pointed to by *pvProfileData*. |
| QCP_PROFILEMEMORY | The method is returning profile data in the buffer pointed to by *pvProfileData*. |

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in's `IPrintOemUI::QueryColorProfile` method performs the same types of operations as the **DrvQueryColorProfile** function that is exported by user-mode printer interface DLLs. For information about printer events and how they should be processed, see the description of the [DrvQueryColorProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvquerycolorprofile) function.

If you provide a user interface plug-in, the printer driver's **DrvQueryColorProfile** function calls the `IPrintOemUI::QueryColorProfile` method. The **DrvQueryColorProfile** function performs its own processing for the specified event, and then calls the `IPrintOemUI::QueryColorProfile` method to handle additional processing of the event.

If `IPrintOemUI::QueryColorProfile` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).