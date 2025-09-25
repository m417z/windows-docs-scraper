# GetThemeTimingFunction function

## Description

Gets a predefined timing function based on
a timing function identifier.

## Parameters

### `hTheme` [in]

An opened theme handle.

### `iTimingFunctionId` [in]

A timing function identifier.

### `pTimingFunction` [out]

A buffer to receive a predefined timing function pointer.

### `cbSize` [in]

The byte size of the buffer pointed by *pTimingFunction*.

### `pcbSizeOut` [out]

The byte size of
the timing function structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.