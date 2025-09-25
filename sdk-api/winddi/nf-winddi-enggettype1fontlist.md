# EngGetType1FontList function

## Description

The **EngGetType1FontList** function retrieves a list of PostScript Type 1 fonts that are installed both locally and remotely.

## Parameters

### `hdev` [in]

Handle to the device. This is the GDI handle received by the driver as the *hdev* parameter for [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev).

### `pType1Buffer` [out, optional]

Pointer to an array of [TYPE1_FONT](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-type1_font) structures in which to store the Type 1 font list. This parameter can be **NULL**.

### `cjType1Buffer` [in]

Specifies the size, in bytes, of *pType1Buffer*.

### `pulLocalFonts` [out]

Pointer to a memory location that receives the number of Type 1 fonts on the local system.

### `pulRemoteFonts` [out]

Pointer to a memory location that receives the number of Type 1 fonts on the remote system.

### `pLastModified` [out]

Pointer to a memory location that receives the time stamp corresponding to the last time a Type 1 font was added or removed from the local system.

## Return value

**EngGetType1FontList** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

PostScript printer drivers can call **EngGetType1FontList** to obtain a list of Type 1 fonts available to them. These fonts can then be accessed through the handles returned in the TYPE1_FONT structure.

If *pType1Buffer* is **NULL**, **EngGetType1FontList** returns only the number of local and remote Type 1 fonts, as well as the time stamp corresponding to the last time a Type 1 font was added or removed locally from the system.

## See also

[TYPE1_FONT](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-type1_font)