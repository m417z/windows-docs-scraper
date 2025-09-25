# IFunctionInstance::OpenPropertyStore

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Opens the property store for the function instance. The property store contains metadata about the function instance, such as its name, icon, installation date, and other information.

## Parameters

### `dwStgAccess` [in]

The access mode to be assigned to the open stream. For this method, the following access modes are supported:

#### STGM_READ

#### STGM_READWRITE

#### STGM_WRITE

### `ppIPropertyStore` [out]

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface pointer.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **STG_E_ACCESSDENIED** | The method could not open a writable property store because the caller has insufficient access or the discovery provider does not allow write access to its property store. |
| **E_INVALIDARG** | The value of *dwStgAccess* is invalid. |
| **E_POINTER** | The *ppIPropertyStore* points to invalid memory. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

Only one property store per function instance can be open at a time. If **OpenPropertyStore** is called twice on the same function instance, both *ppIPropertyStore* pointers would point to the same property store. Furthermore, the access mode (as specified by the *dwStgAccess* parameter) would be determined by the most recent **OpenPropertyStore** call. Applications should call **Release** to close a property store before opening another.

It is possible that **OpenPropertyStore** will return a property store for a device that has been removed. In this case, the property keys in the store will be empty. This situation may occur if the device's [devnode](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-glossary) was deleted but the property store associated with the device's function instance is still accessible. This situation occurs rarely.

## See also

[IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance)