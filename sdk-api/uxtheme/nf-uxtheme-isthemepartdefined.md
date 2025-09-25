# IsThemePartDefined function

## Description

Retrieves whether a visual style has defined parameters for the specified part and state.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Currently unused. The value should be 0.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The theme has defined parameters for the specified *iPartId* and *iStateId* |
| **FALSE** | The theme does not have defined parameters for the specified *iPartId* and *iStateId* |