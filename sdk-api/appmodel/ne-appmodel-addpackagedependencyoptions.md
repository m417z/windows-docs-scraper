## Description

Defines options that can be applied when adding a run-time reference to a framework package by using the [AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency) function.

## Constants

### `AddPackageDependencyOptions_None`

No options are applied.

### `AddPackageDependencyOptions_PrependIfRankCollision`

If multiple packages are present in the package graph with the same rank as the call to [AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency), then the resolved package is added before others of the same rank. For more info, see **AddPackageDependency**.

## Remarks

## See also

[AddPackageDependency](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency)