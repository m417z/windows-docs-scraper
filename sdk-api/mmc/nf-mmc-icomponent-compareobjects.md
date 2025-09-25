# IComponent::CompareObjects

## Description

The **IComponent::CompareObjects** method enables a snap-in to compare two data objects acquired through
[IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject). Be aware that data objects can be acquired from two different instances of
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent).

## Parameters

### `lpDataObjectA` [in]

A pointer to the first object exposing an IDataObject interface that is to be compared.

### `lpDataObjectB` [in]

A pointer to the second object exposing an IDataObject interface that is to be compared.

## Return value

This method can return one of these values.

## Remarks

The
IDataObject interface is documented in the Platform Software Development Kit (SDK).

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)