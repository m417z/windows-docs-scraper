# RoGetAgileReference function

## Description

Creates an agile reference for an object specified by the given interface.

## Parameters

### `options` [in]

The registration options.

### `riid` [in]

The interface ID of the object for which an agile reference is being obtained.

### `pUnk` [in]

Pointer to the interface to be encapsulated in an agile reference. It must be the same type as *riid*. It may be a pointer to an in-process object or a pointer to a proxy of an object.

### `ppAgileReference` [out]

The agile reference for the object. Call the [Resolve](https://learn.microsoft.com/windows/desktop/WinRT/iagilereference-resolve) method to localize the object into the apartment in which **Resolve** is called.

## Return value

This function can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The function completed successfully. |
| E_INVALIDARG | The *options* parameter in invalid. |
| E_OUTOFMEMORY | The agile reference couldn't be constructed due to an out-of-memory condition. |
| E_NOINTERFACE | The *pUnk* parameter doesn't support the interface ID specified by the *riid* parameter. |
| CO_E_NOT_SUPPORTED | The object implements the [INoMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-inomarshal) interface. |

## Remarks

Call the **RoGetAgileReference** function on an existing object to request an agile reference to the object. The object may or may not be agile, but the returned [IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference) is agile. The agile reference can be passed to another apartment within the same process, where the original object is retrieved by using the **IAgileReference** interface.

This is conceptually similar to the existing Global Interface Table (GIT). Rather than interacting with the GIT, an [IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference) is obtained and used to retrieve the object directly. Just as the GIT is per-process only, agile references are per-process and can't be marshaled.

The agile reference feature provides a performance improvement over the GIT. The agile reference performs eager marshaling by default, which saves a cross-apartment call in cases where the object is retrieved from the agile reference in an apartment that's different from where the agile reference was created. For additional performance improvement, users of the **RoGetAgileReference** function can use the same interface to create an [IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference) and resolve the original object. This saves an additional [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call to obtain the desired interface from the resolved object.

For example, you have a non-agile object named CDemoExample, which implements the IDemo and IExample interfaces. Call the **RoGetAgileReference** function and pass the object, with IID_IDemo. You get back an [IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference) interface pointer, which is agile, so you can pass it to a different apartment. In the other apartment, call the [Resolve](https://learn.microsoft.com/windows/desktop/WinRT/iagilereference-resolve) method, with IID_IExample. You get back an IExample pointer that you can use within this apartment. This IExample pointer is an IExample proxy that's connected to the original CDemoExample object. The agile reference handles the complexity of operations like manually marshaling to a stream and unmarshaling on the other side of the apartment boundary.

## See also

[AgileReferenceOptions](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-agilereferenceoptions)

[IAgileReference](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iagilereference)