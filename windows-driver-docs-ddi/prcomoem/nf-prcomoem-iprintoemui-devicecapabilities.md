# IPrintOemUI::DeviceCapabilities

## Description

The `IPrintOemUI::DeviceCapabilities` method enables a user interface plug-in to specify customized device capabilities.

## Parameters

### `poemuiobj`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `hPrinter`

Caller-supplied handle to the printer device.

### `pDeviceName`

Caller-supplied pointer to a string representing the device name.

### `wCapability`

Caller-supplied flag indicating the type of information the method should return. For a list of flags, see the description of the [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities) function.

### `pOutput`

Caller-supplied pointer to a buffer to receive the requested information. The type of information returned is dependent on the flag specified by *wCapability*.

### `pPublicDM`

Caller-supplied pointer to a validated [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `pOEMDM`

Caller-supplied pointer to the user interface plug-in's private DEVMODEW structure members.

### `dwOld`

Caller-supplied return value from the printer driver's [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities) function, or from another user interface plug-in. For more information, see the following Remarks section.

### `dwResult`

A return value that is dependent on the flag specified by *wCapability*. For more information, see the description of the [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities) function and the following Remarks section.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **S_DEVCAP_OUTPUT_FULL_REPLACEMENT** | The plug-in intends to use the buffer that is pointed to by the *pOutput* parameter for its own purposes. This return value is defined in prcomoem.h. For more information about when to use this return value, see the following Remarks section. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in's `IPrintOemUI::DeviceCapabilities` method performs the same types of operations as the [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities) function that is exported by user-mode printer interface DLLs. The method specifies capabilities provided by the printer.

You can use the `IPrintOemUI::DeviceCapabilities` method to preempt Unidrv support for a capability, or to add a capability that the printer driver doesn't provide. The driver calls `IPrintOemUI::DeviceCapabilities` from within its [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities) function.

If the `IPrintOemUI::DeviceCapabilities` method indicates customized support for a capability (by setting appropriate bits in response to a received DC_FIELDS flag), customized code must completely support the capability. Complete support typically includes returning information about the capability in response to calls to the `IPrintOemUI::DeviceCapabilities` method, plus providing appropriate user-mode or kernel-mode code to implement the capability.

If `IPrintOemUI::DeviceCapabilities` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation. Each time a plug-in's `IPrintOemUI::DeviceCapabilities` method is called, its *dwOld* input value is the return value from the previously called plug-in's `IPrintOemUI::DeviceCapabilities` method. For the first plug-in called, *dwOld* contains the return value from the printer driver's **DrvDeviceCapabilities** function. Likewise, the buffer pointed to by *pOutput* contains, on input, any contents placed there by a previously called `IPrintOemUI::DeviceCapabilities` method or **DrvDeviceCapabilities** function.

For multiple user interface plug-ins to work in conjunction with each other, each `IPrintOemUI::DeviceCapabilities` method must obey the following rules:

* If a user interface plug-in does not support a specified capability, its `IPrintOemUI::DeviceCapabilities` method should just return the contents of the *dwOld* parameter in *dwResult*.
* If a user interface plug-in supports the capability, its `IPrintOemUI::DeviceCapabilities` method should ignore *dwOld* and the contents of the buffer pointed to by *pOutput*. It should provide a return value and buffer contents appropriate for indicating that it supports the specified capability. If the method detects an error, it should return GDI_ERROR in *dwResult*.
* If you want a user interface plug-in to modify the capabilities information received in the buffer pointed to by *pOutput*, its `IPrintOemUI::DeviceCapabilities` method should modify the buffer contents and return an appropriate return value in *dwResult*. For example, if *wCapability* is DC_FIELDS, the method should OR the bits it needs to set with the bits that are set in *dwOld*, and return the result of the OR operation in *dwResult*.
* The preceding rules should be followed even if the received contents of *dwOld* is GDI_ERROR.

When the driver's **DrvDeviceCapabilities** function is called with the DC_FIELDS flag set, the function calls all `IPrintOemUI::DeviceCapabilities` methods, also specifying DC_FIELDS, and returns the union of all set bits to the caller.

The S_DEVCAP_OUTPUT_FULL_REPLACEMENT return value is new in Windows Vista, and applies to both Unidrv and Pscript5 user interface plug-ins. A plug-in should use the S_DEVCAP_OUTPUT_FULL_REPLACEMENT return value only if it requires complete control over what is placed in the buffer that is pointed to by the *pOutput* parameter. Neither the Unidrv nor the Pscript5 core driver will place data in the *pOutput* buffer when the plug-in returns S_DEVCAP_OUTPUT_FULL_REPLACEMENT. A plug-in might need to return this value when a setting in the [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure (which is pointed to by the *pPublicDM* and *pOEMDM* parameters) indicates to the user interface plug-in that it should report device capability data that is different from that specified in the GPD or PPD file. For example, a DEVMODEW structure that specifies photo printing might require a different set of paper types than those that are specified in the GPD or PPD file. In such a situation, and regardless of the values of the *pOutput* and *dwOld* parameters, the plug-in should return S_DEVCAP_OUTPUT_FULL_REPLACEMENT, and should set the *dwResult* parameter to the number of paper types that it intends to report. If *pOutput* is not **NULL**, the plug-in should also fill the buffer that is pointed to by *pOutput* with the desired set of paper types, and should set *dwResult* to the number of paper types that the plug-in intends to report.

When multiple user interface plug-ins are active at the same time, and one of them returns S_DEVCAP_OUTPUT_FULL_REPLACEMENT, the Unidrv or Pscript5 core driver interprets this return value to mean that the plug-ins intend to provide full replacement output data. As a result, the core driver does not place any data into the *pOutput* buffer before it calls the plug-ins. (The core driver calls the plug-ins in the same order that was specified for their installation.)

In situations where the values that the core driver places in the *pOutput* buffer do not need to be replaced, the plug-in should return S_OK. The Unidrv and Pscript5 core drivers recognize the S_DEVCAP_OUTPUT_FULL_REPLACEMENT return value only for device capabilities that use the *pOutput* buffer--in other words, when the *wCapability* parameter is set to one of the following flags:

DC_PAPERNAMES

DC_PAPERS

DC_PAPERSIZE

DC_BINNAMES

DC_BINS

DC_NUP

DC_PERSONALITY

DC_MEDIAREADY

DC_MEDIATYPENAMES

DC_MEDIATYPES

DC_ENUMRESOLUTIONS

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)