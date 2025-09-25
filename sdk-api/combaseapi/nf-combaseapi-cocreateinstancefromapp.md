# CoCreateInstanceFromApp function

## Description

Creates an instance of a specific class on a specific computer from within an app container.

## Parameters

### `Clsid` [in]

The CLSID of the object to be created.

### `punkOuter` [in, optional]

If this parameter non-**NULL**, indicates the instance is being created as part of an aggregate, and *punkOuter* is to be used as the new instance's controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Aggregation is currently not supported cross-process or cross-computer. When instantiating an object out of process, CLASS_E_NOAGGREGATION will be returned if *punkOuter* is non-**NULL**.

### `dwClsCtx` [in]

A value from the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `reserved` [in, optional]

Reserved for future use.

### `dwCount` [in]

The number of structures in *pResults*. This value must be greater than 0.

### `pResults` [in, out]

An array of [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures. Each structure has three members: the identifier for a requested interface (**pIID**), the location to return the interface pointer (**pItf**) and the return value of the call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) (**hr**).

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **REGDB_E_CLASSNOTREG** | A specified class is not registered in the registration database, or the class is not supported in the app container. Also can indicate that the type of server you requested in the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration is not registered or the values for the server types in the registry are corrupt. |
| **CLASS_E_NOAGGREGATION** | This class cannot be created as part of an aggregate. |
| **CO_S_NOTALLINTERFACES** | At least one, but not all of the interfaces requested in the *pResults* array were successfully retrieved. The **hr** member of each of the [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures in *pResults* indicates with S_OK or E_NOINTERFACE whether the specific interface was returned. |
| **E_NOINTERFACE** | None of the interfaces requested in the *pResults* array were successfully retrieved. |

## Remarks

The **CoCreateInstanceFromApp** function is the same as the [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex) function, with the following differences.

* The **CoCreateInstanceFromApp** function reads class registrations only from application contexts, and from the HKLM\SOFTWARE\Classes\CLSID registry hive.
* Only built-in classes that are supported in the app container are supplied. Attempts to activate unsupported classes, including all classes installed by 3rd-party code as well as many Windows classes, result in error code **REGDB_E_CLASSNOTREG**.
* The **CoCreateInstanceFromApp** function is available to Windows Store apps. Desktop applications can call this function, but they have the same restrictions as Windows Store apps.

## See also

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[Fusion (Unmanaged API Reference)](https://learn.microsoft.com/dotnet/framework/unmanaged-api/fusion/)