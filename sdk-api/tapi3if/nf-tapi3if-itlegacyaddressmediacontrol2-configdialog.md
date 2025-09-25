# ITLegacyAddressMediaControl2::ConfigDialog

## Description

The
**ConfigDialog** method causes the provider of the specified line device to display a dialog box to allow the user to configure parameters related to the line device. The parameters that can be edited are those currently in use on the device.

## Parameters

### `hwndOwner` [in]

A handle to a window to which the dialog box is to be attached. This parameter can be **NULL** to indicate that a window created by the method should have no owner window.

### `pDeviceClass` [in]

Pointer to a **BSTR** that specifies a device class name. This device class allows the application to select a specific subscreen of configuration information applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest-level configuration is selected.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method translates to a TAPI 2.*x*
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) function call. The
[ITLegacyAddressMediaControl2::ConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol2-configdialogedit) method translates to a
[lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialogedit) call. These methods differ in their source of parameters to edit and the result of the editing on an active connection. For a discussion about these differences, see
[lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialogedit).

## See also

[ITLegacyAddressMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol2)