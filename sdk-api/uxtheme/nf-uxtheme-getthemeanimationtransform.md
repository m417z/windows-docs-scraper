# GetThemeAnimationTransform function

## Description

Gets an animation transform operation
based on storyboard id, target id and transform
index.

## Parameters

### `hTheme` [in]

An opened theme handle.

### `iStoryboardId` [in]

A predefined storyboard identifier.

### `iTargetId` [in]

A predefined target identifier.

### `dwTransformIndex` [in]

The zero-based index of a transform operation.

### `pTransform` [out]

A pointer to a buffer to receive a transform structure.

### `cbSize` [in]

The byte size of the buffer pointed by *pTransform*.

### `pcbSizeOut` [out]

The byte size of a transform operation structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.