# ICEnroll::put_UseExistingKeySet

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **UseExistingKeySet** property sets or retrieves a Boolean value that determines whether the existing keys should be used.

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

 If an existing key set is used, the **UseExistingKeySet** property must be set to true.

The **UseExistingKeySet** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
BOOL     bUEKS;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the UseExistingKeySet value
hr = pEnroll->get_UseExistingKeySet( &bUEKS );
if (FAILED( hr ))
    printf("Failed get_UseExistingKeySet - %x\n", hr );
else
    printf( "UseExistingKeySet: %d\n", bUEKS );

// set the UseExistingKeySet value
hr = pEnroll->put_UseExistingKeySet( TRUE );
if (FAILED( hr ))
    printf("Failed put_UseExistingKeySet - %x\n", hr );
else
    printf( "UseExistingKeySet set to TRUE\n" );
```