# IComponentData::CompareObjects

## Description

The **IComponentData::CompareObjects** method enables a snap-in to compare two data objects acquired through
[QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject). Be aware that the data objects can be acquired from two different instances of
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata).

## Parameters

### `lpDataObjectA` [in]

A pointer to the first data object exposing an
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that is to be compared.

### `lpDataObjectB` [in]

A pointer to the second data object exposing an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that is to be compared.

## Return value

This method can return one of these values.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)