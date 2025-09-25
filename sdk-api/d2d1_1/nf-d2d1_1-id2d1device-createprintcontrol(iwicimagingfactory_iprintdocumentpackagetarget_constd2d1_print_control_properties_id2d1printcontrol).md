# ID2D1Device::CreatePrintControl(IWICImagingFactory,IPrintDocumentPackageTarget,const D2D1_PRINT_CONTROL_PROPERTIES,ID2D1PrintControl)

## Description

Creates an [ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol) object that converts [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) primitives stored in [ID2D1CommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandlist) into a fixed page representation. The print sub-system then consumes the primitives.

## Parameters

### `wicFactory` [in]

Type: **[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)***

A WIC imaging factory.

### `documentTarget` [in]

Type: **[IPrintDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetarget)***

The target print job for this control.

### `printControlProperties` [in, optional]

Type: **const [D2D1_PRINT_CONTROL_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_print_control_properties)***

The options to be applied to the print control.

### `printControl` [out]

Type: **[ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol)****

When this method returns, contains the address of a pointer to an [ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol) object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_FAIL | Generic failure code. |
| D2DERR_PRINT_FORMAT_NOT_SUPPORTED | The print format is not supported by the document target. |

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## See also

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)