# PrjStartVirtualizing function

## Description

Configures a ProjFS virtualization instance and starts it, making it available to service I/O and invoke callbacks on the provider.

## Parameters

### `virtualizationRootPath` [in]

Pointer to a null-terminated unicode string specifying the full path to the virtualization root directory.

The provider must have called [PrjMarkDirectoryAsPlaceholder](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjmarkdirectoryasplaceholder) passing the specified path as the rootPathName parameter and NULL as the targetPathName parameter before calling this routine. This only needs to be done once to designate the path as the virtualization root directory

### `callbacks` [in]

Pointer to a [PRJ_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_callbacks) structure that has been filled in with pointers to the provider's callback functions.

### `instanceContext` [in, optional]

Pointer to context information defined by the provider for each instance. This parameter is optional and can be NULL. If it is specified, ProjFS will return it in the InstanceContext member of [PRJ_CALLBACK_DATA](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_callback_data) when invoking provider callback routines.

### `options` [in, optional]

An optional pointer to a [PRJ_STARTVIRTUALIZING_OPTIONS](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_startvirtualizing_options).

### `namespaceVirtualizationContext` [out]

On success returns an opaque handle to the ProjFS virtualization instance.
The provider passes this value when calling functions that require a PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT as input.

## Return value

The error, HRESULT_FROM_WIN32(ERROR_REPARSE_TAG_MISMATCH), indicates that virtualizationRootPath has not been configured as a virtualization root.