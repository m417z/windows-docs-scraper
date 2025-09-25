# IsCompositionActive function

## Description

Determines whether Desktop Window Manager (DWM) composition effects are available to the theme.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if composition effects are available; otherwise, **FALSE**.

## Remarks

Composition effects are provided through the DWM. This function first determines whether DWM is active, then checks whether it has composition effects enabled.