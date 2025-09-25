# IWbemClassObject::SpawnInstance

## Description

Use the
**IWbemClassObject::SpawnInstance** method to create a new instance of a class. The current object must be a class definition obtained from Windows Management using
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject),
[IWbemServices::CreateClassEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenum), or
[IWbemServices::CreateClassEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenumasync) Then, use this class definition to create new instances.

A call to
[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) is required to actually write the instance to Windows Management. If you intend to discard the object before calling
**IWbemServices::PutInstance**, simply make a call to **IWbemClassObject::Release**.

Note that spawning an instance from an instance is supported but the returned instance will be empty.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `ppNewInstance` [out]

Cannot be **NULL**. It receives a new instance of the class. The caller must invoke **IWbemClassObject::Release** when the pointer is no longer required. On error, a new object is not returned and the pointer is left unmodified.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject)

[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance)