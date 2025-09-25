# INetFwProducts::Register

## Description

The **Register** method registers a third-party firewall product.

## Parameters

### `product` [in]

The [INetFwProduct](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproduct) object that defines the product to be registered.

### `registration` [out, retval]

The registration handle. The registration will be removed when this object is released.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_CANNOT_INSTALL** | The product binary has not been signed. |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |

## Remarks

Registrations only last for the lifetime of the Windows Firewall service. Third-party firewalls calling this API should also have a service dependency on the Windows Firewall service (mpssvc) to make sure that the service is not unexpectedly stopped, causing all registrations to be lost.

Registrations are removed when a returned registration object is released by the third-party firewall or when the third-party firewall process exits.

A user mode code module using this API should be linked with the /integritycheck linker flag. This flag sets [IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-image_optional_header32) in the image PE header OptionalHeader.DllCharacteristics field, which enforces a signature check at load time. The code module should be digitally signed, consistent with the Authenticode signing procedure.

## See also

[INetFwProduct](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproduct)

[INetFwProducts](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwproducts)