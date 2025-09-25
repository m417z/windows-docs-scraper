# IDataModelScriptHostContext::GetNamespaceObject

## Description

The GetNamespaceObject method returns an object into which the script provider can place any bridges between the data model and the script. It is here, for instance, that the script provider might place data model method objects ([IModelMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelmethod) interfaces boxed into [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) whose implementation calls into correspondingly named functions in the script.

## Parameters

### `namespaceObject`

A data model object which can be used as the representation of the namespace of the script.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripthostcontext)