# IDataModelManager2::CreateTypedIntrinsicObjectEx

## Description

The CreateTypedIntrinsicObjectEx method is semantically similar to the CreateTypedIntrinsicObject method. The only difference between the two is that this method allows the caller to specify the context in which the intrinsic data is valid. If no context is passed, the data is considered valid in whatever context is inherited from the type argument (how CreateTypedIntrinsicObject behaves). This allows for the creation of typed pointer values in the debug target which require more specific context than can be inherited from the type.

## Parameters

### `context`

The context which should be associated with the newly created object. If this is not specified, the context of the object will inherit from the context of the type argument. The special value USE_CURRENT_HOST_CONTEXT can also be passed indicating that the context should be the current UI context of the debugger.

### `intrinsicData`

A VARIANT containing the value which is going to be boxd inside an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) container. Note that this method does not support VT_UNKNOWN constructs. Anything passed to this method must be expressable as ObjectIntrinsic

### `type`

The native/language type of the value.

### `object`

The newly boxed value (as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelManager2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager2)