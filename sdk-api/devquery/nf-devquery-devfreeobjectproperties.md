## Description

Frees [DEVPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty) structures allocated by calls to [DevGetObjectProperties](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devgetobjectproperties) or [DevGetObjectPropertiesEx](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devgetobjectpropertiesex).

## Parameters

### `cPropertyCount` [in]

Supplies the number of elements pointed at by *pProperties*.

### `pProperties` [in]

An array of [DEVPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty) structures to be freed.

## Remarks

## See also