# ITLegacyAddressMediaControl2::ConfigDialogEdit

## Description

The
**ConfigDialogEdit** method causes the provider of the specified line device to display a dialog box to allow the user to configure parameters related to the line device. The configuration data is passed in and out of this method by the application. (The data is the same as that retrieved by the
[ITLegacyAddressMediaControl::GetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getdevconfig) method and set by the
[ITLegacyAddressMediaControl::SetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-setdevconfig) method.)

## Parameters

### `hwndOwner` [in]

A handle to a window to which the dialog box is to be attached. Can be **NULL** to indicate that a window created by the method should have no owner window.

### `pDeviceClass` [in]

Pointer to a **BSTR** that specifies a device class name. This device class allows the application to select a specific subscreen of configuration information applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest level configuration is selected.

### `dwSizeIn` [in]

Pointer to the size of the configuration data pointed to by the *pDeviceConfigIn* parameter.

### `pDeviceConfigIn` [in]

Pointer to an array of bytes containing device configuration data to edit.

### `pdwSizeOut` [out]

Pointer to the size of the configuration data pointed to by the *ppDeviceConfigOut* parameter.

### `ppDeviceConfigOut` [out]

Pointer to an array of bytes containing edited device configuration data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method translates to a TAPI 2.*x*
[lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialogedit) call. The
[ITLegacyAddressMediaControl2::ConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol2-configdialog) method translates to a
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) call. These methods differ in their source of parameters to edit and the result of the editing on an active connection. For a discussion about these differences, see
[lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialogedit).

## See also

[ITLegacyAddressMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)

[ITLegacyAddressMediaControl2::ConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol2-configdialog)