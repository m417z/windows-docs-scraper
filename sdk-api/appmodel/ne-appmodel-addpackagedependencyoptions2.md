## Description

Defines options (version 2) that can be applied when adding a run-time reference to a framework package by using the [AddPackageDependency2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency2) function.

## Constants

### `AddPackageDependencyOptions2_None`

No options are applied.

### `AddPackageDependencyOptions2_PrependIfRankCollision`

If multiple packages are present in the package graph with the same rank as the call to [AddPackageDependency2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency2), then the resolved package is added before others of the same rank. For more info, see **AddPackageDependency2**.

### `AddPackageDependencyOptions2_SpecifiedPackageFamilyOnly`

Adds only the target package's family to the package graph. This provides you a way to more surgically manage your dependencies at runtime.

A Framework package can't declare dependencies in the Framework's manifest (that is, Framework package's dependency list is always a size of 1—`[TheFrameworkPackage]`. **AddPackageDependency2** targeting a Framework package adds only the target to the caller's package graph; a Framework package has declared dependencies. Thus targeting Framework packages avoids the need to restrict dynamic dependencies to the target's package family, but Framework packages can't replace Main packages for dynamic use because there are some things that only a Main package can do (for example, Packaged COM OOP Servers, windows.startupTask, and more). Main packages bring this additional indirect packages issue, and thus the need for the *AddPackageDependencyOptions2_SpecifiedPackageFamilyOnly* option, which narrows the scope of **AddPackageDependency2** to only the directly targeted package family.

## Remarks

## See also

* [AddPackageDependency2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-addpackagedependency2)