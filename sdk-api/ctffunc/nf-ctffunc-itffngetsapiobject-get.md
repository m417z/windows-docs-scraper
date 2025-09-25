# ITfFnGetSAPIObject::Get

## Description

Obtains a specified SAPI object.

## Parameters

### `sObj` [in]

Contains a [TfSapiObject](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tfsapiobject) value that specifies the SAPI object to obtain.

### `ppunk` [out]

Pointer to an **IUnknown** interface pointer that receives the requested SAPI object. The caller must release this interface when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The requested object cannot be obtained. |
| **E_NOTIMPL** | The requested object is not implemented. |

## See also

[ITfFnGetSAPIObject](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffngetsapiobject)

[TfSapiObject](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tfsapiobject)