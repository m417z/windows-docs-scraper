# IWsbApplicationRestoreSupport::OrderComponents

## Description

Specifies the order in which application components are to be restored.

## Parameters

### `cComponents` [in]

The number of components to be restored. The value of this parameter can range from 0 to MAX_COMPONENTS.

### `rgComponentName` [in]

An array of *cComponents* names of components to be restored.

### `rgComponentLogicalPaths` [in]

An array of *cComponents* logical paths of components to be restored.

### `prgComponentName` [out]

An array of *cComponents* names of components to be restored, in the order in which they are to be restored. This parameter receives **NULL** if no specific restore order is required.

### `prgComponentLogicalPath` [out]

An array of *cComponents* logical paths of components to be restored, in the order in which they are to be restored. This parameter receives **NULL** if no specific restore order is required.

## Return value

Returns **S_OK** if successful, or an error value otherwise. Possible return values include the following.

## Remarks

Windows Server Backup calls this method before restoring components for an application.

## See also

[IWsbApplicationRestoreSupport](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationrestoresupport)