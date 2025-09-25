# IPrintCoreHelper::CreateInstanceOfMSXMLObject

## Description

The **IPrintCoreHelper::CreateInstanceOfMSXMLObject** method creates an instance of an MSXML 6.0 object by using the correct MSXML DLL.

## Parameters

### `rclsid` [in]

The CLSID that is associated with the data and code that will be used to create the object.

### `pUnkOuter` [in]

A pointer to the aggregate object's **IUnknown** interface (the controlling **IUnknown**). This parameter must be **NULL**, which means that the object is not being created as part of an aggregate.

### `dwClsContext` [in]

The context in which the code that manages the newly created object will run. The only valid values are **NULL** and CLSCTX_INPROC_SERVER, which is a value of the CLSCTX enumeration (described in the Microsoft Windows SDK documentation).

### `riid` [in]

A reference to the identifier of the interface that will be used to communicate with the object.

### `ppv` [out]

A pointer to a variable that receives the address of the interface that is requested in the *riid* parameter. If **IPrintCoreHelper::CreateInstanceOfMSXMLObject** successfully returns, **ppv* contains the address of the requested interface. If this method fails, **ppv* contains **NULL**.

## Return value

**IPrintCoreHelper::CreateInstanceOfMSXMLObject** should return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | An instance of the specified object class was successfully created. |
| **CLASS_E_NOAGGREGATION** | The specified class cannot be created as part of an aggregate. |
| **E_NOINTERFACE** | The specified class does not implement the requested interface, or the controlling **IUnknown** interface does not expose the requested interface. |
| **REGDB_E_CLASSNOTREG** | A specified class is not registered in the registration database. This value can also indicate that the type of server you requested in the CLSCTX enumeration type is not registered or the values for the server types in the registry are corrupt. |

## Remarks

**IPrintCoreHelper::CreateInstanceOfMSXMLObject** enables a plug-in to use MSXML objects safely even when it runs on down-level client machines (that is, client machines that run Windows Server 2003, Windows XP, or Windows 2000).

The parameters in this method map directly to those of the **CoCreateInstance** function (which is described in the Windows SDK documentation). Note that installing a Windows Vista driver on a machine that runs a previous version of Windows does not cause MSXML 6.0 to be installed. The actual DLL is included with the driver-dependent DLLs and is loaded from the driver directory. It is not registered on the system. Plug-ins that use this method should create only MSXML objects.