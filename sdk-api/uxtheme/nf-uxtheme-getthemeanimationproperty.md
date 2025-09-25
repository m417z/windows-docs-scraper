# GetThemeAnimationProperty function

## Description

Gets a theme animation property based
on the storyboard id and the target id.

## Parameters

### `hTheme` [in]

An opened theme handle.

### `iStoryboardId` [in]

A predefined storyboard identifier.

### `iTargetId` [in]

A predefined target identifier.

### `eProperty` [in]

The property that is associated with the animation storyboard and target.

### `pvProperty` [out]

The buffer to receive the returned property value.

### `cbSize` [in]

The byte size of a buffer that is pointed by *pvProperty*.

### `pcbSizeOut` [out]

The byte size of the returned
property.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.