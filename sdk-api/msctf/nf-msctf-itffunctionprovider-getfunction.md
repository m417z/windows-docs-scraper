# ITfFunctionProvider::GetFunction

## Description

Obtains the specified function object.

## Parameters

### `rguid` [in]

Contains a GUID value that identifies the function group that the requested function belongs to. This value can be GUID_NULL.

### `riid` [in]

Contains an interface identifier that identifies the requested function within the group specified by *rguid*. This value can be specified by the application, text service, or one of the IID_ITfFn* values.

### `ppunk` [out]

Pointer to an **IUnknown** interface pointer that receives the requested function interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The requested function is unsupported. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |