## Description

The **MxdcGetPDEVAdjustment** function is exported by a printer interface DLL and supplies printer configuration data for the Microsoft XPS Document Converter (MXDC).

## Parameters

### `hPrinter` [in]

The handle of the currently instantiated printer.

### `cbDevMode` [in]

The size of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, in bytes, including the driver's private DEVMODE data.

### `pDevMode` [in]

A copy of the DEVMODE structure that the MXDC received. The printer interface DLL uses information from this structure to return the requested data.

### `cbIn` [in]

An input parameter that designates the size of the *pvIn* parameter, in bytes. This parameter is currently not used and its value is zero.

### `pvIn` [in, optional]

A parameter that consists of data that is sent to the printer interface DLL from the MXDC. This parameter is currently not used and its value is **NULL**.

### `cbPrintPropertiesCollection` [in]

The size of the [PrintPropertiesCollection](https://learn.microsoft.com/windows-hardware/drivers/print/xps-driver-document-events) data structure, in bytes.

### `pPrintPropertiesCollection`

The **PrintPropertiesCollection** data structure from which the printer interface's DLL gets the requested data. This structure is defined in WinSpool.h. The requested fields might be pre-filled with the MXDC's default data. The printer interface DLL must ignore the fields that it does not understand.

## Return value

**MxdcGetPDEVAdjustment** should return one of the following values:

| Return code | Description |
|---|---|
| S_OK | The printer interface DLL successfully returned an adjusted imageable area, compression type, or DPI based on the given DEVMODE structure. The MXDC will validate the returned imageable area and then use it to populate the [GDIINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-gdiinfo) structure to the respective fields. |
| E_NOTIMPL | The **MxdcGetPDEVAdjustment** function is not implemented by the printer interface. The printer interface must not modify the fields that it does not support. The MXDC defaults to its current defaults. For the imageable area case, MXDC defaults to using the physical page size. For the compression option, MXDC defaults to medium JPEG compression. |
| E_FAIL | For this value or any other failure values, the MXDC returns -1 to the [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev) function, catches the internal exception, and sets a flag to fail and end the print job. |

## Remarks

The **MxdcGetPDEVAdjustment** function is implemented by the hardware vendor. The MXDC calls this function to obtain printer configuration data in the form of a property bag that includes the following data:

MXDC enables the printer interface DLL to adjust DPI through the **MxdcGetPDEVAdjustment** function only if the print job's **dmPrintQuality** field has a value that is less than or equal to 0. If the DPI value is not adjusted, MXDC maps negative **dmPrintQuality** values to the following resolutions.

| GDI name (Wingdi.h) | GDI value(Wingdi.h) | MXDC default interpretation(dots per inch) |
|---|---|
| DMRES_HIGH | -4 | 2400 |
| DMRES_MEDIUM | -3 | 1200 |
| DMRES_LOW | -2 | 600 |
| DMRES_DRAFT | -1 | 400 |

The name of the MXDC property that stores the MXDC default DPI value is L"MxdcDotsPerInch".

The following table lists the MXDC's property types and property-bag fields for the properties:

| Property (propertyName) | Property type (ePropertyValue) | Property-bag fields |
|---|---|---|
| L"MxdcImageableArea" | kPropertyTypeBuffer | PrintPropertiesCollection::propertiesCollection\[i\].propertyValue.value.propertyBlob.cbBuf = sizeof(RECT) PrintPropertiesCollection::propertiesCollection\[i\].propertyValue.value.propertyBlob.pBuf |
| L"MxdcImageCompressionType" | kPropertyTypeInt32 | PrintPropertiesCollection::propertiesCollection\[i\].propertyValue.value.propertyInt32 |
| L"MxdcDotsPerInch" | kPropertyTypeInt32 | PrintPropertiesCollection::propertiesCollection\[i\].propertyValue.value.propertyInt32 |
| L"MxdcLandscapeRotation" | kPropertyTypeInt32 | PrintPropertiesCollection::propertiesCollection\[i\].propertyValue.value.propertyInt32 |

The following table lists the MXDC's supported data types and data values for the properties:

| Property (propertyName) | Data types and values |
|---|---|
| L"MxdcImageableArea" | Data Type: RECT<br><br>Values:<br><br>RECT::left (Same as FORM_INFO_1)<br><br>RECT::right (Same as FORM_INFO_1)<br><br>RECT::top (Same as FORM_INFO_1)<br><br>RECT::bottom (Same as FORM_INFO_1) |
| L"MxdcImageCompressionType" | Data Type: LONG<br><br>Values:<br><br>1 = JPEG High Compression<br><br>2 = JPEG Medium Compression<br><br>3 = JPEG Low Compression<br><br>4 = PNG Compression |
| L"MxdcDotsPerInch" | Data Type: LONG<br><br>Values:<br><br>A positive value for Dots Per Inch |
| L"MxdcLandscapeRotation" | Data Type: LONG<br><br>Values:<br><br>90 = MXDC_LANDSCAPE_ROTATE_COUNTERCLOCKWISE_90_DEGREES<br><br>0 = MXDC_LANDSCAPE_ROTATE_NONE<br><br>-90 = MXDC_LANDSCAPE_ROTATE_COUNTERCLOCKWISE_270_DEGREES |

The **MxdcGetPDEVAdjustment** function is not a part of the MXDC. The MXDC calls back to this function in the driver's configuration DLL to obtain data for configuring the printer.

The MXDC expects the imageable area to be expressed in unrotated coordinates (portrait orientation). The MXDC rotates both the page size and the imageable area according to the value of the **dmOrientation** member of the DEVMODE structure pointed to by *pDevMode*. Thus, the hardware vendor's implementation of **MxdcGetPDEVAdjustment** should avoid specifying the imageable area in rotated coordinates (landscape orientation) because this will cause landscape print jobs to print incorrectly.

The default value in the MXDC will be MXDC_LANDSCAPE_ROTATE_COUNTERCLOCKWISE_270_DEGREES, which is its current legacy behavior.

All rotation will be done on the imageable area. If a configuration component (UniDrv/PostScript, XPSDrv Monolithic) does not understand the new property bag values, then it should ignore them as is in the current design.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev)

[GDIINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-gdiinfo)

[IPrintOemUIMXDC Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuimxdc)