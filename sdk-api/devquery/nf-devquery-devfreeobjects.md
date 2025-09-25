## Description

Frees [DEV_OBJECT](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_object) structures allocated by a call to [DevGetObjects](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devgetobjects) or [DevGetObjectsEx](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devgetobjectsex).

## Parameters

### `cObjectCount` [in]

Supplies the number of objects pointed at by *pObjects*.

### `pObjects` [in]

An array of **DEV_OBJECT** structures to be freed.

## Remarks

## See also