# IPortableDeviceServiceManager::GetDeviceServices

## Description

The **GetDeviceServices** method retrieves a list of the services associated with the specified device.

## Parameters

### `pszPnPDeviceID` [in]

The Plug and Play (PnP) identifier of the device.

### `guidServiceCategory` [in]

A reference to a globally unique identifier (GUID) that specifies the category of services to retrieve. If the referenced identifier is [GUID_DEVINTERFACE_WPD_SERVICE](https://learn.microsoft.com/windows/desktop/wpd_sdk/device-interface-guids), this method will retrieve all services supported by the device.

### `pServices` [in, out]

A user-allocated array of pointers to strings. When the method returns, the array contains the retrieved PnP service identifiers.

### `pcServices` [in, out]

The number of elements in the array specified by the *pServices* parameter. This value represents the maximum number of service identifiers that will be retrieved. When the method returns, this parameter contains the number of identifiers actually retrieved.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The array referenced by the *pServices* parameter was too small to contain all of the services. |
| **E_POINTER** | The *pcServices* parameter was **NULL**. |

## Remarks

If this method succeeds, the application should call the [FreePortableDevicePnPIDs](https://learn.microsoft.com/windows/desktop/wpd_sdk/freeportabledevicepnpids) function to free the array referenced by the *pServices* parameter.

An application can retrieve the PnP identifier for a device by calling the [IPortableDeviceManager::GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices) method.

Applications that use Single Threaded Apartments should use **CLSID_PortableDeviceServiceFTM** as this eliminates the overhead of interface pointer marshaling. **CLSID_PortableDeviceService** is still supported for legacy applications.

#### Examples

The following example shows how to retrieve a list of services for all devices.

```cpp

#include "stdafx.h"
#include "atlbase.h"
#include "portabledeviceapi.h"
#include "portabledevice.h"

HRESULT GetServiceName( LPCWSTR    pszPnpServiceID, LPWSTR*    ppszServiceName);
HRESULT EnumerateServicesForDevice(
    IPortableDeviceServiceManager* pPortableDeviceServiceManager,
    LPCWSTR pszPnpDeviceID);

int _tmain(int argc, _TCHAR* argv[])
{
    HRESULT                         hr            = S_OK;
    DWORD                           cPnPDeviceIDs = 0;
    LPWSTR*                         pPnpDeviceIDs = NULL;

    CComPtr<IPortableDeviceManager>        pPortableDeviceManager;
    CComPtr<IPortableDeviceServiceManager> pPortableDeviceServiceManager;

       // Initialize COM for COINIT_MULTITHREADED
    hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

    // CoCreate the IPortableDeviceManager interface to enumerate
    // portable devices and to get information about them.
    if (hr == S_OK)
    {
        hr = CoCreateInstance(CLSID_PortableDeviceManager,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_IPortableDeviceManager,
                              (VOID**) &pPortableDeviceManager);
    }

    if (hr == S_OK)
    {
       // Get the PortableDeviceServiceManager interface
       // by calling QueryInterface from IPortableDeviceManager
        hr = pPortableDeviceManager->QueryInterface
            (IID_IPortableDeviceServiceManager,
            (VOID**) &pPortableDeviceServiceManager);
    }

    // Get the number of devices on the system
    if (hr == S_OK)
    {
        hr = pPortableDeviceManager->GetDevices(NULL, &cPnPDeviceIDs);
    }

    // If we have at least 1 device,
    // continue to query the list of services for each device
    if ((hr == S_OK) && (cPnPDeviceIDs > 0))
    {
      pPnpDeviceIDs = new LPWSTR[cPnPDeviceIDs];
      if (pPnpDeviceIDs != NULL)
      {
        hr = pPortableDeviceManager->GetDevices
            (pPnpDeviceIDs, &cPnPDeviceIDs);
        if (SUCCEEDED(hr))
        {
           for (DWORD dwIndex = 0; dwIndex < cPnPDeviceIDs; dwIndex++)
           {
             hr = EnumerateServicesForDevice
                    (pPortableDeviceServiceManager, pPnpDeviceIDs[dwIndex]);
           }
         }

        // Free all returned PnPDeviceID strings
        FreePortableDevicePnPIDs(pPnpDeviceIDs, cPnPDeviceIDs);

        // Delete the array of LPWSTR pointers
        delete [] pPnpDeviceIDs;
        pPnpDeviceIDs = NULL;
    }
 }

    return 0;
}

HRESULT EnumerateServicesForDevice(
    IPortableDeviceServiceManager* pPortableDeviceServiceManager,
   LPCWSTR pszPnpDeviceID)
{
    HRESULT hr = S_OK;
    DWORD cPnpServiceIDs = 0;
    LPWSTR* pPnpServiceIDs = NULL;

    if (pPortableDeviceServiceManager == NULL)
    {
        return E_POINTER;
    }
    // Get the number of services for the device
    if (hr == S_OK)
    {
        hr = pPortableDeviceServiceManager->GetDeviceServices(
             pszPnpDeviceID,
             GUID_DEVINTERFACE_WPD_SERVICE, NULL, &cPnpServiceIDs);
    }

    // If we have at least 1, continue to gather information about
    // each service and populate the device information array.
    if ((hr == S_OK) && (cPnpServiceIDs > 0))
    {
      pPnpServiceIDs = new LPWSTR[cPnpServiceIDs];
      if (pPnpServiceIDs != NULL)
      {
             // Get a list of all services on the given device.
          // To query a give type of service (e.g. the Contacts Service),
          // a service GUID can be provided here instead of
             // GUID_DEVINTERFACE_WPD_SERVICE which returns all services
          DWORD dwIndex = 0;
          hr = pPortableDeviceServiceManager->GetDeviceServices
              (pszPnpDeviceID, GUID_DEVINTERFACE_WPD_SERVICE,
              pPnpServiceIDs, &cPnpServiceIDs);
          if (SUCCEEDED(hr))
          {
             // For each service found, read the name property
             for (dwIndex = 0; dwIndex < cPnpServiceIDs && SUCCEEDED(hr);
                 dwIndex++)
             {
                       LPWSTR pszServiceName = NULL;
                             hr = GetServiceName(pPnpServiceIDs[dwIndex],
                      &pszServiceName);
                       CoTaskMemFree(pszServiceName);
             }
          }
          FreePortableDevicePnPIDs(pPnpServiceIDs, cPnpServiceIDs);

          // Delete the array of LPWSTR pointers
          delete [] pPnpServiceIDs;
          pPnpServiceIDs = NULL;
     }
      }
}

HRESULT GetServiceName( LPCWSTR    pszPnpServiceID,
                        LPWSTR* ppszServiceName)
{
    HRESULT hr = S_OK;
    LPWSTR pszServiceID = NULL;
    LPWSTR pszServiceObjectID  = NULL;
    CComPtr<IPortableDeviceValues> pClientInfo;
    CComPtr<IPortableDeviceValues> pPropertyValues;
    CComPtr<IPortableDeviceService> pService;
    CComPtr<IPortableDeviceContent2> pContent;
    CComPtr<IPortableDeviceProperties>pProperties;
    CComPtr<IPortableDeviceKeyCollection> pPropertiesToRead;

    hr = CoCreateInstance(CLSID_PortableDeviceServiceFTM,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IPortableDeviceService,
                          (VOID**) &pService);
    if (hr == S_OK)
    {
        // CoCreate an IPortableDeviceValues interface
        // to hold the client information.
        hr = CoCreateInstance(CLSID_PortableDeviceValues,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_IPortableDeviceValues,
                              (VOID**) & pClientInfo);
          if ((hr == S_OK) && (pClientInfo!= NULL))
          {
                hr = pClientInfo->SetStringValue
                   (WPD_CLIENT_NAME, L"Service Sample Application");
                if (hr == S_OK)
                {
                       hr = pClientInfo->SetUnsignedIntegerValue(
                WPD_CLIENT_MAJOR_VERSION, 1);
                }
                if (hr == S_OK)
                {
                       hr = pClientInfo->SetUnsignedIntegerValue(
                WPD_CLIENT_MINOR_VERSION, 0);
                }
                if (hr == S_OK)
                {
                        hr = pClientInfo->SetUnsignedIntegerValue(
                 WPD_CLIENT_REVISION, 0);
                }
                if (hr == S_OK)
                {
                        hr = pClientInfo->SetUnsignedIntegerValue(
                                WPD_CLIENT_SECURITY_QUALITY_OF_SERVICE,
                 SECURITY_IMPERSONATION);
                }
                if (hr == S_OK)
                {
                        // Open a connection to the service
                        hr = pService->Open(pszPnpServiceID,
                 pClientInfo);
                }
                if (hr == S_OK)
                {
                        hr = pService->GetServiceObjectID(&pszServiceID);
                }
                if (hr == S_OK)
                {
                        hr = pService->Content(&pContent);
                }
                if (hr == S_OK)
                {
                       hr = pContent->Properties(&pProperties);
                }
                // Create a IPortableDeviceKeyCollection
                // containing the single PROPERTYKEY
                if (hr == S_OK)
                {
                        hr = CoCreateInstance(CLSID_PortableDeviceKeyCollection,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_IPortableDeviceKeyCollection,
                              (VOID**) &pPropertiesToRead);
                }
                // Add our property key
                if (hr == S_OK)
                {
                       hr = pPropertiesToRead->Add(WPD_OBJECT_NAME);
                }
                if (hr == S_OK)
                {
                        hr = pProperties->GetValues(
                 pszServiceID,
                 pPropertiesToRead, &pPropertyValues);
                }
                if (hr == S_OK)
                {
                         hr = pPropertyValues->GetStringValue(
                  WPD_OBJECT_NAME, ppszServiceName);
                }
             CoTaskMemFree(pszServiceObjectID);
             return hr;
          }
     }
}

```

## See also

[Enumerating Services](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-services)

[IPortableDeviceServiceManager](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemanager)

[Opening a Service](https://learn.microsoft.com/windows/desktop/wpd_sdk/opening-a-service)