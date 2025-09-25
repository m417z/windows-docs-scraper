# IServicePool::GetObject

## Description

Retrieves an object from the object pool.

The object returned is a COM object that can run under arbitrary threading models and contexts.

## Parameters

### `riid` [in]

A reference to the identifier of the object requested.

### `ppv` [out]

The requested object.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_ACTIVATION_FAILED** | Object activation failed. |
| **CO_E_ACTIVATIONFAILED_TIMEOUT** | Object activation failed due to time-out. |
| **CO_E_NOTINITIALIZED** | The object pool was not initialized. |

## See also

[IServicePool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicepool)