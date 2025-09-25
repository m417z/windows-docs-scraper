# KsReleaseCachedMdl function

## Description

The **KsReleaseCachedMdl** function is used to release the MDL acquired by the [KsAcquireCachedMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecachedmdl) call.

## Parameters

### `Guid` [in]

The GUID extracted from the **MFSampleExtension_MDLCacheCookie** attribute item of the **IMFSample** passed by the pipeline.

### `MdlAddr` [in]

MDL address retrieved in the [KsAcquireCachedMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecachedmdl) call. This should not be touched after the **KsReleaseCachedMdl** call.

### `ReleaseContext` [in]

The context passed as an output in the [KsAcquireCachedMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecachedmdl) call.

## Return value

Returns **STATUS_SUCCESS** for success conditions.