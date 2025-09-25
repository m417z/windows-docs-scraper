# IsThemeBackgroundPartiallyTransparent function

## Description

Retrieves whether the background specified by the visual style has transparent pieces or alpha-blended pieces.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The theme-specified background for a particular *iPartId* and *iStateId* has transparent pieces or alpha-blended pieces. |
| **FALSE** | The theme-specified background for a particular *iPartId* and *iStateId* does not have transparent pieces or alpha-blended pieces. |