# IPrintOemUI::CommonUIProp

## Description

The `IPrintOemUI::CommonUIProp` method allows a user interface plug-in to modify an existing printer property sheet page.

## Parameters

### `dwMode`

Caller-supplied integer constant indicating which property sheet page should be modified. The following constants are valid.

| Value | Definition |
| --- | --- |
| OEMCUIP_DOCPROP | The method is being called to modify the Layout, Paper/Quality, or Advanced page of the document property sheet. |
| OEMCUIP_PRNPROP | The method is being called to modify the Device Settings page of the printer property sheet. |

### `pOemCUIPParam`

Caller-supplied pointer to an [OEMCUIPPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemcuipparam) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

When a user interface plug-in's `IPrintOemUI::CommonUIProp` method is called, it should return customized property sheet option items in order to modify an existing printer property sheet page.

The `IPrintOemUI::CommonUIProp` method is called by the printer driver's [printer interface DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll). The method should supply an array of [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures describing property sheet items, along with a callback function for processing user modifications to option values.

You should expect the method to be called twice for each property sheet. The method's *dwMode* parameter value indicates whether it is being called to make changes to the printer property sheet or the document property sheet.

The first time it is called, the method should just return the number of [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures to be added. This number should be placed in the [OEMCUIPPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemcuipparam) structure's **cOEMOptItems** member. The printer interface DLL then allocates enough memory to store the specified number of OPTITEMs, and calls `IPrintOemUI::CommonUIProp` again.

The second time it is called, the `IPrintOemUI::CommonUIProp` method should do the following:

* Fill the driver-supplied array of OPTITEM structures with option descriptions. This array is pointed to by the OEMCUIPPARAM structure's **pOEMOptItems** member, and the number of allocated array elements is contained in the structure's **cOEMOptItems** member. (For information about specifying OPTITEM member values, see the description of the OEMCUIPPARAM structure's **pOEMOptItems** member).
* Return the number of structures added to the OPTITEM array by placing the number in the OEMCUIPPARAM structure's **cOEMOptItems** member.
* Return the address of a callback function in the OEMCUIPPARAM structure's **OEMCUIPCallback** member. This callback function is called when a user modifies the property sheet page. The callback function must be of type [OEMCUIPCALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-oemcuipcallback).
* Optionally, return the address of a private data structure by placing it in the OEMCUIPPARAM structure's **pOEMUserData** member. The callback function specified by the structure's **OEMCUIPCallback** member receives the OEMCUIPPARAM structure's address as an input parameter and can therefore obtain the private data's address.

  Space for the private data structure should be allocated by calling the Microsoft Windows SDK **HeapAlloc** function, using the handle contained in the OEMCUIPPARAM structure's **hOEMHeap** member.

If `IPrintOemUI::CommonUIProp` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information, see [Modifying a Driver-Supplied Property Sheet Page](https://learn.microsoft.com/windows-hardware/drivers/print/modifying-a-driver-supplied-property-sheet-page).