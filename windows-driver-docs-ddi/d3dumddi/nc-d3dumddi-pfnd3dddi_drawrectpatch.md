# PFND3DDDI_DRAWRECTPATCH callback function

## Description

The **DrawRectPatch** function draws a new or cached rectangular patch or updates the specification of a previously defined patch.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DRAWRECTPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawrectpatch) structure that describes the rectangular patch to draw.

### `unnamedParam3`

*pInfo* [in]

Optional. A pointer to a D3DDDIRECTPATCH_INFO structure that describes information about the rectangular patch.

### `unnamedParam4`

*pPatch* [in]

Optional. A pointer to a buffer that contains four floating-point values (D3DFLOAT[4]) that provide the segment counts for each of the four edges of the rectangular patch.

## Return value

**DrawRectPatch** returns S_OK or an appropriate error result if the rectangular patch is not successfully drawn.

## Remarks

When the Microsoft Direct3D runtime calls*pPatch* the user-mode display driver's **DrawRectPatch** function, it can optionally supply information in the *pInfo* and parameters. The runtime sets flags in the **Flags** member of the [D3DDDIARG_DRAWRECTPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawrectpatch) structure that is specified by *pData* to indicate if it supplies this optional information.

The runtime supplies a UINT value in the **Handle** member of D3DDDIARG_DRAWRECTPATCH to refer to the patch surface. Whenever the runtime redraws the patch surface, it passes the patch handle value and is not required to re-specify the D3DDDIRECTPATCH_INFO data structure for the patch surface. The user-mode display driver can precompute and cache forward-difference coefficients and any other information. Therefore, subsequent calls to the driver's **DrawRectPatch** function that use the same patch handle value run more efficiently.

The actual value in **Handle** is determined by the application and is not under runtime control. Therefore, the driver must handle any value that can be specified by a UINT.

The special **Handle** value of zero indicates that the patch is dynamic; therefore, the driver cannot precompute or cache information for the patch. A nonzero value for **Handle** indicates that the patch is static (or updated with low frequency); therefore, the driver can precompute and cache information for the patch.

The driver must handle the following scenarios in its **DrawRectPatch** function:

* If the **Handle** member is zero, the patch is dynamic. The driver should neither precompute nor cache information for the patch. In this situation, the runtime passes a pointer to a D3DDDIRECTPATCH_INFO structure in the *pInfo* parameter and sets the RTPATCHFLAG_HASINFO flag in the **Flags** member of the D3DDDIARG_DRAWRECTPATCH structure to indicate the presence of the D3DDDIRECTPATCH_INFO structure at *pInfo*. Optionally, the runtime can also set the RTPATCHFLAG_HASSEGS flag in **Flags** to indicate the presence of the segment information that is specified by the *pPatch* parameter. However, if the runtime does not supply segment information at *pPatch*, the runtime should instead use the D3DRS_PATCHSEGMENTS render state value.
* If a nonzero **Handle** value has not been previously specified in an earlier call to the driver's **DrawRectPatch** function, the runtime draws a new cacheable patch. The driver should allocate memory to store cached data and should add this data to its patch handle table. Because the runtime has not previously drawn this patch, the runtime should set the RTPATCHFLAG_HASINFO flag and pass a pointer to a D3DDDIRECTPATCH_INFO structure in the *pInfo* parameter. The driver must check for the RTPATCHFLAG_HASINFO flag to verify the presence of the patch information. If no patch information is specified, the driver should ignore the **DrawRectPatch** call and should not allocate memory for cached data in its patch handle table. Optionally, the runtime can set the RTPATCHFLAG_HASSEGS flag to indicate the presence of the segment information. However, if the runtime does not supply segment information at *pPatch*, the runtime should instead use the D3DRS_PATCHSEGMENTS render state value.
* If a nonzero **Handle** value has been previously specified in an earlier call to the driver's **DrawRectPatch** function and the RTPATCHFLAG_HASINFO flag is set, the runtime updates the definition for the patch. The runtime passes a pointer to a D3DDDIRECTPATCH_INFO structure in the *pInfo* parameter, and the driver must recompute and recache the patch information. Optionally, the runtime can set the RTPATCHFLAG_HASSEGS flag to indicate the presence of the segment information. However, if the runtime does not supply segment information at *pPatch*, the runtime should instead use the D3DRS_PATCHSEGMENTS render state value.
* If a nonzero **Handle** value has been previously specified in an earlier call to the driver's **DrawRectPatch** function and the RTPATCHFLAG_HASINFO flag is not set, the runtime redraws the patch. The driver should use the cached information to draw the patch. In this situation, the driver ignores the current vertex streams, and the cached information is used instead. However, the runtime can still specify new segment information; therefore, the driver should check for the RTPATCHFLAG_HASSEGS flag and handle specified segment information even if it uses a cached patch.

The driver receives notification to release cached patch information through the D3DRS_DELETERTPATCH render state. The value of this render state is the patch to delete.

## See also

[D3DDDIARG_DRAWRECTPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawrectpatch)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)