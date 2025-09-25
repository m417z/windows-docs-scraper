# IServicePool::Initialize

## Description

Initializes an object pool.

## Parameters

### `pPoolConfig` [in]

An object supporting the [IServicePoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicepoolconfig) interface that describes the configuration of the object pool.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_ALREADYINITIALIZED** | [Initialize](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicepool-initialize) has already been called. |

## See also

[IServicePool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicepool)