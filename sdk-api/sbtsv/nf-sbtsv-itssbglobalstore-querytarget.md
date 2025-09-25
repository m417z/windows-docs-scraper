# ITsSbGlobalStore::QueryTarget

## Description

Retrieves the [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) object for the given parameters.

## Parameters

### `ProviderName` [in]

The name of the resource plug-in provider.

### `TargetName` [in]

The target name.

### `FarmName` [in]

The farm name to which the target belongs. If **NULL**, the first target found is returned.

### `ppTarget` [out]

A pointer to a pointer to a target [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## Remarks

Any changes made to the target object returned by this method do not affect the target object stored
in Remote Desktop Connection Broker (RD Connection Broker). The target object returned is a copy of the target object in RD Connection Broker.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)