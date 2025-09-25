# IWbemClassObject::Clone

## Description

The
**IWbemClassObject::Clone** method returns a new object that is a complete clone of the current object. The new object has a COM reference count of 1.

## Parameters

### `ppCopy` [out]

This parameter cannot be **NULL**. It receives the copy of the current object. You must call **IWbemClassObject::Release** on this object when it is no longer required.

A new object is not returned on error.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Use this method to duplicate a class definition, or to duplicate an instance. This can be useful when the original copy of the object is required for backup purposes while a new copy is modified. Likewise, use this method to create many new instances from a single source instance. For example, use
[IWbemClassObject::SpawnInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-spawninstance) to create a single starting instance, and use
**IWbemClassObject::Clone** to produce 100 copies of the instance quickly. Each object can be modified subsequently to take on its particular values.

It is not possible to use this method to convert a class definition into an instance, or convert an instance into a class definition.