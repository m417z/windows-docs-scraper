# IPrint::Print

## Description

Prints an object on the specified printer, using the specified job requirements.

## Parameters

### `grfFlags` [in]

A bitfield specifying print options from the **PRINTFLAG** enumeration.

#### PRINTFLAG_MAYBOTHERUSER (1)

#### PRINTFLAG_PROMPTUSER (2)

#### PRINTFLAG_USERMAYCHANGEPRINTER (4)

#### PRINTFLAG_RECOMPOSETODEVICE (8)

#### PRINTFLAG_DONTACTUALLYPRINT (16)

#### PRINTFLAG_FORCEPROPERTIES (32)

#### PRINTFLAG_PRINTTOFILE (64)

### `pptd` [in, out]

A pointer to a [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure that describes the target print device.

### `ppPageSet` [in, out]

A pointer to a [PAGESET](https://learn.microsoft.com/windows/desktop/api/docobj/ns-docobj-pageset) pointer variable that receives a pointer to the structure that indicates which pages are to be printed.

### `pstgmOptions` [in, out]

A pointer to object-specific printing options in a serialized OLE property set. This parameter can be **NULL** on input or return.

### `pcallback` [in]

A pointer to the [IContinueCallback](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-icontinuecallback) interface on the view site, which is to be periodically polled at human-response speeds to determine whether printing should be abandoned. This parameter can be **NULL**.

### `nFirstPage` [in]

The page number of the first page to be printed. This value overrides any value previously passed to [IPrint::SetInitialPageNum](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iprint-setinitialpagenum).

### `pcPagesPrinted` [out]

A pointer to a variable that receives the actual number of pages that were successfully printed.

### `pnLastPage` [out]

A pointer to a variable that receives the page number of the last page that was printed.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **PRINT_E_CANCELED** | The print process was canceled before completion. **pcPagesPrinted* indicates the number of pages that were in fact successfully printed before this error occurred. |
| **PRINT_E_NOSUCHPAGE** | A page specified in ***ppPageSet* or *nFirstPage* does not exist. |

## Remarks

The printer on which the object is to be printed is indicated by the [DVTARGETDEVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-dvtargetdevice) structure pointed to by *pptd*. The [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure in the target device indicates whole-job printer-specific options, such as number of copies, paper size, and print quality. The **DEVMODE** structure may also contain orientation information in the **dmOrientation** member (this is indicated in the **dmFields** member). If present, then this paper orientation should be used; if absent, then natural orientation as determined by the object content is to be used.

Due to the possibility of user input, the parameters *pptd* and *ppPageSet* are both [in,out] structures. In the absence of user interaction (that is, if the PRINTFLAG_PROMPTUSER flag is not set), both the target device and the page set will necessarily be the same for input and output. However, if the user is prompted for print options, then the object returns target device and page-set information appropriate to what the user has actually chosen.

The *pstgmOptions* parameter is also [in,out]. On exit, the object should write to **pstgmOptions* any object-specific information that it would need to reproduce this exact print job. Examples might include whether the user selected "sheet, notes, or both" in a spreadsheet application. The data passed is in the format of a serialized property set. The data is normally useful only when passed back in a subsequent call to the same object. Because a subsequent call may specify different user interaction flags, target device, or other settings, the caller can cause the document to be printed multiple times in the same way in slightly different printing contexts.

## See also

[IPrint](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iprint)