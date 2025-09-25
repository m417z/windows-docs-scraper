# IDeviceModelPlugIn::Initialize

## Description

Takes a pointer to a Stream that contains the whole device model plug-in as input, and initializes any internal parameters required by the plug-in.

## Parameters

### `bstrXml` [in]

A string that contains the BSTR XML device model plug-in profile. This parameter stores data as little-endian Unicode XML; however, it may have no leading bytes to tag it as such. Also, the encoding keyword in the XML may not reflect that this is formatted as little-endian Unicode. Furthermore, due to the action of the MSXML engine, the BSTR XML file is processed and might not have exactly the same contents as the original XML file.

### `cNumModels` [in]

The number of total models in the transform sequence.

### `iModelPosition` [in]

The one-based model position of the other device model in the workflow of *uiNumModels* as provided in the **Initialize** function.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## Remarks

If this function is called more than once, subsequent calls release any allocated memory and reinitialize according to the new *bstrXml* parameter.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)