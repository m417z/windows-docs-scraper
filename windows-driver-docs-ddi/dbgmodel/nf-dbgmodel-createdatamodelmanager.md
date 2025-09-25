# CreateDataModelManager function

## Description

The initial call a host performs to create and initialize the data model.

## Parameters

### `debugHost`

A pointer to the host interface of the debugger application which is hosting the data model.

### `manager`

The newly created data model manager will be returned here.

## Return value

This function returns HRESULT.

## Remarks

It is unlikely a client will call this function. Only an application which HOSTS the data model will call this.

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)