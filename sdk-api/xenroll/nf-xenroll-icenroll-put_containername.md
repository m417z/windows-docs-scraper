# ICEnroll::put_ContainerName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ContainerName** property sets or retrieves the name of the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) to use.

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The container specified may be an existing container or a new one. It may only be an existing container if the
[UseExistingKeySet](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_useexistingkeyset) property is set, as long as the key set has not been generated yet. For example, if only an [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) set has been generated for a container, it is still possible to perform a certificate enrollment using the signature key set without setting **UseExistingKeySet**. The *exchange key set* could be used if **UseExistingKeySet** is set beforehand.

By default, a new container is selected each time the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) control is run. This ensures that a new key set is generated. If this property is not explicitly set, a generated GUID is used as the container name.

The **ContainerName** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
BSTR     bstrContainerName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the container name
hr = pEnroll->get_ContainerName( &bstrContainerName );
if ( FAILED ( hr ) )
    printf("Failed getting ContainerName - %x\n", hr );
else
    printf( "ContainerName: %ws\n", bstrContainerName );
// free BSTR when done
if ( NULL != bstrContainerName )
    SysFreeString( bstrContainerName );

// set the container name
// bstrMyName previously set to a valid name
hr = pEnroll->put_ContainerName( bstrMyName );
if ( FAILED ( hr ) )
    printf("Failed setting ContainerName - %x\n", hr );
else
    printf( "ContainerName was set to %ws\n", bstrMyName );
```