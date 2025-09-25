# IModelIterator::QueryInterface

## Description

Retrieves pointers to the supported interfaces on an object. This method calls IUnknown::AddRef on the pointer it returns.

For more information, see [IUnknown::QueryInterface](https://learn.microsoft.com/windows/win32/api/Unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)) and [Introduction to COM](https://learn.microsoft.com/cpp/atl/introduction-to-com).

## Parameters

### `iid`

The interface ID. A pointer to an existing object provided as input.

### `iface`

The returned pointer to the requested COM interface.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

Standard COM method.

## See also

[IModelIterator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodeliterator)