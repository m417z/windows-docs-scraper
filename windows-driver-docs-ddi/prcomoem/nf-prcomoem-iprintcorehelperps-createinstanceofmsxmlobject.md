# IPrintCoreHelperPS::CreateInstanceOfMSXMLObject

## Description

The **IPrintCoreHelperPS::CreateInstanceOfMSXMLObject** method creates an instance of an MSXML object.

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

A pointer to a memory address that receives the address of the interface that is requested in the *riid* parameter. If **IPrintCoreHelperPS::CreateInstanceOfMSXMLObject** successfully returns, **ppv* contains the address of the requested interface. If this method fails, **ppv* contains **NULL**.

## Return value

**IPrintCoreHelperPS::CreateInstanceOfMSXMLObject** should return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | An instance of the specified object class was successfully created. |
| **CLASS_E_NOAGGREGATION** | The specified class cannot be created as part of an aggregate. |
| **E_NOINTERFACE** | The specified class does not implement the requested interface, or the controlling **IUnknown** interface does not expose the requested interface. |
| **REGDB_E_CLASSNOTREG** | A specified class is not registered in the registration database. This value can also indicate that the type of server you requested in the CLSCTX enumeration type is not registered or the values for the server types in the registry are corrupt. |

## Remarks

The plug-in should not directly create an MSXML object by calling CoCreateInstance (described in the Windows SDK documentation). Instead, it should call Pscript to do so. The reason is that under certain conditions in which the printer driver might be used, such as with older operating system versions, the operating system does not need to register the required version of MSXML, which currently is version 6. In such situations, calling CoCreateInstance can fail. However, the core driver ensures that wherever the driver is present, the MSXML parser DLL is also present on the machine, making it possible to create an MSXML object when needed.