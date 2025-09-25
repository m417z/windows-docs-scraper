## Description

A convenience method for acquiring (and registering if necessary) a filtered sub-namespace on an object.

## Parameters

### `modelName`

The name of the model which is being extended with a namespace. For example, "Debugger.Models.Process".

### `subNamespaceModelName`

The name of the model which is being added. For example, "Debugger.Models.Process.Io".

### `accessName`

The name used to access the namespace from the parent object. For example, "Io".

### `metadata`

The metadata store used on the accessor for the namespace, such as the help on "Io" if it is newly created.

### `filter`

A filter method to evaluate the context object in order to determine if the namespace property will be applied to the context object.

### `namespaceModelObject`

The resulting namespace model is placed here.

### `token`

The resulting token is placed here.

## Return value

This method returns an HRESULT indicating the success or failure of the method call.

## Remarks

## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)