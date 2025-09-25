# IPortableDeviceServiceCapabilities::GetInheritedServices

## Description

The **GetInheritedServices** method retrieves the services having the specified inheritance type.

## Parameters

### `dwInheritanceType` [in]

The type of inherited services to retrieve.

### `ppServices` [out]

The [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that receives the list of services. If no inherited services are found, an empty collection is returned.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Currently, device services may only inherit by implementing an abstract service. This is analogous to how a class implements methods of an abstract interface or a virtual class in object-oriented programming. By implementing an abstract service, a device service will support all formats, properties, and method behavior that the abstract service describes. For instance, a **Contacts** service may implement the **Anchor Sync** abstract service, where the device stores markers indicating which contacts were updated since the last synchronization with the PC.

Possible values for the *dwInheritanceType* parameter are those defined in the [WPD_SERVICE_INHERITANCE_TYPES](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-service-inheritance-types2) enumeration. (For Windows 7, only the **WPD_SERVICE_INHERITANCE_IMPLEMENTATION** enumeration constant is supported.)

If the value of the *dwInheritanceType* parameter is **WPD_SERVICE_INHERITANCE_IMPLEMENTATION**, each item in the collection specified by the *ppServices* parameter has variant type **VT_CLSID**.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)