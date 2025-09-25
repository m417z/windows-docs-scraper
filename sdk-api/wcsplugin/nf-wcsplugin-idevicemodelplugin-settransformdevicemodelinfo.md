# IDeviceModelPlugIn::SetTransformDeviceModelInfo

## Description

Provides the plug-in with parameters to determine where in the transform sequence the specific plug-in occurs.

## Parameters

### `iModelPosition` [in]

The one-based model position of the other device model in the workflow of *uiNumModels*, as provided in the [Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-initialize) function.

### `pIDeviceModelOther` [in]

A pointer to a **IDeviceModelPlugIn** interface that contains the other device model in the transform sequence.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## Remarks

This function is called by the [CreateMultiProfileTransform](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-createmultiprofiletransform) function, which is responsible for calling **AddRef** and **Release** as appropriate. The function enables plug-in device models to exchange information in a proprietary manner by accessing proprietary plug-in interface functions.

This function will fail if the other device model is a baseline device model, because such models are not plugins and thus inter-plugin communication is not supported.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)