# ExtEscape function

## Description

The **ExtEscape** function enables an application to access device capabilities that are not available through GDI.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iEscape` [in]

The escape function to be performed. It can be one of the following or it can be an application-defined escape function.

| Value | Meaning |
| --- | --- |
| **[CHECKJPEGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183421(v=vs.85))** | Checks whether the printer supports a JPEG image. |
| **[CHECKPNGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183424(v=vs.85))** | Checks whether the printer supports a PNG image. |
| **[DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85))** | Draws a white, gray-scale, or black rectangle. |
| **[GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85))** | Gets information on a specified feature setting for a PostScript driver. |
| **[GETTECHNOLOGY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144931(v=vs.85))** | Reports on whether or not the driver is a Postscript driver. |
| **[PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85))** | Allows the application to send data directly to a printer. Supported in compatibility mode and GDI-centric mode. |
| **[POSTSCRIPT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162828(v=vs.85))** | Allows the application to send data directly to a printer. Supported only in compatibility mode. |
| **[POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85))** | Sets a PostScript driver to GDI-centric or PostScript-centric mode. |
| **[POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85))** | Inserts a block of raw data in a PostScript job stream. |
| **[POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85))** | Sends data directly to a PostScript printer driver. Supported in compatibility mode and PostScript-centric mode. |
| **QUERYESCSUPPORT** | Determines whether a particular escape is implemented by the device driver. |
| **[SPCLPASSTHROUGH2](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd145110(v=vs.85))** | Enables applications to include private procedures and other resources at the document level-save context. |

### `cjInput` [in]

The number of bytes of data pointed to by the *lpszInData* parameter.

### `lpInData` [in]

A pointer to the input structure required for the specified escape. See also Remarks.

### `cjOutput` [in]

The number of bytes of data pointed to by the *lpszOutData* parameter.

### `lpOutData` [out]

A pointer to the structure that receives output from this escape. This parameter must not be **NULL** if **ExtEscape** is called as a query function. If no data is to be returned in this structure, set *cbOutput* to 0. See also Remarks.

## Return value

The return value specifies the outcome of the function. It is greater than zero if the function is successful, except for the QUERYESCSUPPORT printer escape, which checks for implementation only. The return value is zero if the escape is not implemented. A return value less than zero indicates an error.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Use this function to pass a driver-defined escape value to a device.

Use the [Escape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-escape) function to pass one of the system-defined escape values to a device, unless the escape is one of the defined escapes in *nEscape*. **ExtEscape** might not work properly with the system-defined escapes. In particular, escapes in which *lpszInData* is a pointer to a structure that contains a member that is a pointer will fail.

Note, that the behavior described in this article is the expected behavior, but it is up to the driver to comply with this model.

The variables referenced by *lpszInData* and *lpszOutData* should not be the same or overlap. If the input and the output buffer size variables overlap, they may not contain the correct values after the call returns. For the best results, *lpszInData* and *lpszOutData* should refer to different variables.

The [CHECKJPEGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183421(v=vs.85)) printer escape function determines whether a printer supports printing a JPEG image.

Before using the [CHECKJPEGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183421(v=vs.85)) printer escape function, call the [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) printer escape function to determine whether the driver supports **CHECKJPEGFORMAT**. For sample code that demonstrates the use of **CHECKJPEGFORMAT**, see [Testing a Printer for JPEG or PNG Support](https://learn.microsoft.com/windows/desktop/gdi/testing-a-printer-for-jpeg-or-png-support).

The [CHECKPNGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183424(v=vs.85)) printer escape function determines whether a printer supports printing a PNG image.

Before using the [CHECKJPEGFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd183421(v=vs.85)) printer escape function, call the [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) printer escape function to determine whether the driver supports **CHECKJPEGFORMAT**. For sample code, see [Testing a Printer for JPEG or PNG Support](https://learn.microsoft.com/windows/desktop/gdi/testing-a-printer-for-jpeg-or-png-support).

The [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) printer escape creates a white, gray scale, or solid black rectangle by using the pattern and rule capabilities of Page Control Language (PCL) on Hewlett-Packard LaserJet or LaserJet-compatible printers. A gray scale is a gray pattern that contains a specific mixture of black and white pixels.

An application should use the [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) escape to determine whether the printer is capable of drawing patterns and rules before using the [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) escape.

* Rules drawn with [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) are not subject to clipping regions in the device context.
* Applications should not try to erase patterns and rules created with [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) by placing opaque objects over them.

If the printer supports white rules, these can be used to erase patterns created by [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)). If the printer does not support white rules, there is no method for erasing these patterns.

If an application cannot use the [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) escape and the device is a printer, it should generally use the [PatBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-patblt) function instead. Note that if **PatBlt** is used to print a black rectangle, the application should use the BLACKNESS raster operator. If the device is a plotter, however, the application should use the [Rectangle](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectangle) function.

The [GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85)) printer escape function retrieves information about a specified feature setting for a PostScript driver.

This escape function is supported only if the PostScript driver is in PostScript-centric mode or in GDI-centric mode. To set the PostScript driver mode, call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) escape function.

To perform this operation, call the **ExtEscape** function with the following parameters.

The [GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85)) printer escape function is valid if called any time after calling the [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) function and before calling the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function.

The [GETTECHNOLOGY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144931(v=vs.85)) printer escape function identifies the type of printer driver.

For non-XPSDrv printers, this escape reports whether the driver is a Postscript driver.

For XPSDrv printers, this escape reports whether the driver is the [Microsoft XPS Document Converter (MXDC)](https://learn.microsoft.com/windows/desktop/printdocs/microsoft-xps-document-converter--mxdc-). If it is, the escape returns the zero-terminated string "http://schemas.microsoft.com/xps/2005/06"

The [PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85)) printer escape function sends data directly to a printer driver. To perform this operation, call the **ExtEscape** function with the following parameters.

The **PASSTHROUGH** printer escape function is supported by PostScript drivers in GDI-centric mode or compatibility mode, but not in PostScript-centric mode. Drivers in PostScript-centric mode can use the [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)) escape function. To set a PostScript driver mode, call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) escape function.

For PASSTHROUGH data sent by EPSPRINTING or PostScript-centric applications, the PostScript driver will not make any modifications. For PASSTHROUGH data sent by other applications, if the PostScript driver is using BCP (Binary Communication Protocol) or TBCP (Tagged Binary Communication Protocol) output protocol, the driver does the appropriate BCP or TBCP quoting on special characters, as described in "Adobe Serial and Parallel Communications Protocols Specification." This means that the application should send either ASCII or pure binary PASSTHROUGH data.

The [POSTSCRIPT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162828(v=vs.85)) printer escape function sends data directly to a printer driver. To perform this operation, call the **ExtEscape** function with the following parameters.

The [POSTSCRIPT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162828(v=vs.85)) function is identical to the [PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85)) escape function except that it is supported by PostScript drivers in compatibility mode only. It is not supported by PostScript drivers in PostScript-centric mode or in GDI-centric mode.

Drivers in PostScript-centric mode can use the [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)) escape function, and drivers in GDI-centric mode can use the [PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85)) escape function. To set a PostScript driver's mode, call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) escape function.

The [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) printer escape function sets a PostScript driver to GDI-centric mode or PostScript-centric mode.

To put the driver in GDI-centric or PostScript-centric modes, first call the [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) printer escape function to determine whether the driver supports the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) printer escape function. If so, you can assume the driver is PSCRIPT 5.0. Then, before you call any other printer escape function, you must call **POSTSCRIPT_IDENTIFY** and specify either **PSIDENT_GDICENTRIC** or **PSIDENT_PSCENTRIC**. You must call the **QUERYESCSUPPORT** and **POSTSCRIPT_IDENTIFY** printer escape functions before calling any other printer escape function.

**Note** After the PostScript driver is set to GDI-centric mode or PostScript-centric mode, you will not be allowed to call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) printer escape function anymore.

If you do not use the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) printer escape function, the PostScript driver is in compatibility mode and provides identical support for the [PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85)), [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)), and [POSTSCRIPT_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162828(v=vs.85)) printer escape functions.

For PostScript drivers that support the [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)), [PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162776(v=vs.85)), and **POSTSCRIPT_PASSTHROUGH** printer escape functions are identical.

In PostScript-centric mode, the application is responsible for all PostScript output that marks the paper using the [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)) escape function. GDI functions are not allowed. The driver is responsible for the overall document structure and printer control settings. The application can use the [POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85)) printer escape function to inject a block of raw data (including DSC comments) into the job stream at specific places.

The [POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85)) printer escape function inserts a block of raw data at a specified point in a PostScript job stream.

A PostScript driver supports this escape function in GDI-centric mode or PostScript-centric mode support, but not in compatibility mode.

To set the PostScript driver's mode, call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) escape function.

To perform this operation, call the **ExtEscape** function with the following parameters.

The driver internally caches the injection data and emits it at appropriate points in the output. The cached information is flushed when it is no longer needed. At the latest, it is flushed after the [EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc) call.

In GDI-centric mode, the application can only inject valid DSC block data by using the [POSTSCRIPT_INJECTION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162830(v=vs.85)) printer escape function. A valid DSC block must satisfy all of the following conditions:

* It consists of an integral sequence of "lines."
* Each "line" must begin with "%%".
* Each "line" except the last line must end with \<CR>, \<LF>, or \<CR>\<LF> except for the last line. If the last line does not end with \<CR>, \<LF>, or \<CR>\<LF>, the driver appends \<CR>\<LF> after the last byte of the injection data.
* Each "line" must be 255 bytes or less including the "%%" but not counting the \<CR>/\<LF> line termination.

The [POSTSCRIPT_PASSTHROUGH](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162831(v=vs.85)) printer escape function sends data directly to a PostScript printer driver.

A PostScript driver supports this escape function when in PostScript-centric mode or in compatibility mode, but not in GDI-centric mode.

To set the PostScript driver's mode, call the [POSTSCRIPT_IDENTIFY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162829(v=vs.85)) escape function.

The [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) printer escape function checks the implementation of a printer escape function.

The [SPCLPASSTHROUGH2](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd145110(v=vs.85)) printer escape function allows applications that print to PostScript devices using EPSPRINTING to include private PostScript procedures and other resources at the document-level save context.

This escape is supported only for backward compatibility with Adobe Acrobat. Other applications should not use this obsolete escape.

The application must call this escape before calling [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) so that the driver will cache the data for insertion at the correct point in the PostScript stream. If this escape is supported, the driver will also allow escape **DOWNLOADFACE** calls prior to **StartDoc**. The driver internally caches the data to be inserted and the data required by any escape **DOWNLOADFACE** calls prior to **StartDoc** and emits them all immediately before %%EndProlog. The sequence of [SPCLPASSTHROUGH2](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd145110(v=vs.85)) and **DOWNLOADFACE** calls will be preserved in the order their data is passed in, that is, a later call results in data output after an earlier call's data. The driver will consider fonts downloaded by pre-**StartDoc** escape **DOWNLOADFACE** calls as unavailable for removal during the scope of the job.

This escape is not recorded in EMF files by the operating system, therefore applications must ensure that EMF recording is turned off for those jobs using the escape.

#### Examples

For an example, see [Sizing a JPEG or PNG Image](https://learn.microsoft.com/windows/desktop/gdi/sizing-a-jpeg-or-png-image).

## See also

[Escape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-escape)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)