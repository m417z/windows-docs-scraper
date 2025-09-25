# IWbemClassObject::SpawnDerivedClass

## Description

Use the
**IWbemClassObject::SpawnDerivedClass** method to create a newly derived class object from the current object. The current object must be a class definition that becomes the parent class of the spawned object. The returned object becomes a subclass of the current object.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `ppNewClass` [out]

Cannot be **NULL**. This receives the pointer to the new class definition object. The caller must invoke **IWbemClassObject::Release** when the object is no longer required, typically after you have invoked
[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass) to write the class definition. On error, a new object is not returned, and *ppNewClass* is left unmodified.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The new object returned in *ppNewClass* automatically becomes a subclass of the current object. This behavior cannot be overridden. There is no other method by which subclasses (derived classes) can be created.

You cannot create a derived class from a class that is local to your own client process. The parent class (base class) must be created and registered with Windows Management using
[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass), and then retrieved using
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) before this method can be used to create a derived class.

To create a class hierarchy, you must create the initial class with
[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass), retrieve it using
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject), and use the retrieved object to create the newly derived class. Then, this newly derived class must be created using
**IWbemServices::PutClass**. To create other derived classes, you must call
**IWbemServices::GetObject**, then call
**IWbemClassObject::SpawnDerivedClass**, and so on, in a cycle for each new derivation level. You must follow this procedure to prevent version errors and concurrency conflicts. For more information about creating a class with no parent, see
[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject)

[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass)