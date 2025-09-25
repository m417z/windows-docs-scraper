# EventAccessQuery function (evntcons.h)

## Description

Retrieves the permissions for the specified controller or provider.

## Parameters

### `Guid` [in]

GUID that uniquely identifies the provider or session.

### `Buffer` [in, out]

Application-allocated buffer that will contain the security descriptor of the controller or provider.

### `BufferSize` [in, out]

Size of the security descriptor buffer, in bytes. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns ERROR_MORE_DATA and this parameter receives the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns ERROR_SUCCESS if successful.

The function returns the following return code if an error occurs:

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The buffer is too small to receive the security descriptor. Reallocate the buffer using the size returned in *BufferSize*. |

## Remarks

If the GUID does not exist in the registry, ETW returns the default permissions for a provider or controller. For details on specifying the GUID in the registry, see [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol).

For information on accessing the components of the security descriptor, see [Getting Information from an ACL](https://learn.microsoft.com/windows/desktop/SecAuthZ/getting-information-from-an-acl), the [GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl), [GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl), and [GetAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getace) functions, and the [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace) structure.

## See also

[EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol)

[EventAccessRemove](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccessremove)