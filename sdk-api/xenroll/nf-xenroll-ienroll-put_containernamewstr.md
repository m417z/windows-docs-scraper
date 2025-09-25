# IEnroll::put_ContainerNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ContainerNameWStr** property sets or retrieves the name of the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) to use.

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The container specified may be an existing container or a new one. It may only be an existing container if the
[UseExistingKeySet](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_useexistingkeyset) property is set, as long as the key set has not been generated yet. For example, if only an [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) set has been generated for a container, it is still possible to perform a certificate enrollment using the signature key set without setting **UseExistingKeySet**. The *exchange key set* could be used if **UseExistingKeySet** is set beforehand.

By default, a new container is selected each time the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) control is run. This ensures that a new key set is generated. If this property is not explicitly set, a generated GUID is used as the container name.

The **ContainerNameWStr** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)