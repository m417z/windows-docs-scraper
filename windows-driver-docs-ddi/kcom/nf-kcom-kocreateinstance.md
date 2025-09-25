# KoCreateInstance function

## Description

*This function is intended for internal use only.*

The **KoCreateInstance** function creates an object of the class with the specified CLSID.

## Parameters

### `ClassId` [in]

The CLSID of the object to create an instance of.

### `UnkOuter` [in, optional]

The outer unknown object to pass to the new instance.

### `ClsContext` [in]

The context in which to create the instance. This must be CLSCTX_KERNEL_SERVER.

### `InterfaceId` [in]

Reference to the identifier of the interface that will communicate with the object.

### `Interface` [out]

Address of the pointer variable that receives the new interface pointer specified in *InterfaceId*.

## Return value

Returns STATUS_SUCCESS if the instance was successfully created. Otherwise, it returns an error.